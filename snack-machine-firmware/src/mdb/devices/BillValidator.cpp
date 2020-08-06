#ifdef VENDING_MAIN_BOARD

#include "mdb/devices/BillValidator.h"
#include "utils.h"

static const uint16_t CMD_RESET[] = {0x130};
static const uint16_t CMD_POLL[] = {0x133};
static const uint16_t CMD_SETUP[] = {0x131};
static const uint16_t CMD_BILL_SETUP[] = {0x134, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint16_t CMD_BILL_STACKER[] = {0x136};
static const uint16_t CMD_ACCEPT_BILL[] = {0x135, 0x01};
static const uint16_t CMD_REJECT_BILL[] = {0x135, 0x00};
static const uint16_t CMD_EXPANSION_LEVEL_TWO_IDENTIFICATION[] = {0x137, 0x02};
static const uint16_t CMD_RECYCLER_FEATURE_ENABLE[] = {0x137, 0x01, 0x00, 0x00, 0x00, 0x02};

uint8_t BillValidator::pollFailures = 0;
bool BillValidator::devicePolled = false;
BillValidatorState BillValidator::state = BillValidatorState::UNKNOWN;
BillRecyclerState BillValidator::recyclerState = BillRecyclerState::UNKNOWN;

uint8_t BillValidator::featureLevel;
uint16_t BillValidator::currencyCode;
uint16_t BillValidator::billScalingFactor;
uint8_t BillValidator::decimalPlaces;
uint16_t BillValidator::stackerCapacity;
uint16_t BillValidator::billSecurityLevels;
bool BillValidator::canEscrow;
uint8_t BillValidator::billTypeCredit[16];
uint32_t BillValidator::levelTwoOptionalFeatures;

BillValidatorStateCallback BillValidator::onStateChanged = nullptr;
BillRecyclerStateCallback BillValidator::onRecyclerStateChanged = nullptr;
BillRoutedCallback BillValidator::onBillRouted = nullptr;
VoidCallback BillValidator::onDefectiveMotor = nullptr;
VoidCallback BillValidator::onSensorProblem = nullptr;
VoidCallback BillValidator::onValidatorBusy = nullptr;
VoidCallback BillValidator::onROMChecksumError = nullptr;
VoidCallback BillValidator::onValidatorJammed = nullptr;
VoidCallback BillValidator::onJustReset = nullptr;
VoidCallback BillValidator::onBillRemoved = nullptr;
VoidCallback BillValidator::onCashBoxOutOfPosition = nullptr;
VoidCallback BillValidator::onValidatorDisabled = nullptr;
VoidCallback BillValidator::onInvalidEscrowRequest = nullptr;
VoidCallback BillValidator::onBillRejected = nullptr;
VoidCallback BillValidator::onPossibleCreditedBillRemoval = nullptr;
BillInputWhileDisabledCallback BillValidator::onBillInputWhileDisabled = nullptr;

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

  if(state == BillValidatorState::IDLE) {
    if(featureLevel == 2 && recyclerState == BillRecyclerState::UNKNOWN) {
      updateRecyclerState(BillRecyclerState::MAYBE_CAPABLE);
      return;
    }

    if (recyclerState == BillRecyclerState::MAYBE_CAPABLE) {
      sendLevelTwoOptionIdentification();
      return;
    }

    if(recyclerState == BillRecyclerState::READY_TO_ENABLE) {
      sendRecyclerFeatureEnable();
      return;
    }
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
    updateState(BillValidatorState::UNKNOWN);
    updateRecyclerState(BillRecyclerState::UNKNOWN);
    return;
  }
  devicePolled = true;

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    return;
  }

  mdbResult.print("CASH POLL");

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
      uint8_t billRoutingCode = (data & 0x70) >> 4;
      uint8_t billType = (data & 0xF);
      BillRouting billRouting = BillRouting(billRoutingCode);

      CALLBACK(onBillRouted, billRouting, billType)
    }
    else if (data == 0x01)
    {
      CALLBACK(onDefectiveMotor)
    }
    else if (data == 0x02)
    {
      CALLBACK(onSensorProblem)
    }
    else if (data == 0x03)
    {
      CALLBACK(onValidatorBusy)
    }
    else if (data == 0x04)
    {
      CALLBACK(onROMChecksumError)
    }
    else if (data == 0x05)
    {
      CALLBACK(onValidatorJammed)
    }
    else if (data == 0x06)
    {
      // Validator was Reset
      CALLBACK(onJustReset);
      updateState(BillValidatorState::RESET);
      updateRecyclerState(BillRecyclerState::UNKNOWN);
    }
    else if (data == 0x07)
    {
      CALLBACK(onBillRemoved)
    }
    else if (data == 0x08)
    {
      CALLBACK(onCashBoxOutOfPosition)
    }
    else if (data == 0x09)
    {
      CALLBACK(onValidatorDisabled)
    }
    else if (data == 0x0A)
    {
      CALLBACK(onInvalidEscrowRequest)
    }
    else if (data == 0x0B)
    {
      CALLBACK(onBillRejected)
    }
    else if (data == 0x0C)
    {
      CALLBACK(onPossibleCreditedBillRemoval)
    }
    else if (data & 0x40)
    {
      // Number of attempts to input a bill while validator is disabled
      // & 0x1F
      CALLBACK(onBillInputWhileDisabled, data & 0x1F)
    }
    else if (data == 0x21)
    {
      // TODO Bill Recycler Escrow Request
    }
    else if (data == 0x22)
    {
      // TODO Bill Recycler Dispernser Payout Busy
    }
    else if (data == 0x23)
    {
      // TODO Bill Recycler Dispenser Busy
    }
    else if (data == 0x24)
    {
      // TODO Bill Recycler Defective Dispenser Sensor
    }
    else if (data == 0x26)
    {
      // TODO Bill Recycler Dispensor did not start / motor problem
    }
    else if (data == 0x27)
    {
      // TODO Bill Recycler Dispenser Jam
    }
    else if (data == 0x28)
    {
      // TODO Bill Recycler ROM checksum
    }
    else if (data == 0x29)
    {
      // TODO Bill Recycler Dispenser disabled
    }
    else if (data == 0x2A)
    {
      // TODO Bill Recycler Bill waiting
    }
    else if (data == 0x2F)
    {
      // TODO Bill Recycler Filled key pressed
    }
    i++;
  }
}

