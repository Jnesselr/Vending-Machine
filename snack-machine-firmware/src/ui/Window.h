#pragma once

#include <Diablo_Serial_4DLib.h>

class Window {
  public:
    Window();

    virtual void draw() = 0;
    virtual void loop();

    bool onScreen = false;
    Diablo_Serial_4DLib* display;
};