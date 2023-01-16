#ifdef VENDING_MAIN_BOARD

#include "MDB.h"
#include "utils.h"

MDBResult MDB::mdbResult;

static RingBuffer<64, uint16_t> receiveBuffer(-1);
static RingBuffer<64, uint16_t> transmitBuffer(-1);

void enableSend()
{
  // Enable the UDRI to begin transmit
  UCSR3B |= (1 << UDRIE3);
}

void disableSend()
{
  // Disable UDRI to end transmit
  UCSR3B &= ~(1 << UDRIE3);
}

ISR(USART3_RX_vect)
{
  // Wait for data
  while (!(UCSR3A & (1 << RXC3)))
    ;
  uint8_t state = UCSR3A;
  uint8_t recH = UCSR3B;
  uint8_t recL = UDR3;

  if (state & (1 << UPE3))
    return;

  recH = 0x01 & (recH >> 1);
  uint16_t data = (recH << 8) | recL;

  receiveBuffer.push(data);
}

ISR(USART3_UDRE_vect)
{
  if (!transmitBuffer.isEmpty())
  {
    /* 
    * Wait for empty transmit buffer
    * When UDREn flag is 1 -- buffer is empty and ready to be written
    */
    while (!(UCSR3A & (1 << UDRE3)))
      ;

    uint16_t transmitVal = transmitBuffer.pop();
    /* 
    *  Copy 9-th bit to TXB8n
    *  Clear this bit manually to prevent
    *  If data does not exceed 0x0100, don't do anything
    */
    UCSR3B &= ~(1 << TXB83);
    if (transmitVal & 0x0100)
      UCSR3B |= (1 << TXB83);
    /* Write the rest to UDRn register */
    UDR3 = (uint8_t)transmitVal;

    return;
  }

  ::disableSend();
}

void MDB::setup()
{
  UCSR3A |= (1 << U2X3); // try double speed

  uint16_t baud_setting = (F_CPU / 4 / BAUD_RATE - 1) / 2;

  /* Set Baud Rate */
  UBRR3H = (uint8_t)(baud_setting >> 8);
  UBRR3L = (uint8_t)(baud_setting & 0x00FF);
  /* Enable Receiver and Transmitter */
  UCSR3B |= (1 << RXEN3) | (1 << TXEN3);
  /* Enable Interrupt on Recieve Complete */
  UCSR3B |= (1 << RXCIE3);
  /* Set Frame Format, 9-bit word, no parity, 1 stop-bit */
  UCSR3B |= (1 << UCSZ32);
  UCSR3C |= (1 << UCSZ31) | (1 << UCSZ30);

  sei();
}

MDBResult::MDBResult()
{
  reset();
}

void MDBResult::reset()
{
  memset(data, 0, sizeof(data));
  length = 0;
  timeout = false;
  checksumValid = false;
}

void MDBResult::print(const char type[]) const
{
  if(this->data[0] == MDBResult::ACK) {
    return;
  }

  uint8_t i = 0;
  Serial.print(type);
  Serial.print(" recv ");
  Serial.print("(");
  Serial.print(this->length);
  Serial.print(") ");

  if (this->timeout)
  {
    Serial.println("timeout");
    return;
  }

  while (i < this->length)
  {
    Serial.print(F(" 0x"));
    Serial.print(this->data[i], HEX);
    i++;
  }
  Serial.println();
  Serial.flush();
}

MDBCommand::MDBCommand() : MDBCommand(NULL, 0) {}

MDBCommand::MDBCommand(const uint16_t *data, size_t length)
    : MDBCommand(data, length, NULL) {}

MDBCommand::MDBCommand(const uint16_t* data, size_t length, VoidCallback timeout)
    : MDBCommand(data, length, timeout, NULL) {}

MDBCommand::MDBCommand(
    const uint16_t *data,
    size_t length,
    VoidCallback timeout,
    VoidCallback success)
{
  memset(this->data, 0, sizeof(uint16_t) * DATA_SIZE);
  COPY(data, this->data, length);
  this->length = length;
  this->timeout = timeout;
  this->success = success;
}

MDBCommand::MDBCommand(const MDBCommand &command)
{
  memset(this->data, 0, sizeof(uint16_t) * DATA_SIZE);
  COPY(command.data, this->data, command.length);
  this->length = command.length;
  this->timeout = command.timeout;
  this->success = command.success;
}

void MDBCommand::operator=(const MDBCommand &command) {
  memset(this->data, 0, sizeof(uint16_t) * DATA_SIZE);
  COPY(command.data, this->data, command.length);
  this->length = command.length;
  this->timeout = command.timeout;
  this->success = command.success;
}

void MDBCommand::run()
{
  // TODO Handle retry on checksum failure
  MDB::writeForResult(this->data, this->length);

  if (MDB::mdbResult.timeout)
  {
    if (this->timeout != NULL)
    {
      this->timeout();
    }
  } else if (this->success != NULL)
  {
    this->success();
  }

  MDB::mdbResult.reset();
}

void MDBCommand::print(const char type[]) const
{
    if(this->data[0] == MDBResult::ACK) {
    return;
  }

  uint8_t i = 0;
  Serial.print(type);
  Serial.print(" send ");
  Serial.print("(");
  Serial.print(this->length);
  Serial.print(") ");

  while (i < this->length)
  {
    Serial.print(F(" 0x"));
    Serial.print(this->data[i], HEX);
    i++;
  }
  Serial.println();
  Serial.flush();
}

void MDB::ack()
{
  transmitBuffer.push(0x0);

  ::enableSend();
}

void MDB::write(const uint16_t data[], size_t length)
{
  uint16_t checksum = 0;

  for (uint8_t i = 0; i < length; i++)
  {
    transmitBuffer.push(data[i]);

    checksum = (checksum + data[i]) & 0xFF;
  }

  transmitBuffer.push(checksum);

  ::enableSend();
}

void MDB::writeForResult(const uint16_t data[], size_t length)
{
  mdbResult.reset();

  write(data, length);

  // Read data until we get the checksum byte
  // If we don't get the checksum byte and have had an empty buffer
  // for 20 ms, say that the mdb transaction timed out or had an
  // invalid checksum or something.

  uint8_t i = 0;
  uint16_t checksum = 0;
  while (true)
  {
    if(! receiveBuffer.isEmpty()) {
      uint16_t data = receiveBuffer.pop();

      checksum = (checksum + data) & 0xFF;

      mdbResult.data[i] = data;
      mdbResult.length += 1;
      i++;

      if(data & 0x100) {
        if(checksum == (data & 0xFF)) {
          mdbResult.checksumValid = true;
        }
        return; // Good job, we got it all
      }

      delay(1);
    } else {
      delay(10);
      // If we're still empty after 10 mS, we failed here
      if(receiveBuffer.isEmpty()) {
        mdbResult.timeout = true;
        return;
      }
    }
  }
}

void MDB::copyAtMost16(uint8_t start, uint8_t destination[16])
{
  memset(destination, 0, 16);

  for (uint8_t i = start; i < 18; i++)
  {
    if (i < mdbResult.length)
    {
      destination[i - start] = mdbResult.data[i];
    }
  }
}

#endif