void BillValidator::sendReset()
{
  // DEBUG("Sending cash reset")
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
  DEBUG("Sending Cash Setup")
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);
  
  if (mdbResult.timeout)
  {
    DEBUG("Cash Setup timed out")
    updateState(BillValidatorState::UNKNOWN);
    updateRecyclerState(BillRecyclerState::UNKNOWN);
    return;
  }

  MDB::ack();

  // mdbResult.print("CASH SETUP");

  featureLevel = mdbResult.data[0];
  currencyCode = BYTE2WORD(mdbResult.data[1], mdbResult.data[2]);
  billScalingFactor = BYTE2WORD(mdbResult.data[3], mdbResult.data[4]);
  decimalPlaces = mdbResult.data[5];
  stackerCapacity = BYTE2WORD(mdbResult.data[6], mdbResult.data[7]);
  billSecurityLevels = BYTE2WORD(mdbResult.data[8], mdbResult.data[9]);
  canEscrow = mdbResult.data[10] == 0xFF;
  MDB::copyAtMost16(mdbResult, 11, billTypeCredit);

  updateState(BillValidatorState::SETUP);
}

void BillValidator::sendBillSetup()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_BILL_SETUP, LENGTH(CMD_BILL_SETUP), &mdbResult);
  
  if (mdbResult.timeout)
  {
    updateState(BillValidatorState::UNKNOWN);
    updateRecyclerState(BillRecyclerState::UNKNOWN);
    return;
  }

  updateState(BillValidatorState::IDLE);

  return;
}

void BillValidator::sendLevelTwoOptionIdentification() {
  static MDBResult mdbResult;

  MDB::writeForResult(
    CMD_EXPANSION_LEVEL_TWO_IDENTIFICATION,
    LENGTH(CMD_EXPANSION_LEVEL_TWO_IDENTIFICATION),
    &mdbResult
  );

  mdbResult.print("CASH OPTIONS");

  if(mdbResult.timeout) {
    return;
  }

  MDB::ack();

  levelTwoOptionalFeatures = BYTE2DWORD(
    mdbResult.data[29],
    mdbResult.data[30],
    mdbResult.data[31],
    mdbResult.data[32]
  );

  // Bill Recycling supported
  if(levelTwoOptionalFeatures & 0x2) {
    updateRecyclerState(BillRecyclerState::READY_TO_ENABLE);
  } else {
    updateRecyclerState(BillRecyclerState::NOT_CAPABLE);
  }
}

void BillValidator::sendRecyclerFeatureEnable() {
  static MDBResult mdbResult;


  MDB::writeForResult(
    CMD_RECYCLER_FEATURE_ENABLE,
    LENGTH(CMD_RECYCLER_FEATURE_ENABLE),
    &mdbResult
  );

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    updateRecyclerState(BillRecyclerState::IDLE);
    return;
  }
}

void BillValidator::updateState(BillValidatorState newState) {
  BillValidatorState oldState = BillValidator::state;
  BillValidator::state = newState;

  CALLBACK(onStateChanged, oldState, newState)
}

void BillValidator::updateRecyclerState(BillRecyclerState newState) {
  BillRecyclerState oldState = BillValidator::recyclerState;
  BillValidator::recyclerState = newState;

  CALLBACK(onRecyclerStateChanged, oldState, newState)
}

void BillValidator::acceptBill() {
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_ACCEPT_BILL, LENGTH(CMD_ACCEPT_BILL), &mdbResult);
}

void BillValidator::rejectBill() {
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_REJECT_BILL, LENGTH(CMD_REJECT_BILL), &mdbResult);
}

uint16_t BillValidator::billValue(uint8_t billType) {
  if(billType < 0 || billType > 15) {
    return -1;
  }
  
  uint16_t result = billScalingFactor;
  result *= billTypeCredit[billType];

  return result;
}

#endif