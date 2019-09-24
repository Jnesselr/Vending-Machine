#include "MDB.h"

static RingBuffer receiveBuffer;
static RingBuffer transmitBuffer;

void enableSend() {
  // Enable the UDRI to begin transmit
  UCSR2B |= (1 << UDRIE2);
}

void disableSend() {
  // Disable UDRI to end transmit
  UCSR2B &= ~(1 << UDRIE2);
}

ISR(USART2_RX_vect)
{
  // Wait for data
  while ( !(UCSR2A & (1 << RXC2)) );
  uint8_t state = UCSR2A;
  uint8_t recH = UCSR2B;
  uint8_t recL = UDR2;
  
  if ( state & (1 << UPE2) )
      return;
  
  recH = 0x01 & (recH >> 1);
  uint16_t data = (recH << 8) | recL;

  receiveBuffer.push(data);
}

ISR(USART2_UDRE_vect)
{   
  if ( ! transmitBuffer.isEmpty() )
  {
    /* 
    * Wait for empty transmit buffer
    * When UDREn flag is 1 -- buffer is empty and ready to be written
    */
    while ( !(UCSR2A & (1 << UDRE2)) );

    uint16_t transmitVal = transmitBuffer.pop();
    /* 
    *  Copy 9-th bit to TXB8n
    *  Clear this bit manually to prevent
    *  If data does not exceed 0x0100, don't do anything
    */
    UCSR2B &= ~(1 << TXB82);
    if (transmitVal & 0x0100)
        UCSR2B |= (1 << TXB82);
    /* Write the rest to UDRn register */
    UDR2 = (uint8_t)transmitVal;
    
    return;
  }

  ::disableSend();
}

void MDB::setup() {
  UCSR2A |= (1 << U2X2); // try double speed
  
  uint16_t baud_setting = (F_CPU / 4 / BAUD_RATE - 1) / 2;

  /* Set Baud Rate */
  UBRR2H = (uint8_t)(baud_setting >> 8);
  UBRR2L = (uint8_t)(baud_setting &  0x00FF);
  /* Enable Receiver and Transmitter */
  UCSR2B |= (1 << RXEN2) | (1 << TXEN2);
  /* Enable Interrupt on Recieve Complete */
  UCSR2B |= (1 << RXCIE2);
  /* Set Frame Format, 9-bit word, no parity, 1 stop-bit */
  UCSR2B |= (1 << UCSZ22);
  UCSR2C |= (1 << UCSZ21) | (1 << UCSZ20);

  sei();
}

MDBResult::MDBResult() {
  reset();
}

void MDBResult::reset() {
  memset(data, 0, sizeof(data) / sizeof(data[0]));
  length = 0;
  timeout = false;
}

void MDB::ack() {
  transmitBuffer.push(0x0);

  ::enableSend();
}

void MDB::write(const uint16_t data[], size_t length) {
  uint16_t checksum = 0;

  for(uint8_t i=0; i<length; i++) {
    transmitBuffer.push(data[i]);

    checksum += data[i];
  }

  checksum &= 0xFF;

  transmitBuffer.push(checksum);

  ::enableSend();
}

void MDB::writeForResult(const uint16_t data[], size_t length, MDBResult* result) {
  result->reset();

  write(data, length);
  delay(20);

  if(receiveBuffer.isEmpty()) {
    result->timeout = true;
    return;
  }

  uint8_t i = 0;
  while(! receiveBuffer.isEmpty()) {
    result->data[i] = receiveBuffer.pop();
    result->length += 1;

    i++;
  }
}