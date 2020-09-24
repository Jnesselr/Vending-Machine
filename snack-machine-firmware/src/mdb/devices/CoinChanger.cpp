#ifdef VENDING_MAIN_BOARD

#include "mdb/devices/CoinChanger.h"
#include "utils.h"

static const uint16_t CMD_POLL[] = {0x10B};
static const uint16_t CMD_RESET[] = {0x108};
static const uint16_t CMD_SETUP[] = {0x109};
static const uint16_t CMD_COIN_TYPE_SETUP[] = {0x10C, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint16_t CMD_TUBE_STATUS[] = {0x10A};
static uint16_t CMD_DISPENSE[] = {0x10D, 0};

MDBCommand emptyMDBCommand;
RingBuffer<8, MDBCommand> CoinChanger::commandBuffer(emptyMDBCommand);

uint8_t CoinChanger::pollFailures;
CoinChangerState CoinChanger::state = CoinChangerState::UNKNOWN;
bool CoinChanger::devicePolled = false;
bool CoinChanger::currentlyDispensing = false;
bool CoinChanger::needUpdatedTubeStatus = false;
unsigned long CoinChanger::lastUpdateTubeStatus = 0;

uint8_t CoinChanger::featureLevel = 0;
uint16_t CoinChanger::countryCode = 0;
uint8_t CoinChanger::coinScalingFactor = 0;
uint8_t CoinChanger::decimalPlaces = 0;
uint16_t CoinChanger::coinTypeRouting = 0;
uint8_t CoinChanger::coinTypeCredit[16];

uint16_t CoinChanger::tubeFullStatus = 0;
uint8_t CoinChanger::tubeStatus[16];

CoinChangerStateCallback CoinChanger::onStateChanged = nullptr;
CoinDispensedCallback CoinChanger::onCoinDispensed = nullptr;
CoinDepositedCallback CoinChanger::onCoinDeposited = nullptr;
VoidCallback CoinChanger::onEscrowRequest = nullptr;
VoidCallback CoinChanger::onChangerPayoutBusy = nullptr;
VoidCallback CoinChanger::onChangerPayoutStopped = nullptr;
VoidCallback CoinChanger::onNoCredit = nullptr;
VoidCallback CoinChanger::onDefectiveTubeSensor = nullptr;
VoidCallback CoinChanger::onDoubleArrival = nullptr;
VoidCallback CoinChanger::onAcceptorUnplugged = nullptr;
VoidCallback CoinChanger::onTubeJam = nullptr;
VoidCallback CoinChanger::onROMChecksumError = nullptr;
VoidCallback CoinChanger::onCoinRoutingError = nullptr;
VoidCallback CoinChanger::onChangerBusy = nullptr;
VoidCallback CoinChanger::onJustReset = nullptr;
VoidCallback CoinChanger::onCoinJam = nullptr;
VoidCallback CoinChanger::onPossibleCreditedCoinRemoval = nullptr;

void CoinChanger::loop()
{
  if (state == CoinChangerState::UNKNOWN)
  {
    DEBUG("Unknown state")
    commandBuffer.clear();
    sendReset();
    return;
  }

  if (state == CoinChangerState::RESET)
  {
    DEBUG("State is reset")
    commandBuffer.clear();
    sendSetup();
    sendCoinTypeSetup();
    updateState(CoinChangerState::SETUP_SENT);
    return;
  }

  sendPoll();

  // Force an update every five seconds
  if(TIME_SINCE(lastUpdateTubeStatus, 5000)) {
    lastUpdateTubeStatus = current_loop_millis;
    needUpdatedTubeStatus = true;
  }

  if(needUpdatedTubeStatus) {
    needUpdatedTubeStatus = false;
    sendTubeStatus();
  }

  if (!commandBuffer.isEmpty())
  {
    DEBUG("Running command")
    MDBCommand command = commandBuffer.pop();
    // command.print("COIN CMD");
    command.run();
    DEBUG("Command run")
  }
}

void CoinChanger::dispense(uint32_t amount) {
  while(amount > 0) {
    uint8_t maxCreditValue = 0;
    uint8_t maxCreditIndex = 0;
    for (uint8_t i = 0; i < 16; i++)
    {
      uint16_t value = coinTypeCredit[i] * coinScalingFactor;
      if(amount >= value &&
        value > maxCreditValue &&
        tubeStatus[i] > 0) {
        maxCreditValue = value;
        maxCreditIndex = i;
      }
    }

    if(maxCreditValue == 0) {
      // No more change left I guess
      // TODO Prevent this from happening?
      return;
    }

    uint8_t maxAvailable = tubeStatus[maxCreditIndex];
    uint8_t needed = amount / maxCreditValue;
    uint8_t toDispense = min(maxAvailable, needed);
    CoinChanger::dispense(maxCreditIndex, toDispense);

    amount -= toDispense * maxCreditValue;
  }
}

void CoinChanger::dispense(uint8_t coinType, uint8_t coinCount) {
  uint8_t coinData = (coinCount & 0xF) << 4 | (coinType & 0xF);
  CMD_DISPENSE[1] = coinData;

  MDBCommand dispenseCommand(
    CMD_DISPENSE, 2,
    onTimeout
  );

  commandBuffer.push(dispenseCommand);
}

uint16_t CoinChanger::getValue(uint8_t coinType) {
  return CoinChanger::coinTypeCredit[coinType] * (uint16_t) coinScalingFactor;
}

void CoinChanger::sendPoll()
{
  // DEBUG("Sending Coin POLL")
  MDBCommand pollCommand(
      CMD_POLL, LENGTH(CMD_POLL),
      onTimeout,
      [](const MDBResult& mdbResult) {
        MDB::ack();
        devicePolled = true;
        pollFailures = 0;

        if (mdbResult.data[0] == mdbResult.ACK)
        {
          if(currentlyDispensing) {
            currentlyDispensing = false;
            needUpdatedTubeStatus = true;
            CALLBACK(onChangerPayoutStopped)
          }
          return;
        }

        CoinChanger::handlePollData(mdbResult);
      });

  pollCommand.run();
  // DEBUG("Failure Count")
  // DEBUG(pollFailures)
}

void CoinChanger::handlePollData(const MDBResult& mdbResult)
{
  mdbResult.print("COIN POLL");
  uint8_t i = 0;

  while (i < mdbResult.length)
  {
    uint16_t data = mdbResult.data[i];

    if (data & 0x100)
    {
      // Checksum byte, we can ignore it
    }
    else if (data & 0x80)
    {
      // Coins Dispensed Manually
      uint8_t numberDispensed = (data & 0x70) >> 4;
      uint8_t coinType = (data & 0xF);
      for (uint8_t i = 0; i < numberDispensed; i++)
      {
        CALLBACK(onCoinDispensed, coinType)
      }

      i++; // Two byte code
      // Second byte is the number of coins in the tube
    }
    else if (data & 0x40)
    {
      // Coins Deposited
      uint8_t coinRoutingCode = (data & 0x30) >> 4;
      uint8_t coinType = (data & 0x0F);
      CoinRouting coinRouting =
          coinRoutingCode == 0x00
              ? CoinRouting::CASH_BOX
              : coinRoutingCode == 0x01
                    ? CoinRouting::TUBES
                    : CoinRouting::REJECT;

      CALLBACK(onCoinDeposited, coinRouting, coinType)

      i++; // Two byte code
      // Second byte is the number of coins in the tube
    }
    else if (data & 0x20)
    {
      // Slug
    }
    else {
    }
    
    if (data == 0x01)
    {
      // Escrow request
      CALLBACK(onEscrowRequest)
    }
    else if (data == 0x02)
    {
      currentlyDispensing = true;
      // Changer Payout Busy
      CALLBACK(onChangerPayoutBusy)
    }
    else if (data == 0x03)
    {
      // No Credit
      CALLBACK(onNoCredit)
    }
    else if (data == 0x04)
    {
      // Defective Tube Sensor
      CALLBACK(onDefectiveTubeSensor)
    }
    else if (data == 0x05)
    {
      // Double Arrival
      CALLBACK(onDoubleArrival)
    }
    else if (data == 0x06)
    {
      // Acceptor Unplugged
      CALLBACK(onAcceptorUnplugged)
    }
    else if (data == 0x07)
    {
      // Tube Jam
      CALLBACK(onTubeJam)
    }
    else if (data == 0x08)
    {
      // ROM checksum error
      CALLBACK(onROMChecksumError)
    }
    else if (data == 0x09)
    {
      // Coin Routing error
      CALLBACK(onCoinRoutingError)
    }
    else if (data == 0x0A)
    {
      // Changer Busy
      CALLBACK(onChangerBusy)
    }
    else if (data == 0x0B)
    {
      DEBUG("Just Reset!")
      // Changer was Reset
      updateState(CoinChangerState::RESET);

      CALLBACK(onJustReset)

      return;
    }
    else if (data == 0x0C)
    {
      // Coin Jam
      CALLBACK(onCoinJam)
    }
    else if (data == 0x0D)
    {
      // Possible Credited Coin Removal
      CALLBACK(onPossibleCreditedCoinRemoval)
    }
    i++;
  }
}

void CoinChanger::sendReset()
{
  DEBUG("Calling Coin reset");
  MDBCommand resetCommand(
      CMD_RESET, LENGTH(CMD_RESET),
      onTimeout,
      [](const MDBResult &mdbResult) {
        DEBUG("On success for coin reset");
        MDB::ack();
      });

  resetCommand.run();
  DEBUG("Reset called")
  updateState(CoinChangerState::RESET);
}

void CoinChanger::sendSetup()
{
  DEBUG("Calling Coin setup");
  MDBCommand setupCommand(
      CMD_SETUP, LENGTH(CMD_SETUP),
      onTimeout,
      [](const MDBResult &mdbResult) {
        MDB::ack();

        // mdbResult.print("COIN SETUP");

        featureLevel = mdbResult.data[0];
        countryCode = BYTE2WORD(mdbResult.data[1], mdbResult.data[2]);
        coinScalingFactor = mdbResult.data[3];
        decimalPlaces = mdbResult.data[4];
        coinTypeRouting = BYTE2WORD(mdbResult.data[5], mdbResult.data[6]);
        MDB::copyAtMost16(mdbResult, 7, coinTypeCredit);
      });

  commandBuffer.push(setupCommand);
}

void CoinChanger::sendCoinTypeSetup()
{
  DEBUG("Calling Coin type setup");
  MDBCommand coinSetupCommand(
      CMD_COIN_TYPE_SETUP, LENGTH(CMD_COIN_TYPE_SETUP),
      onTimeout,
      [](const MDBResult &mdbResult) {
        needUpdatedTubeStatus = true;
        updateState(CoinChangerState::IDLE);
      });

  commandBuffer.push(coinSetupCommand);
}

void CoinChanger::sendTubeStatus()
{
  DEBUG("Calling Coin tube status");
  MDBCommand tubeStatusCommand(
      CMD_TUBE_STATUS, LENGTH(CMD_TUBE_STATUS),
      onTimeout,
      [](const MDBResult& mdbResult) {
        // mdbResult.print("COIN TUBE STATUS");
        tubeFullStatus = BYTE2WORD(mdbResult.data[0], mdbResult.data[1]);
        MDB::copyAtMost16(mdbResult, 2, tubeStatus);

        MDB::ack();
      });

  commandBuffer.push(tubeStatusCommand);
}

void CoinChanger::updateState(CoinChangerState newState) {
  CoinChangerState oldState = CoinChanger::state;
  CoinChanger::state = newState;

  CALLBACK(onStateChanged, oldState, newState)
}

void CoinChanger::onTimeout(const MDBResult &mdbResult)
{
  DEBUG("Coin On timeout");
  DEBUG(pollFailures);
  pollFailures++;
  devicePolled = false;
  DEBUG(pollFailures);


  if (pollFailures > 10)
  {
    pollFailures = 0; // Give it a chance to recover
    DEBUG("Coin Poll failures > 10");
    updateState(CoinChangerState::UNKNOWN);
    return;
  }
}

#endif