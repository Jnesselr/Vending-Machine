#ifdef VENDING_MAIN_BOARD

#include "ui/WindowManager.h"
#include "ui/Screen.h"
#include "utils.h"

Window* WindowManager::currentWindow = nullptr;

void WindowManager::loop() {
  if(currentWindow == nullptr) {
    return;
  }

  word touchStatus = Screen::display.touch_Get(TOUCH_STATUS);
  if(touchStatus != 0) {
    currentWindow->touch(
      touchStatus,
      Screen::display.touch_Get(TOUCH_GETX),
      Screen::display.touch_Get(TOUCH_GETY)
    );
  }
  currentWindow->loop();
}

void WindowManager::show(Window& window) {
  window.display = &Screen::display;

  if(currentWindow != nullptr && currentWindow->onScreen) {
    currentWindow->hide();
    currentWindow->onScreen = false;
  }

  currentWindow = &window;

  currentWindow->show();
  currentWindow->onScreen = true;
}

#endif