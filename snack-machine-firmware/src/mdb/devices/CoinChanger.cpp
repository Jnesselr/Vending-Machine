#include "mdb/devices/CoinChanger.h"
#include "utils.h"

static const uint16_t CMD_POLL[] = {0x10B};
static const uint16_t CMD_RESET[] = {0x108};
static const uint16_t CMD_SETUP[] = {0x109};
static const uint16_t CMD_COIN_TYPE_SETUP[] = {0x10C, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint16_t CMD_TUBE_STATUS[] = {0x10A};

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

  if(state == CoinChangerState::UNKNOWN) {
    sendReset();
    return;
  }

  if(state == CoinChangerState::RESET) {
    sendSetup();
    return;
  }

  if(state == CoinChangerState::SETUP) {
    sendCoinSetup();
    return;
  }
}

void CoinChanger::sendPoll()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_POLL, LENGTH(CMD_POLL), &mdbResult);

  if (mdbResult.timeout)
  {
    pollFailures++;
    DEBUG("Coin poll timeout");
    devicePolled = false;
    return;
  }

  MDB::ack();

  if(pollFailures > 0) {
    pollFailures = 0;
    state = CoinChangerState::UNKNOWN;
    return;
  }

  devicePolled = true;

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    return;
  }

  uint8_t i = 0;

  while (i < mdbResult.length)
  {
    uint16_t data = mdbResult.data[i];

    if (data & 0x100)
    {
      // Checksum byte
      // TODO NAK/ACK based on correctness
      // Not here though because we'll have already processed everything if it's wrong
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

  //Ack?
}

void CoinChanger::sendReset()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_RESET, LENGTH(CMD_RESET), &mdbResult);

  if (mdbResult.timeout)
  {
    state = CoinChangerState::UNKNOWN;
    return;
  }

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    MDB::ack();
  }
}

void CoinChanger::sendSetup()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);

  if (mdbResult.timeout)
  {
    state = CoinChangerState::UNKNOWN;
    return;
  }
  
  MDB::ack();

  featureLevel = mdbResult.data[0];
  countryCode = BYTE2WORD(mdbResult.data[1], mdbResult.data[2]);
  coinScalingFactor = mdbResult.data[3];
  decimalPlaces = mdbResult.data[4];
  coinTypeRouting = BYTE2WORD(mdbResult.data[5], mdbResult.data[6]);
  MDB::copyAtMost16(mdbResult, 7, coinTypeCredit);

  state = CoinChangerState::SETUP;
}

void CoinChanger::sendCoinSetup() {
  static MDBResult mdbResult;
  
  MDB::writeForResult(CMD_COIN_TYPE_SETUP, LENGTH(CMD_COIN_TYPE_SETUP), &mdbResult);
  
  if (mdbResult.timeout)
  {
    state = CoinChangerState::UNKNOWN;
    return;
  }

  Serial.println("Coin Type setup done");

  state = CoinChangerState::IDLE;
}

void CoinChanger::sendTubeStatus()
{
  static MDBResult mdbResult;
  MDB::writeForResult(CMD_TUBE_STATUS, LENGTH(CMD_TUBE_STATUS), &mdbResult);

  tubeFullStatus = BYTE2WORD(mdbResult.data[0], mdbResult.data[1]);
  MDB::copyAtMost16(mdbResult, 2, tubeStatus);
}

/**
 * I like the idea of doing higher level stuff as opposed to low level.
 * I think it's possible to configure the changer however we want, then have it handle setup
 * automatically when the loop starts. Basically, we'd start at an unknown state, start polling,
 * and go from there. 
 * 
 * Too many poll failures? State is now "disconnected" or something. We can do a callback on that
 * state change.
 * 
 * In summary:
 * - Initial setup before calling the event manager loop
 * - Changes to config calls the appropriate function, if the state is correct (idle?)
 *  - What to do if not idle? Queue the change somehow?
 * - Anything that happens that needs to be known about a level up gets a callback.
 *  - onReset
 *  - onCoinDeposited
 *  - onCoinDispensed
 */