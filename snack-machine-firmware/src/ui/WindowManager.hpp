#pragma once

#ifdef VENDING_MAIN_BOARD

#include <Diablo_Serial_4DLib.h>
#include <DirectIO.h>

#include "ui/Screen.h"
#include "utils.h"

typedef void (*TouchCallback)(uint8_t touchMode, uint16_t x, uint16_t y);

class WindowManager {
public:
  static void loop();
  
  template<typename T>
  static void show();

private:
  static VoidCallback windowLoop;
  static VoidCallback windowTeardown;
  static TouchCallback windowTouch;
};

template<typename T>
void WindowManager::show() {
  T::setup();

  WindowManager::windowLoop = T::loop;
  WindowManager::windowTeardown = T::teardown;
  WindowManager::windowTouch = T::touch;
}

#endif