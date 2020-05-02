#pragma once

#include "mdb/MDB.h"

enum class BillValidatorState {
  UNKNOWN,
  RESET,
  SETUP,
  IDLE
};

enum class BillRecyclerState {
  UNKNOWN,
  NOT_CAPABLE,
  MAYBE_CAPABLE, // Correct feature level, haven't checked the options bits yet
  READY_TO_ENABLE,
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

typedef void (*BillValidatorStateCallback)(BillValidatorState oldState, BillValidatorState newState);
typedef void (*BillRecyclerStateCallback)(BillRecyclerState oldState, BillRecyclerState newState);
typedef void (*BillAcceptedCallback)(BillRouting, uint8_t billType);

class BillValidator {
  public:
    static void loop();

    // Callbacks
    static BillValidatorStateCallback onStateChanged;
    static BillRecyclerStateCallback onRecyclerStateChanged;
    static BillAcceptedCallback onBillAccepted;

    static void acceptBill();
    // TODO static void rejectBill();

    static uint16_t billValue(uint8_t billType);

  private:
    static uint8_t pollFailures;
    static BillValidatorState state;
    static BillRecyclerState recyclerState;
    static bool devicePolled;

    static void sendPoll();
    static void sendReset();
    static void sendSetup();
    static void sendBillSetup();
    static void sendLevelTwoOptionIdentification();
    static void sendRecyclerFeatureEnable();

    static void updateState(BillValidatorState newState);
    static void updateRecyclerState(BillRecyclerState newState);

    // Setup response values
    static uint8_t featureLevel;
    static uint16_t currencyCode;
    static uint16_t billScalingFactor;
    static uint8_t decimalPlaces;
    static uint16_t stackerCapacity;
    static uint16_t billSecurityLevels;
    static bool canEscrow;
    static uint8_t billTypeCredit[16];
    static uint32_t levelTwoOptionalFeatures;
};