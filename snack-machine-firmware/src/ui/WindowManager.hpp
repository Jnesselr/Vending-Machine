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
  // Tear down the old window, if there is one
  if(WindowManager::windowTeardown != nullptr) {
    windowTeardown();
  }

  // Ensure any internal variables are referring to the window we want to show
  WindowManager::windowLoop = T::loop;
  WindowManager::windowTouch = T::touch;
  WindowManager::windowTeardown = T::teardown;

  // Allow the window to setup anything it needs to before we start calling its loop/touch methods
  T::setup();
}

#endif
