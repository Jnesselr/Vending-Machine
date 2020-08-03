#ifdef VENDING_MAIN_BOARD

#include "ui/Button.h"

#include <Diablo_Const4D.h>

void Button::touch(uint8_t touchMode, uint16_t x, uint16_t y) {
  if(!enabled) {
    return;
  }

  if(touchMode == TOUCH_PRESSED || touchMode == TOUCH_MOVING) {
    if(inBounds(x, y)) {
      if(!pressed) {
        redrawNeeded = true;
        pressed = true;
        show();
      }
    } else {
      if(pressed) {
        redrawNeeded = true;
        pressed = false;
        show();
      }
    }
  } else if(touchMode == TOUCH_RELEASED) {
    if(pressed) {
      redrawNeeded = true;
      pressed = false;
      show();
      CALLBACK(tapped);
    }
  }
}

void Button::hide() {}

bool Button::inBounds(uint16_t x, uint16_t y) {
  return false;
}

bool Button::isEnabled() {
  return this->enabled;
}

void Button::setEnabled(bool enabled) {
  if(this->enabled != enabled) {
    this->enabled = enabled;
    this->redrawNeeded = true;
  }
}

void Button::enable() {
  setEnabled(true);
}

void Button::disable() {
  setEnabled(false);
}

void Button::forceRedrawNeeded() {
  redrawNeeded = true;
}

#endif