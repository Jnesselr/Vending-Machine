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

uint8_t BillValidator::featureLevel;
uint16_t BillValidator::currencyCode;
uint16_t BillValidator::billScalingFactor;
uint8_t BillValidator::decimalPlaces;
uint16_t BillValidator::stackerCapacity;
uint16_t BillValidator::billSecurityLevels;
bool BillValidator::canEscrow;
uint8_t BillValidator::billTypeCredit[16];

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

  mdbResult.print("CASH");

  uint8_t i = 0;

  while(i < mdbResult.length) {
    uint16_t data = mdbResult.data[i];

    if(data & 0x100) {
      // Checksum byte
      // TODO NAK/ACK based on correctness
      // Not here though because we'll have already processed everything if it's wrong
    }
    else if (data & 0x80)
    {
      // Bill inserted
      if(data & 0x10) {
        Serial.println(data & 0xF, HEX);
        acceptBill();
      }
    }
    else if (data == 0x01)
    {
      // Defective Motor
    }
    else if (data == 0x02)
    {
      // Sensor Problem
    }
    else if (data == 0x03)
    {
      // Validator Busy
    }
    else if (data == 0x04)
    {
      // ROM Checksum Error
    }
    else if (data == 0x05)
    {
      // Validator Jammed
    }
    else if (data == 0x06)
    {
      // Validator was Reset
      state = BillValidatorState::RESET;
    }
    else if (data == 0x07)
    {
      // Bill Removed
    }
    else if (data == 0x08)
    {
      // Cash Box out of Position
    }
    else if (data == 0x09)
    {
      // Validator Disabled
    }
    else if (data == 0x0A)
    {
      // Invalid Escrow request
    }
    else if (data == 0x0B)
    {
      // Bill Rejected
    }
    else if (data == 0x0C)
    {
      // Possible Credit Bill Removal
    }
    else if (data & 0x40)
    {
      // Number of attempts to input a bill while validator is disabled
      // & 0x1F
    }
    else if (data == 0x21)
    {
      // Bill Recycler Escrow Request
    }
    else if (data == 0x22)
    {
      // Bill Recycler Dispernser Payout Busy
    }
    else if (data == 0x23)
    {
      // Bill Recycler Dispenser Busy
    }
    else if (data == 0x24)
    {
      // Bill Recycler Defective Dispenser Sensor
    }
    else if (data == 0x26)
    {
      // Bill Recycler Dispensor did not start / motor problem
    }
    else if (data == 0x27)
    {
      // Bill Recycler Dispenser Jam
    }
    else if (data == 0x28)
    {
      // Bill Recycler ROM checksum
    }
    else if (data == 0x29)
    {
      // Bill Recycler Dispenser disabled
    }
    else if (data == 0x2A)
    {
      // Bill Recycler Bill waiting
    }
    else if (data == 0x2F)
    {
      // Bill Recycler Filled key pressed
    }
    i++;
  }
}

void BillValidator::acceptBill()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_ACCEPT_BILL, LENGTH(CMD_ACCEPT_BILL), &mdbResult);
}

void BillValidator::sendReset()
{
  DEBUG("Sending cash reset")
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_RESET, LENGTH(CMD_RESET), &mdbResult);

  if (mdbResult.timeout)
  {
    Serial.println("Cash reset timed out");
    return;
  }

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    MDB::ack();
  }
}

void BillValidator::sendSetup()
{
  DEBUG("Sending Cash Setup")
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);
  
  if (mdbResult.timeout)
  {
    DEBUG("Cash Setup timed out")
    state = BillValidatorState::UNKNOWN;
    return;
  }

  MDB::ack();

  mdbResult.print("CASH SETUP");

  featureLevel = mdbResult.data[0];
  currencyCode = BYTE2WORD(mdbResult.data[1], mdbResult.data[2]);
  billScalingFactor = BYTE2WORD(mdbResult.data[3], mdbResult.data[4]);
  decimalPlaces = mdbResult.data[5];
  stackerCapacity = BYTE2WORD(mdbResult.data[6], mdbResult.data[7]);
  billSecurityLevels = BYTE2WORD(mdbResult.data[8], mdbResult.data[9]);
  canEscrow = mdbResult.data[10] == 0xFF;
  MDB::copyAtMost16(mdbResult, 11, billTypeCredit);

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