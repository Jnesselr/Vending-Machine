#ifndef _BILL_VALIDATOR_H_
#define _BILL_VALIDATOR_H_

#include "mdb/MDB.h"

enum class BillValidatorState {
  UNKNOWN,
  RESET,
  SETUP,
  IDLE
};

class BillValidator {
  public:
    static void loop();

  private:
    static uint8_t pollFailures;
    static BillValidatorState state;
    static bool devicePolled;

    static void sendPoll();
    static void sendReset();
    static void sendSetup();
    static void sendBillSetup();

    static void acceptBill();

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