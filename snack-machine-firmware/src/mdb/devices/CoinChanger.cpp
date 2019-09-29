#include "mdb/devices/CoinChanger.h"
#include "utils.h"

static const uint16_t CMD_POLL[] = {0x10B};
static const uint16_t CMD_RESET[] = {0x108};
static const uint16_t CMD_SETUP[] = {0x109};
static const uint16_t CMD_COIN_TYPE_SETUP[] = {0x10C, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint16_t CMD_TUBE_STATUS[] = {0x10A};

RingBuffer<MDBCommand *> CoinChanger::commandBuffer(NULL);

uint8_t CoinChanger::pollFailures = 0;
CoinChangerState CoinChanger::state = CoinChangerState::UNKNOWN;
bool CoinChanger::devicePolled = false;

uint8_t CoinChanger::featureLevel = 0;
uint16_t CoinChanger::countryCode = 0;
uint8_t CoinChanger::coinScalingFactor = 0;
uint8_t CoinChanger::decimalPlaces = 0;
uint16_t CoinChanger::coinTypeRouting = 0;
uint8_t CoinChanger::coinTypeCredit[16];

uint16_t CoinChanger::tubeFullStatus = 0;
uint8_t CoinChanger::tubeStatus[16];

CoinDispensedCallback CoinChanger::onCoinDispensed = NULL;
CoinDepositedCallback CoinChanger::onCoinDeposited = NULL;
VoidCallback CoinChanger::onEscrowRequest = NULL;
VoidCallback CoinChanger::onChangerPayoutBusy = NULL;
VoidCallback CoinChanger::onNoCredit = NULL;
VoidCallback CoinChanger::onDefectiveTubeSensor = NULL;
VoidCallback CoinChanger::onDoubleArrival = NULL;
VoidCallback CoinChanger::onAcceptorUnplugged = NULL;
VoidCallback CoinChanger::onTubeJam = NULL;
VoidCallback CoinChanger::onROMChecksumError = NULL;
VoidCallback CoinChanger::onCoinRoutingError = NULL;
VoidCallback CoinChanger::onChangerBusy = NULL;
VoidCallback CoinChanger::onJustReset = NULL;
VoidCallback CoinChanger::onCoinJam = NULL;
VoidCallback CoinChanger::onPossibleCreditedCoinRemoval = NULL;

void CoinChanger::loop()
{
  sendPoll();

  if (!commandBuffer.isEmpty())
  {
    MDBCommand *command = commandBuffer.pop();
    command->run();
    delete command;
  }

  if (state == CoinChangerState::UNKNOWN)
  {
    commandBuffer.clear();
    sendReset();
    return;
  }

  if (state == CoinChangerState::RESET && commandBuffer.isEmpty())
  {
    commandBuffer.clear();
    sendSetup();
    sendCoinTypeSetup();
    return;
  }
}

void CoinChanger::dispense(uint8_t coinType, uint8_t coinCount) {
  uint8_t coinData = (coinCount & 0xF) << 4 | (coinType & 0xF);
  uint16_t* dispenseBuffer = new uint16_t[2] { 0x10D, coinData };

  MDBCommand* dispenseCommand = new MDBCommand(
    dispenseBuffer, 2,
    onTimeout
  );

  delete dispenseBuffer;

  commandBuffer.push(dispenseCommand);
}

void CoinChanger::sendPoll()
{
  MDBCommand pollCommand(
      CMD_POLL, LENGTH(CMD_POLL),
      onTimeout,
      [](MDBResult mdbResult) {
        MDB::ack();
        devicePolled = true;

        if (pollFailures > 25)
        {
          DEBUG("Coin Poll failures > 25");
          state = CoinChangerState::UNKNOWN;
          return;
        }
        
        pollFailures = 0;

        if (mdbResult.data[0] == mdbResult.ACK)
        {
          return;
        }

        CoinChanger::handlePollData(mdbResult);
      });

  pollCommand.run();
}

void CoinChanger::handlePollData(MDBResult mdbResult)
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
        if (onCoinDispensed != NULL)
        {
          onCoinDispensed(coinType);
        }
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

      if(onCoinDeposited != NULL) {
        onCoinDeposited(coinRouting, coinType);
      }

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
      if(onEscrowRequest != NULL) {
        onEscrowRequest();
      }
    }
    else if (data == 0x02)
    {
      // Changer Payout Busy
      if(onChangerPayoutBusy != NULL) {
        onChangerPayoutBusy();
      }
    }
    else if (data == 0x03)
    {
      // No Credit
      if(onNoCredit != NULL) {
        onNoCredit();
      }
    }
    else if (data == 0x04)
    {
      // Defective Tube Sensor
      if(onDefectiveTubeSensor != NULL) {
        onDefectiveTubeSensor();
      }
    }
    else if (data == 0x05)
    {
      // Double Arrival
      if(onDoubleArrival != NULL) {
        onDoubleArrival();
      }
    }
    else if (data == 0x06)
    {
      // Acceptor Unplugged
      if(onAcceptorUnplugged != NULL) {
        onAcceptorUnplugged();
      }
    }
    else if (data == 0x07)
    {
      // Tube Jam
      if(onTubeJam != NULL) {
        onTubeJam();
      }
    }
    else if (data == 0x08)
    {
      // ROM checksum error
      if(onROMChecksumError != NULL) {
        onROMChecksumError();
      }
    }
    else if (data == 0x09)
    {
      // Coin Routing error
      if(onCoinRoutingError != NULL) {
        onCoinRoutingError();
      }
    }
    else if (data == 0x0A)
    {
      // Changer Busy
      if(onChangerBusy != NULL) {
        onChangerBusy();
      }
    }
    else if (data == 0x0B)
    {
      // Changer was Reset
      state = CoinChangerState::RESET;

      if (onJustReset != NULL)
      {
        onJustReset();
      }

      return;
    }
    else if (data == 0x0C)
    {
      // Coin Jam
      if(onCoinJam != NULL) {
        onCoinJam();
      }
    }
    else if (data == 0x0D)
    {
      // Possible Credited Coin Removal
      if(onPossibleCreditedCoinRemoval != NULL) {
        onPossibleCreditedCoinRemoval();
      }
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
      [](MDBResult mdbResult) {
        MDB::ack();
      });

  resetCommand.run();
}

void CoinChanger::sendSetup()
{
  DEBUG("Calling Coin setup");
  MDBCommand *setupCommand = new MDBCommand(
      CMD_SETUP, LENGTH(CMD_SETUP),
      onTimeout,
      [](MDBResult mdbResult) {
        MDB::ack();

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
  MDBCommand *coinSetupCommand = new MDBCommand(
      CMD_COIN_TYPE_SETUP, LENGTH(CMD_COIN_TYPE_SETUP),
      onTimeout,
      [](MDBResult mdbResult) {
        state = CoinChangerState::IDLE;
      });

  commandBuffer.push(coinSetupCommand);
}

void CoinChanger::sendTubeStatus()
{
  DEBUG("Calling Coin tube status");
  MDBCommand *tubeStatusCommand = new MDBCommand(
      CMD_TUBE_STATUS, LENGTH(CMD_TUBE_STATUS),
      onTimeout,
      [](MDBResult mdbResult) {
        tubeFullStatus = BYTE2WORD(mdbResult.data[0], mdbResult.data[1]);
        MDB::copyAtMost16(mdbResult, 2, tubeStatus);

        MDB::ack();
      });

  commandBuffer.push(tubeStatusCommand);
}

void CoinChanger::onTimeout(MDBResult mdbResult)
{
  DEBUG("Coin On timeout");
  pollFailures++;
  devicePolled = false;
}