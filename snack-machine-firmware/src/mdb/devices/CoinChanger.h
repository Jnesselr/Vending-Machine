#pragma once

#include "mdb/MDB.h"
#include "utils.h"

enum class CoinChangerState {
  UNKNOWN,
  RESET,
  SETUP_SENT,
  IDLE
};

enum class CoinRouting {
  CASH_BOX,
  TUBES,
  REJECT
};

typedef void (*CoinChangerStateCallback)(CoinChangerState oldState, CoinChangerState newState);
typedef void (*CoinDispensedCallback)(uint8_t coinType);
typedef void (*CoinDepositedCallback)(CoinRouting, uint8_t coinType);

class CoinChanger {
  public:
    static void loop();

    static void dispense(uint32_t amount);
    static void dispense(uint8_t coinType, uint8_t coinCount);
    static uint16_t getValue(uint8_t coinType);

    // Callbacks
    static CoinChangerStateCallback onStateChanged;
    static CoinDispensedCallback onCoinDispensed;
    static CoinDepositedCallback onCoinDeposited;
    static VoidCallback onEscrowRequest;
    static VoidCallback onChangerPayoutBusy;
    static VoidCallback onChangerPayoutStopped;
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
  /**
   * 4 was chosen here as it's the max our dispense command can use with the denhac setup.
   * We can dispense $1 through the bill recycler (which is controlled through this class
   * in this setup) as well as $0.25 coins and $0.05 coins. That means we may issue up to 3
   * commands in a row in the "dispense" loop.
   *
   * We may have also queued a tube status command before, which we do every 5 seconds. We
   * reduce the chances of this interfering with an active dispense by only queuing that
   * function if the buffer is empty, but we still need to make room for it.
  */
    static RingBuffer<4, MDBCommand> commandBuffer;

    static void sendReset();
    static void sendSetup();
    static void sendTubeStatus();
    static void sendPoll();
    static void handlePollData();
    static void sendCoinTypeSetup();

    static void updateState(CoinChangerState newState);

    static void onTimeout();

    static uint8_t pollFailures;
    static bool devicePolled;
    static bool currentlyDispensing;
    static bool needUpdatedTubeStatus;
    static unsigned long lastUpdateTubeStatus;

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