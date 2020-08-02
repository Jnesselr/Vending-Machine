#pragma once

#include "mdb/MDB.h"
#include "utils.h"

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
typedef void (*BillRoutedCallback)(BillRouting, uint8_t billType);
typedef void (*BillInputWhileDisabledCallback)(uint8_t numAttempts);

class BillValidator {
  public:
    static void loop();

    // Callbacks
    static BillValidatorStateCallback onStateChanged;
    static BillRecyclerStateCallback onRecyclerStateChanged;
    static BillRoutedCallback onBillRouted;
    static VoidCallback onDefectiveMotor;
    static VoidCallback onSensorProblem;
    static VoidCallback onValidatorBusy;
    static VoidCallback onROMChecksumError;
    static VoidCallback onValidatorJammed;
    static VoidCallback onJustReset;
    static VoidCallback onBillRemoved;
    static VoidCallback onCashBoxOutOfPosition;
    static VoidCallback onValidatorDisabled;
    static VoidCallback onInvalidEscrowRequest;
    static VoidCallback onBillRejected;
    static VoidCallback onPossibleCreditedBillRemoval;
    static BillInputWhileDisabledCallback onBillInputWhileDisabled;

    static void acceptBill();
    static void rejectBill();

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