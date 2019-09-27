#include "mdb/devices/BillValidator.h"
#include "utils.h"

static const uint16_t CMD_RESET[] = {0x130};
static const uint16_t CMD_POLL[] = {0x133};
static const uint16_t CMD_SETUP[] = {0x131};
static const uint16_t CMD_BILL_SETUP[] = {0x134, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint16_t CMD_BILL_STACKER[] = {0x136};
static const uint16_t CMD_ACCEPT_BILL[] = {0x135, 0x1};

uint8_t BillValidator::pollFailures = 0;
bool BillValidator::devicePolled = false;
BillValidatorState BillValidator::state = BillValidatorState::UNKNOWN;

void BillValidator::loop()
{
  sendPoll();

  if (state == BillValidatorState::UNKNOWN)
  {
    sendReset();
    return;
  }

  if (state == BillValidatorState::RESET) {
    sendSetup();
    return;
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
    return;
  }

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
  }

  if (mdbResult.data[0] & 0x80) {
    if(mdbResult.data[0] & 0x10) {
      Serial.println(mdbResult.data[0] & 0xF, HEX);
      acceptBill();
    }
  }
}

void BillValidator::acceptBill()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_ACCEPT_BILL, LENGTH(CMD_ACCEPT_BILL), &mdbResult);
}

void BillValidator::sendReset()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_RESET, LENGTH(CMD_RESET), &mdbResult);

  if (mdbResult.timeout)
  {
    return;
  }

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    MDB::ack();
  }
}

void BillValidator::sendSetup()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);
  
  if (mdbResult.timeout)
  {
    state = BillValidatorState::UNKNOWN;
    return;
  }

  MDB::ack();

  state = BillValidatorState::SETUP;
}

void BillValidator::sendBillSetup()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_BILL_SETUP, LENGTH(CMD_BILL_SETUP), &mdbResult);
  
  if (mdbResult.timeout)
  {
    state = BillValidatorState::UNKNOWN;
    return;
  }

  state = BillValidatorState::IDLE;

  return;
}