#include "mdb/devices/BillValidator.h"
#include "utils.h"

static const uint16_t CMD_RESET[] = { 0x130 };
static const uint16_t CMD_POLL[] = { 0x133 };
static const uint16_t CMD_SETUP[] = { 0x131 };
static const uint16_t CMD_BILL_SETUP[] = { 0x134, 0xFF, 0xFF, 0xFF, 0xFF };
static const uint16_t CMD_BILL_STACKER[] = { 0x136 }; 

bool BillValidator::devicePolled = false;
BillValidatorState BillValidator::state = BillValidatorState::UNKNOWN;

void BillValidator::setup() {
  MDB::write(CMD_RESET, LENGTH(CMD_RESET));
}

void BillValidator::loop() {
  sendPoll();
}

void BillValidator::sendPoll() {
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_POLL, LENGTH(CMD_POLL), &mdbResult);

  if(mdbResult.timeout) {
    devicePolled = false;
    state = BillValidatorState::UNKNOWN;
    Serial.println("Cash Timeout");
    return;
  }
  mdbResult.print((char *) "CASH");

  MDB::ack();
  devicePolled = true;

  if(mdbResult.data[0] == mdbResult.ACK) {
    return;
  }

  if(state == BillValidatorState::SETUP) {
    MDB::writeForResult(CMD_BILL_SETUP, LENGTH(CMD_BILL_SETUP), &mdbResult);
    state = BillValidatorState::IDLE;
    Serial.println("cash idle");
    return;
  }

  if(mdbResult.data[0] == 0x06) {
    state = BillValidatorState::RESET;
    sendSetup();
  } else if(mdbResult.data[0] == 0x09 && state == BillValidatorState::SETUP) {
    Serial.println("Sending bill setup");

    MDB::writeForResult(CMD_BILL_SETUP, LENGTH(CMD_BILL_SETUP), &mdbResult);
    state = BillValidatorState::IDLE;
  }
}

void BillValidator::sendSetup() {
  static MDBResult mdbResult;
  
  Serial.println("Entering setup");
  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);
  mdbResult.print("CASH_SETUP");
  MDB::ack();

  Serial.println("Setup done");
  state = BillValidatorState::SETUP;
}