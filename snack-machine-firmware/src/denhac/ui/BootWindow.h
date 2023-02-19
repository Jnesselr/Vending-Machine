#pragma once

#include <Diablo_Serial_4DLib.h>

#include "stdint.h"

class BootWindow {
  public:
    static void setup();
    static void loop();
    static void teardown() {};
    static void touch(uint8_t touchMode, uint16_t x, uint16_t y) {};

    static void setBillValidatorIdle(bool);
    static void setCoinChangerIdle(bool);
    static void setSiteLinkIdle(bool);
    static void setWifiOnline(bool);
    static void setMotorsIdle(bool);
  private:
    static void drawXAt(uint16_t x, uint16_t y);
    static void drawCheckAt(uint16_t x, uint16_t y);

    static Diablo_Serial_4DLib* display;

    static unsigned long lastChangeMillis;
    static bool billValidatorIdle;
    static bool coinChangerIdle;
    static bool siteLinkIdle;
    static bool wifiOnline;
    static bool motorsIdle;

    static bool redrawBillValidator;
    static bool redrawCoinChanger;
    static bool redrawSiteLink;
    static bool redrawWifi;
    static bool redrawMotors;

    static uint16_t billValidatorY;
    static uint16_t coinChangerY;
    static uint16_t siteLinkY;
    static uint16_t wifiY;
    static uint16_t motorsY;
};