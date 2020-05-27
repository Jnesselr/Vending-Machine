#ifdef VENDING_MAIN_BOARD

#include "ui/WindowManager.h"

OutputPort<PORT_H, 2, 1> WindowManager::displayResetPin;
HardwareSerial* WindowManager::displaySerial = &Serial2;
Diablo_Serial_4DLib WindowManager::display(WindowManager::displaySerial);

WindowManagerState WindowManager::state = WindowManagerState::UNKNOWN;
unsigned long WindowManager::lastStateChangeTime = 0;

void WindowManager::setup() {
  displaySerial->begin(9600);
}

void WindowManager::loop() {
  if(state != WindowManagerState::IDLE) {
    handleNonIdleStates();
    return;
  }
}

void WindowManager::handleNonIdleStates() {
  if(state == WindowManagerState::UNKNOWN) {
    displayResetPin.setup();
    displayResetPin.write(0xFF);
    lastStateChangeTime = millis();
    state = WindowManagerState::RESET;
    return;
  }

  if(state == WindowManagerState::RESET) {
    if((millis() - 100) < lastStateChangeTime) {
      return;
    }

    displayResetPin.write(0x0);
    lastStateChangeTime = millis();
    state = WindowManagerState::SETUP;
    return;
  }

  if(state == WindowManagerState::SETUP) {
    if((millis() - 5000) < lastStateChangeTime) {
      return;
    }

    display.gfx_ScreenMode(PORTRAIT_R);
    display.gfx_Cls();
    lastStateChangeTime = millis();
    state = WindowManagerState::IDLE;
    return;
  }
}

#endif