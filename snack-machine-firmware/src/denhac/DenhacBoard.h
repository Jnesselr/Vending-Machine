#pragma once

#include "vendingMachine.h"

#include "Looper.h"


class DenhacBoard: public VendingMachine {
  public:
    static void setup();
    static void loop();
  private:
    static Task billValidatorLoop;
    static Task coinChangerLoop;
    static Task rfidLoop;
    static Task uiLoop;

    static void onCardScanned(unsigned long cardCode);
};