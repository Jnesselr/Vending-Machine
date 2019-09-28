#ifndef _COIN_CHANGER_H_
#define _COIN_CHANGER_H_

#include "mdb/MDB.h"
#include "utils.h"

enum class CoinChangerState {
  UNKNOWN,
  RESET,
  SETUP,
  IDLE
};

class CoinChanger {
  public:
    static void loop();

    // Callbacks
    static VoidCallback onJustReset;

  private:
    static void sendPoll();
    static void sendReset();
    static void sendSetup();
    static void sendCoinSetup();
    static void sendTubeStatus();

    static uint8_t pollFailures;
    static CoinChangerState state;
    static bool devicePolled;

    // Setup
    static uint8_t featureLevel;
    static uint16_t countryCode;
    static uint8_t coinScalingFactor;
    static uint8_t decimalPlaces;
    static uint16_t coinTypeRouting;
    static uint8_t coinTypeCredit[16];

    // Tube Status
    static uint16_t tubeFullStatus;
    static uint8_t tubeStatus[16];
};

#endif