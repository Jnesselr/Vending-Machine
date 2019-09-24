#include "mdb/devices/CoinChanger.h"
#include "utils.h"

static const uint16_t CMD_POLL[] = { 0x10B };
static const uint16_t CMD_RESET[] = { 0x108 };
static const uint16_t CMD_SETUP[] = { 0x109 };
static const uint16_t CMD_COIN_SETUP[] = { 0x10C, 0xFF, 0xFF, 0xFF, 0xFF };
static const uint16_t CMD_TUBE_STATUS[] = { 0x10A };

CoinChanger::CoinChanger() {
  mdbResult.reset();
}

void CoinChanger::loop() {
  this->sendPoll();

  if(devicePolled && !setup) {
    sendSetup();
  }
}

void CoinChanger::sendPoll() {
  MDB::writeForResult(CMD_POLL, LENGTH(CMD_POLL), &mdbResult);

  if(mdbResult.timeout) {
    pollFailures++;
    devicePolled = false;
  }

  MDB::ack();

  if(mdbResult.data[0] == mdbResult.ACK) {
    devicePolled = true;
    return;
  }

  uint8_t i = 0;

  Serial.print("Recv: ");
  while(i < mdbResult.length) {
    Serial.print(F(" 0x"));
    Serial.print(mdbResult.data[i], HEX);
    i++;
  }
  Serial.println();
  i = 0;

  while(i < mdbResult.length) {
    uint16_t data = mdbResult.data[i];

    if(data & 0x100) {
      // Checksum byte
    } else if(data & 0x80) {
      // Coins Dispensed Manually
      i++; // Two byte code
    } else if(data & 0x40) {
      // Coins Deposited
      uint8_t coinRouting = (data & 0x30) >> 4;
      uint8_t coinType = (data & 0x0F);
      uint8_t coinCount = mdbResult.data[i+1];

      Serial.print(coinCount);
      Serial.print(" ");

      if(coinType == 0x2) {
        Serial.print("quarter");
      }
      if(coinType == 0x0) {
        Serial.print("nickel");
      }

      if(coinRouting == 0x0) {
        Serial.println(" in cash box");
      }
      if(coinRouting == 0x1) {
        Serial.println(" in tubes");
      }
      if(coinRouting == 0x2) {
        Serial.println(" unused");
      }
      if(coinRouting == 0x3) {
        Serial.println(" rejected");
      }
      i++; // Two byte code
    } else if(data & 0x20) {
      // Slug
    } else if(data == 0x01) {
      // Escrow request
    } else if(data == 0x02) {
      // Changer Payout Busy
    } else if(data == 0x03) {
      // No Credit
    } else if(data == 0x04) {
      // Defective Tube Sensor
    } else if(data == 0x05) {
      // Double Arrival
    } else if(data == 0x06) {
      // Acceptor Unplugged
    } else if(data == 0x07) {
      // Tube Jam
    } else if(data == 0x08) {
      // ROM checksum error
    } else if(data == 0x09) {
      // Coin Routing error
    } else if(data == 0x0A) {
      // Changer Busy
    } else if(data == 0x0B) {
      // Changer was Reset
      if(onJustReset != NULL) {
        onJustReset();
      }
    } else if(data == 0x0C) {
      // Coin Jam
    } else if(data == 0x0D) {
      // Possible Credited Coin Removal
    }
    i++;
  }

  //Ack?
}

void CoinChanger::sendReset() {
  MDB::writeForResult(CMD_RESET, LENGTH(CMD_RESET), &mdbResult);

  if(mdbResult.timeout) {
    Serial.println("Reset timed out");
    return;
  }

  if(mdbResult.data[0] == mdbResult.ACK) {
    MDB::ack();
  }
}

void CoinChanger::sendSetup() {
  MDB::writeForResult(CMD_SETUP, LENGTH(CMD_SETUP), &mdbResult);

  featureLevel = mdbResult.data[0];
  countryCode = BYTE2WORD(mdbResult.data[1], mdbResult.data[2]);
  coinScalingFactor = mdbResult.data[3];
  decimalPlaces = mdbResult.data[4];
  coinTypeRouting = BYTE2WORD(mdbResult.data[5], mdbResult.data[6]);
  memset(coinTypeCredit, 0, 16);

  MDB::writeForResult(CMD_COIN_SETUP, LENGTH(CMD_COIN_SETUP), &mdbResult);

  setup = true;
}

void CoinChanger::sendTubeStatus() {
  MDB::writeForResult(CMD_TUBE_STATUS, LENGTH(CMD_TUBE_STATUS), &mdbResult);


}