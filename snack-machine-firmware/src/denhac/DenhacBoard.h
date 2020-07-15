#pragma once

#include "mdb/MDB.h"
// #include "mdb/devices/BillValidator.h"
#include "mdb/devices/CoinChanger.h"

#include "hid_rfid.h"

// #include "motors.h"

// #include "ui/WindowManager.h"

#include "vendingMachine.h"

#include "Looper.h"


class DenhacBoard: public VendingMachine {
  public:
    static void setup();
    static void loop();
  private:
    // static Task billValidatorLoop;
    static Task coinChangerLoop;
    static Task rfidLoop;
    // static Task uiLoop;
};