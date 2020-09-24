#pragma once

#include "ui/Window.h"

class BootWindow : public Window {
  public:
    void show();
    void loop();

    void setBillValidatorIdle(bool);
    void setCoinChangerIdle(bool);
    void setSiteLinkIdle(bool);
    void setWifiOnline(bool);
    void setMotorsIdle(bool);
  private:
    void drawXAt(uint16_t x, uint16_t y);
    void drawCheckAt(uint16_t x, uint16_t y);
    unsigned long lastChangeMillis = 0;
    bool billValidatorIdle = false;
    bool coinChangerIdle = false;
    bool siteLinkIdle = false;
    bool wifiOnline = false;
    bool motorsIdle = false;

    bool redrawBillValidator = true;
    bool redrawCoinChanger = true;
    bool redrawSiteLink = true;
    bool redrawWifi = true;
    bool redrawMotors = true;

    uint16_t billValidatorY;
    uint16_t coinChangerY;
    uint16_t siteLinkY;
    uint16_t wifiY;
    uint16_t motorsY;
};