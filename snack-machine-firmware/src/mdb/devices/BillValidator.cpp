#include "mdb/devices/BillValidator.h"
#include "utils.h"

static const uint16_t CMD_RESET[] = {0x130};
static const uint16_t CMD_POLL[] = {0x133};
static const uint16_t CMD_SETUP[] = {0x131};
static const uint16_t CMD_BILL_SETUP[] = {0x134, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint16_t CMD_BILL_STACKER[] = {0x136};

uint8_t BillValidator::pollFailures = 0;
bool BillValidator::devicePolled = false;
BillValidatorState BillValidator::state = BillValidatorState::UNKNOWN;

void BillValidator::loop()
{
  static MDBResult mdbResult;
  sendPoll();

  if (state == BillValidatorState::UNKNOWN)
  {
    sendReset();
  }

  if (state == BillValidatorState::SETUP)
  {
    sendBillSetup();
    return;
  }
}

void BillValidator::sendPoll()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_POLL, LENGTH(CMD_POLL), &mdbResult);

  if (mdbResult.timeout)
  {
    pollFailures++;
    devicePolled = false;
    Serial.println("Cash Timeout");
    return;
  }
  mdbResult.print((char *)"CASH");

  MDB::ack();

  if(pollFailures > 0) {
    pollFailures = 0;
    state = BillValidatorState::UNKNOWN;
    return;
  }
  devicePolled = true;

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    return;
  }

  if (mdbResult.data[0] == 0x06)
  {
    state = BillValidatorState::RESET;
    sendSetup();
  }
}

void BillValidator::sendReset()
{
  static MDBResult mdbResult;

  Serial.println("Sending cash reset");
  MDB::writeForResult(CMD_RESET, LENGTH(CMD_RESET), &mdbResult);

  if (mdbResult.timeout)
  {
    Serial.println("Reset timed out");
    return;
  }

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    Serial.println("Cash Reset");
    MDB::ack();
  }
}

void BillValidator::sendSetup()
{
  static MDBResult mdbResult;

  Serial.println("Entering setup");
  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);
  mdbResult.print("CASH_SETUP");
  MDB::ack();

  Serial.println("Setup done");
  state = BillValidatorState::SETUP;
}

void BillValidator::sendBillSetup()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_BILL_SETUP, LENGTH(CMD_BILL_SETUP), &mdbResult);
  Serial.println("cash idle");

  state = BillValidatorState::IDLE;

  return;
}