#pragma once

#include <Diablo_Serial_4DLib.h>
#include <DirectIO.h>

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

  private:
    static void handleNonIdleStates();

    static WindowManagerState state;
    static unsigned long lastStateChangeTime;

    static OutputPort<PORT_H, 2, 1> displayResetPin;
    static HardwareSerial* displaySerial;
    static Diablo_Serial_4DLib display;
};