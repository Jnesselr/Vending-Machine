#pragma once

#include <Diablo_Serial_4DLib.h>

class Window {
  public:
    Window();

    virtual void show() = 0;
    virtual void loop();
    virtual void hide();
    virtual void touch(uint8_t touchMode, uint16_t x, uint16_t y);

    bool onScreen = false;
    Diablo_Serial_4DLib* display;
};