#include "mdb/devices/BillValidator.h"
#include "utils.h"

static const uint16_t CMD_POLL[] = { 0x133 };
static const uint16_t CMD_SETUP[] = { 0x109 };

bool BillValidator::devicePolled = false;
bool BillValidator::setup = false;
MDBResult BillValidator::mdbResult;

void BillValidator::loop() {
  sendPoll();

  if(devicePolled && !setup) {
    sendSetup();
  }
}

void BillValidator::sendPoll() {
  MDB::writeForResult(CMD_POLL, LENGTH(CMD_POLL), &mdbResult);

  if(mdbResult.timeout) {
    devicePolled = false;
  }

  MDB::ack();
  devicePolled = true;

  if(mdbResult.data[0] == mdbResult.ACK) {
    return;
  }
}

void BillValidator::sendSetup() {
  Serial.println("Called setup");
  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);

  setup = true;
}