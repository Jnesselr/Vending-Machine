#pragma once

#include <stdint.h>

#include "utils.h"

class Button {
  public:
    virtual void touch(uint8_t touchMode, uint16_t x, uint16_t y);
    virtual void show() = 0;
    virtual void hide();

    bool isEnabled();
    void setEnabled(bool enabled);
    void enable();
    void disable();

    void forceRedrawNeeded();

    VoidCallback tapped;
  protected:
    virtual bool inBounds(uint16_t x, uint16_t y);
    bool redrawNeeded = true;
    bool pressed = false;
    bool enabled = true;
};