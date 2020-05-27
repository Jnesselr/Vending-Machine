#pragma once

#include <Eventually.h>

#include "mdb/MDB.h"
#include "mdb/devices/BillValidator.h"
#include "mdb/devices/CoinChanger.h"

#include "hid_rfid.h"

#include "motors.h"

#include "ui/WindowManager.h"

#include "vendingMachine.h"


class DenhacBoard: public VendingMachine {
  public:
    static void setup();
    static void loop();
  private:
    static EvtManager eventManager;

    static EvtTimeListener billValidatorLoop;
    static EvtTimeListener coinChangerLoop;
    static EvtTimeListener rfidLoop;
    static EvtTimeListener uiLoop;
};