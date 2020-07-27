#ifdef VENDING_MAIN_BOARD

#include "ui/WindowManager.h"

OutputPort<PORT_H, 2, 1> WindowManager::displayResetPin;
HardwareSerial* WindowManager::displaySerial = &Serial2;
Diablo_Serial_4DLib WindowManager::display(WindowManager::displaySerial);

uint16_t WindowManager::width = 0;
uint16_t WindowManager::height = 0;

WindowManagerState WindowManager::state = WindowManagerState::UNKNOWN;
unsigned long WindowManager::lastStateChangeTime = 0;

Window* WindowManager::currentWindow = nullptr;

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

    display.gfx_ScreenMode(PORTRAIT);

    width = display.gfx_Get(X_MAX) + 1;
    height = display.gfx_Get(Y_MAX) + 1;

    lastStateChangeTime = currentMillis;
    state = WindowManagerState::IDLE;

    if(currentWindow != nullptr) {
      show(*currentWindow);
    }
    return;
  }
}

void WindowManager::show(Window& window) {
  if(currentWindow != nullptr) {
    currentWindow->onScreen = false;
  }

  currentWindow = &window;

  if(state == WindowManagerState::IDLE) {
    currentWindow->draw(display);
    currentWindow->onScreen = true;
  }
}

uint16_t WindowManager::getWidth() {
  return width;
}

uint16_t WindowManager::getHeight() {
  return height;
}

#endif