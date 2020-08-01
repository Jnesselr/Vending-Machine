#pragma once

#include <stdint.h>

#include "utils.h"

class Button {
  public:
    virtual void touch(uint8_t touchMode, uint16_t x, uint16_t y);
    virtual void show() = 0;
    virtual void hide();

    VoidCallback tapped;

    bool enabled = true;
  protected:
    virtual bool inBounds(uint16_t x, uint16_t y);
    bool pressed = false;
};