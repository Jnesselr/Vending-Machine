#ifndef _COIN_CHANGER_H_
#define _COIN_CHANGER_H_

#include "mdb/MDB.h"

typedef void (*ResetCallback)();

class CoinChanger {
  public:
    CoinChanger();
    void loop();

    // Callbacks
    ResetCallback onJustReset = NULL;

  private:
    void sendPoll();
    void sendReset();
    void sendSetup();
    void sendTubeStatus();

    MDBResult mdbResult;

    uint8_t pollFailures = 0;
    bool devicePolled = false;
    bool setup = false;

    // Setup
    uint8_t featureLevel = 0;
    uint16_t countryCode = 0;
    uint8_t coinScalingFactor = 0;
    uint8_t decimalPlaces = 0;
    uint16_t coinTypeRouting = 0;
    uint8_t coinTypeCredit[16];

    // Tube Status
    uint16_t tubeFullStatus = 0;
    uint16_t tubeStatus = 0;
};

#endif