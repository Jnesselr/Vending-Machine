#include "WindowManager.hpp"

#ifdef VENDING_MAIN_BOARD

VoidCallback WindowManager::windowLoop = nullptr;
VoidCallback WindowManager::windowTeardown = nullptr;
TouchCallback WindowManager::windowTouch = nullptr;

void WindowManager::loop() {
  if(windowLoop == nullptr) {
    return;
  }

  word touchStatus = Screen::display.touch_Get(TOUCH_STATUS);
  if(touchStatus != 0 && windowLoop != nullptr) {
    windowTouch(
      touchStatus,
      Screen::display.touch_Get(TOUCH_GETX),
      Screen::display.touch_Get(TOUCH_GETY)
    );
  }
  windowLoop();
}

#endif