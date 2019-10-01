#ifndef _COIN_CHANGER_H_
#define _COIN_CHANGER_H_

#include "mdb/MDB.h"
#include "utils.h"

enum class CoinChangerState {
  UNKNOWN,
  RESET,
  IDLE
};

enum class CoinRouting {
  CASH_BOX,
  TUBES,
  REJECT
};

typedef void (*CoinDispensedCallback)(uint8_t coinType);
typedef void (*CoinDepositedCallback)(CoinRouting, uint8_t coinType);

class CoinChanger {
  public:
    static void loop();

    static void dispense(uint8_t coinType, uint8_t coinCount);

    // Callbacks
    static CoinDispensedCallback onCoinDispensed;
    static CoinDepositedCallback onCoinDeposited;
    static VoidCallback onEscrowRequest;
    static VoidCallback onChangerPayoutBusy;
    static VoidCallback onNoCredit;
    static VoidCallback onDefectiveTubeSensor;
    static VoidCallback onDoubleArrival;
    static VoidCallback onAcceptorUnplugged;
    static VoidCallback onTubeJam;
    static VoidCallback onROMChecksumError;
    static VoidCallback onCoinRoutingError;
    static VoidCallback onChangerBusy;
    static VoidCallback onJustReset;
    static VoidCallback onCoinJam;
    static VoidCallback onPossibleCreditedCoinRemoval;

    static CoinChangerState state;
  private:
    static RingBuffer<MDBCommand*> commandBuffer;

    static void sendReset();
    static void sendSetup();
    static void sendTubeStatus();
    static void sendPoll();
    static void handlePollData(MDBResult);
    static void sendCoinTypeSetup();

    static void onTimeout(MDBResult mdbResult);

    static uint8_t pollFailures;
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