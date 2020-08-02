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

    // Motors
    static void onMotorSystemStateChanged(MotorSystemState oldState, MotorSystemState newState);

    // Bill Validator
    static void onBillValidatorStateCallback(BillValidatorState oldState, BillValidatorState newState);

    // Coin Changer
    static void onCoinChangerStateCallback(CoinChangerState oldState, CoinChangerState newState);
    static void onCoinDepositedCallback(CoinRouting routing, uint8_t coinType);

    // SiteLink
    static void onSiteLinkStateCallback(SiteLinkState oldState, SiteLinkState newState);
};