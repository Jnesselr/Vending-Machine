#pragma once

#include <Diablo_Serial_4DLib.h>
#include <DirectIO.h>

#include "ui/Window.h"

enum class WindowManagerState {
  UNKNOWN, // No idea what's going on
  RESET,   // Display has been reset
  SETUP,   // Display is set up, we're just waiting to send commands
  IDLE     // Display is idle and ready to go
};

class WindowManager {
  public:
    static void setup();
    static void loop();

    static void show(Window&);

    static uint16_t getWidth();
    static uint16_t getHeight();

  private:
    static void handleNonIdleStates();

    static WindowManagerState state;
    static unsigned long lastStateChangeTime;

    static OutputPort<PORT_H, 2, 1> displayResetPin;
    static HardwareSerial* displaySerial;
    static Diablo_Serial_4DLib display;
    static uint16_t width;
    static uint16_t height;

    static Window* currentWindow;
};