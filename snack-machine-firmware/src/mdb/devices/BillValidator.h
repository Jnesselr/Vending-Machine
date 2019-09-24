#ifndef _BILL_VALIDATOR_H_
#define _BILL_VALIDATOR_H_

#include "mdb/MDB.h"

class BillValidator {
  public:
    static void loop();

  private:
    static MDBResult mdbResult;

    static bool devicePolled;
    static bool setup;

    static void sendPoll();
    static void sendSetup();
};

#endif