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
    static void setup();
    static void loop();

  private:
    static bool devicePolled;
    static BillValidatorState state;

    static void sendPoll();
    static void sendSetup();
};

#endif