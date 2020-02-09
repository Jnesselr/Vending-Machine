#ifndef _BILL_VALIDATOR_H_
#define _BILL_VALIDATOR_H_

#include "mdb/MDB.h"

enum class BillValidatorState {
  UNKNOWN,
  RESET,
  SETUP,
  IDLE
};

enum class BillRouting {
  BILL_STACKED,
  ESCROW_POSITION,
  BILL_RETURNED,
  BILL_TO_RECYCLER,
  DISABLED_BILL_REJECTED,
  BILL_TO_RECYCLER_MANUAL,
  MANUAL_DISPENSE,
  TRANSFERRED_FROM_RECYCLER_TO_CASHBOX
};

typedef void (*BillAcceptedCallback)(BillRouting, uint8_t billType);

class BillValidator {
  public:
    static void loop();

    // Callbacks
    static BillAcceptedCallback onBillAccepted;

    static void acceptBill();

  private:
    static uint8_t pollFailures;
    static BillValidatorState state;
    static bool devicePolled;

    static void sendPoll();
    static void sendReset();
    static void sendSetup();
    static void sendBillSetup();

    // Setup
    static uint8_t featureLevel;
    static uint16_t currencyCode;
    static uint16_t billScalingFactor;
    static uint8_t decimalPlaces;
    static uint16_t stackerCapacity;
    static uint16_t billSecurityLevels;
    static bool canEscrow;
    static uint8_t billTypeCredit[16];
};

#endif