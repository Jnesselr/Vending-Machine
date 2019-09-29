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

VoidCallback CoinChanger::onJustReset = NULL;

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
          pollFailures = 0;
          state = CoinChangerState::UNKNOWN;
          return;
        }

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
      i++; // Two byte code
    }
    else if (data & 0x40)
    {
      // Coins Deposited
      uint8_t coinRouting = (data & 0x30) >> 4;
      uint8_t coinType = (data & 0x0F);
      uint8_t coinCount = mdbResult.data[i + 1];

      Serial.print(coinCount);
      Serial.print(" ");

      if (coinType == 0x2)
      {
        Serial.print("quarter");
      }
      if (coinType == 0x0)
      {
        Serial.print("nickel");
      }

      if (coinRouting == 0x0)
      {
        Serial.println(" in cash box");
      }
      if (coinRouting == 0x1)
      {
        Serial.println(" in tubes");
      }
      if (coinRouting == 0x2)
      {
        Serial.println(" unused");
      }
      if (coinRouting == 0x3)
      {
        Serial.println(" rejected");
      }
      i++; // Two byte code
    }
    else if (data & 0x20)
    {
      // Slug
    }
    else if (data == 0x01)
    {
      // Escrow request
    }
    else if (data == 0x02)
    {
      // Changer Payout Busy
    }
    else if (data == 0x03)
    {
      // No Credit
    }
    else if (data == 0x04)
    {
      // Defective Tube Sensor
    }
    else if (data == 0x05)
    {
      // Double Arrival
    }
    else if (data == 0x06)
    {
      // Acceptor Unplugged
    }
    else if (data == 0x07)
    {
      // Tube Jam
    }
    else if (data == 0x08)
    {
      // ROM checksum error
    }
    else if (data == 0x09)
    {
      // Coin Routing error
    }
    else if (data == 0x0A)
    {
      // Changer Busy
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
    }
    else if (data == 0x0D)
    {
      // Possible Credited Coin Removal
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