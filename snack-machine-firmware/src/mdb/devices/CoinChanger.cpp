#include "mdb/devices/CoinChanger.h"
#include "utils.h"

static const uint16_t CMD_POLL[] = {0x10B};
static const uint16_t CMD_RESET[] = {0x108};
static const uint16_t CMD_SETUP[] = {0x109};
static const uint16_t CMD_COIN_SETUP[] = {0x10C, 0xFF, 0xFF, 0xFF, 0xFF};
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

ResetCallback CoinChanger::onJustReset = NULL;

void CoinChanger::loop()
{
  sendPoll();
}

void CoinChanger::copyAtMost16(const MDBResult &mdbResult, uint8_t start, uint8_t destination[16]) {
  memset(destination, 0, 16);

  for (uint8_t i = start; i < 18; i++)
  {
    if(i < mdbResult.length) {
      destination[i - start] = mdbResult.data[i];
    }
  }
}

void CoinChanger::sendPoll()
{
  static MDBResult mdbResult;

  MDB::writeForResult(CMD_POLL, LENGTH(CMD_POLL), &mdbResult);

  if (mdbResult.timeout)
  {
    pollFailures++;
    devicePolled = false;
    state = CoinChangerState::UNKNOWN;
    Serial.println("Coin Timeout");
    return;
  }
  mdbResult.print((char *) "COIN");

  MDB::ack();

  if(pollFailures > 0) {
    pollFailures = 0;
    sendReset();
  }

  if(state == CoinChangerState::UNKNOWN) {
    sendReset();
  }

  if(state == CoinChangerState::SETUP) {
    sendCoinSetup();
  }

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    devicePolled = true;
    return;
  }

  uint8_t i = 0;

  while (i < mdbResult.length)
  {
    uint16_t data = mdbResult.data[i];

    if (data & 0x100)
    {
      // Checksum byte
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
      sendSetup();
      return;

      if (onJustReset != NULL)
      {
        onJustReset();
      }
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

  Serial.println("Sending coin reset");
  MDB::writeForResult(CMD_RESET, LENGTH(CMD_RESET), &mdbResult);

  if (mdbResult.timeout)
  {
    Serial.println("Reset timed out");
    return;
  }

  if (mdbResult.data[0] == mdbResult.ACK)
  {
    Serial.println("CoinReset");
    MDB::ack();
  }
}

void CoinChanger::sendSetup()
{
  static MDBResult mdbResult;

  Serial.println("Setting up coin");
  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);
  // TODO Handle timeout/ack

  featureLevel = mdbResult.data[0];
  countryCode = BYTE2WORD(mdbResult.data[1], mdbResult.data[2]);
  coinScalingFactor = mdbResult.data[3];
  decimalPlaces = mdbResult.data[4];
  coinTypeRouting = BYTE2WORD(mdbResult.data[5], mdbResult.data[6]);
  copyAtMost16(mdbResult, 7, coinTypeCredit);
  
  MDB::writeForResult(CMD_COIN_SETUP, LENGTH(CMD_COIN_SETUP), &mdbResult);
  // TODO Handle timeout/ack

  state = CoinChangerState::SETUP;
}

void CoinChanger::sendCoinSetup() {
  static MDBResult mdbResult;
  
  MDB::writeForResult(CMD_COIN_SETUP, LENGTH(CMD_COIN_SETUP), &mdbResult);
  // TODO Handle timeout/ack

  state = CoinChangerState::IDLE;
}

void CoinChanger::sendTubeStatus()
{
  static MDBResult mdbResult;
  MDB::writeForResult(CMD_TUBE_STATUS, LENGTH(CMD_TUBE_STATUS), &mdbResult);

  tubeFullStatus = BYTE2WORD(mdbResult.data[0], mdbResult.data[1]);
  copyAtMost16(mdbResult, 2, tubeStatus);
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