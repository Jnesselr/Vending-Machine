#pragma once

#include <Diablo_Serial_4DLib.h>

class Window {
  public:
    Window();

    virtual void show() = 0;
    virtual void loop();
    virtual void hide();

    bool onScreen = false;
    Diablo_Serial_4DLib* display;
};