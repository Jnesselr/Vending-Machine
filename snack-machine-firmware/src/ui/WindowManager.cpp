#ifdef VENDING_MAIN_BOARD

#include "ui/WindowManager.h"
#include "utils.h"

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

  if(currentWindow != nullptr) {
    currentWindow->loop();
  }
}

void WindowManager::handleNonIdleStates() {
  if(state == WindowManagerState::UNKNOWN) {
    displayResetPin.setup();
    displayResetPin.write(0xFF);
    lastStateChangeTime = current_loop_millis;
    state = WindowManagerState::RESET;
    return;
  }

  if(state == WindowManagerState::RESET) {
    LOOP_WAIT_MS(lastStateChangeTime, 100)

    displayResetPin.write(0x0);
    lastStateChangeTime = current_loop_millis;
    state = WindowManagerState::SETUP;
    return;
  }

  if(state == WindowManagerState::SETUP) {
    LOOP_WAIT_MS(lastStateChangeTime, 3500)

    display.gfx_ScreenMode(PORTRAIT);

    width = display.gfx_Get(X_MAX) + 1;
    height = display.gfx_Get(Y_MAX) + 1;

    lastStateChangeTime = current_loop_millis;
    state = WindowManagerState::IDLE;

    if(currentWindow != nullptr) {
      show(*currentWindow);
    }
    return;
  }
}

void WindowManager::show(Window& window) {
  window.display = &display;

  if(currentWindow != nullptr) {
    currentWindow->onScreen = false;
  }

  currentWindow = &window;

  if(state == WindowManagerState::IDLE) {
    currentWindow->draw();
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