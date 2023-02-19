#pragma once

#include <Diablo_Serial_4DLib.h>
#include <DirectIO.h>

#include "ui/Window.h"

class WindowManager {
  public:
    static void loop();

    static void show(Window&);

  private:

    static Window* currentWindow;
};