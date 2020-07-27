#pragma once

#include <Diablo_Serial_4DLib.h>

class Window {
  public:
    Window();

    virtual void draw(Diablo_Serial_4DLib& display) = 0;

    bool onScreen = false;
};