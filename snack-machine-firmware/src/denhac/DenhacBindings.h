#pragma once

#include "motors.h"

#include "mdb/devices/BillValidator.h"
#include "mdb/devices/CoinChanger.h"

#include "denhac/SiteLink.h"

class DenhacBindings {
  public:
    static void setup();
  private:
    // RFID
    static void onCardScanned(unsigned long cardCode);

    // Bill Validator
    static void onBillRoutedCallback(BillRouting, uint8_t billType);

    // Coin Changer
    static void onCoinDepositedCallback(CoinRouting routing, uint8_t coinType);
};