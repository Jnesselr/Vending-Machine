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
};

#endif