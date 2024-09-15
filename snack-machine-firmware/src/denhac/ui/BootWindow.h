#pragma once

#include <Diablo_Serial_4DLib.h>

#include "stdint.h"
#include "motors.h"
#include "mdb/devices/BillValidator.h"
#include "mdb/devices/CoinChanger.h"
#include "denhac/SiteLink.h"
#include "denhac/data/BridgeStatus.h"

class BootWindow {
  public:
    static void setup();
    static void loop();
    static void teardown() {};
    static void touch(uint8_t touchMode, uint16_t x, uint16_t y) {};


    static void onCoinChangerStateCallback(CoinChangerState oldState, CoinChangerState newState);
    static void onBillValidatorStateCallback(BillValidatorState oldState, BillValidatorState newState);
    static void onMotorSystemStateChanged(MotorSystemState oldState, MotorSystemState newState);
    static void onSiteLinkStateCallback(SiteLinkState oldState, SiteLinkState newState);
    static void onSiteLinkStatusCallback(uint8_t statusCode);
    static void onMotorAvailability(uint8_t row, uint8_t col, bool available);
  private:
    static void drawXAt(uint16_t x, uint16_t y);
    static void drawCheckAt(uint16_t x, uint16_t y);

    static Diablo_Serial_4DLib* display;

    static unsigned long lastChangeMillis;
    static bool billValidatorIdle;
    static bool coinChangerIdle;
    static bool siteLinkIdle;
    static bool wifiOnline;
    static bool denhacOrgLink;
    static bool motorsIdle;

    static bool redrawBillValidator;
    static bool redrawCoinChanger;
    static bool redrawSiteLink;
    static bool redrawWifi;
    static bool redrawDenhacOrg;
    static bool redrawMotors;

    static uint16_t billValidatorY;
    static uint16_t coinChangerY;
    static uint16_t siteLinkY;
    static uint16_t wifiY;
    static uint16_t denhacOrgY;
    static uint16_t motorsY;

    static uint8_t numStepsCompleted;
    static uint8_t numStepsTotal;
};