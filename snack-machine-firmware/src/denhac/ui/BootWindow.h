#pragma once

#include "ui/Window.h"

class BootWindow : public Window {
  public:
    void draw();
    void loop();

    void setBillValidatorIdle(bool);
    void setCoinChangerIdle(bool);
    void setMotorsIdle(bool);
    void setSiteLinkIdle(bool);
  private:
    unsigned long lastChangeMillis = 0;
    bool billValidatorIdle = false;
    bool coinChangerIdle = false;
    bool motorsIdle = false;
    bool siteLinkIdle = false;

    bool redrawBillValidator = true;
    bool redrawCoinChanger = true;
    bool redrawMotors = true;
    bool redrawSiteLink = true;
};