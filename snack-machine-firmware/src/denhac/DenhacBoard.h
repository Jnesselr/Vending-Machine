#pragma once

#include <Diablo_Serial_4DLib.h>
#include <Eventually.h>
#include <DirectIO.h>

#include "mdb/MDB.h"
#include "mdb/devices/BillValidator.h"
#include "mdb/devices/CoinChanger.h"

#include "hid_rfid.h"

#include "motors.h"

#include "vendingMachine.h"


class DenhacBoard: public VendingMachine {
  public:
    static void setup();
    static void loop();
  private:
    static EvtManager eventManager;

    static OutputPort<PORT_H, 2, 1> displayResetPin;
    static HardwareSerial* displaySerial;
    static Diablo_Serial_4DLib display;

    static EvtTimeListener billValidatorLoop;
    static EvtTimeListener coinChangerLoop;
    static EvtTimeListener rfidLoop;

    static void billAccepted(BillRouting billRouting, uint8_t billType);
    static int dollarsGiven;
    static void printMessage();
};