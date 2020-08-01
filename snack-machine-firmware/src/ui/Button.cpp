#include "ui/Button.h"

#include <Diablo_Const4D.h>

void Button::touch(uint8_t touchMode, uint16_t x, uint16_t y) {
  if(!enabled) {
    return;
  }

  if(touchMode == TOUCH_PRESSED || touchMode == TOUCH_MOVING) {
    if(inBounds(x, y)) {
      if(!pressed) {
        pressed = true;
        show();
      }
    } else {
      if(pressed) {
        pressed = false;
        show();
      }
    }
  } else if(touchMode == TOUCH_RELEASED) {
    if(pressed) {
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