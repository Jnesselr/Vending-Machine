#ifdef VENDING_MAIN_BOARD

#include "ui/WindowManager.h"

OutputPort<PORT_H, 2, 1> WindowManager::displayResetPin;
HardwareSerial* WindowManager::displaySerial = &Serial2;
Diablo_Serial_4DLib WindowManager::display(WindowManager::displaySerial);

WindowManagerState WindowManager::state = WindowManagerState::UNKNOWN;
unsigned long WindowManager::lastStateChangeTime = 0;

void WindowManager::setup() {
  displaySerial->begin(9600);
  display.TimeLimit4D = 200;
}

void WindowManager::loop() {
  if(state != WindowManagerState::IDLE) {
    handleNonIdleStates();
    return;
  }
}

void WindowManager::handleNonIdleStates() {
  unsigned long currentMillis = millis();
  if(state == WindowManagerState::UNKNOWN) {
    displayResetPin.setup();
    displayResetPin.write(0xFF);
    lastStateChangeTime = currentMillis;
    state = WindowManagerState::RESET;
    return;
  }

  if(state == WindowManagerState::RESET) {
    if(currentMillis < lastStateChangeTime + 100) {
      return;
    }

    displayResetPin.write(0x0);
    lastStateChangeTime = currentMillis;
    state = WindowManagerState::SETUP;
    return;
  }

  if(state == WindowManagerState::SETUP) {
    if(currentMillis < lastStateChangeTime + 5000) {
      return;
    }

    lastStateChangeTime = currentMillis;
    state = WindowManagerState::IDLE;

    display.gfx_Cls();
    display.gfx_ScreenMode(PORTRAIT);
    display.println("Hello World!");
    return;
  }
}

#endif