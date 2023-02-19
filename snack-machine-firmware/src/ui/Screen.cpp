#include "Screen.h"

#include "utils.h"

OutputPort<PORT_H, 2, 1> Screen::displayResetPin;
HardwareSerial* Screen::displaySerial = &Serial2;
Diablo_Serial_4DLib Screen::display(Screen::displaySerial);

uint16_t Screen::width = 0;
uint16_t Screen::height = 0;

/**
 * This is one of the few setup functions that runs all the way through before returning.
 * This is because both windows and logging to the SD card might use our Diablo screen.
 */
void Screen::setup() {
  displayResetPin.setup();
  displaySerial->begin(9600);

  display.TimeLimit4D = 200;

  displayResetPin.write(0xFF);  // Begin the reset

  delay(100);  // Let the reset kick in

  displayResetPin.write(0x0);  // Stop resetting the display

  delay(3500);  // The display takes about this long before we can talk to it again

  bool baudRateSuccess = display.setbaudWait(BAUD_128000);
    if(baudRateSuccess) {
      Serial.println("WE CHANGED THE BAUD RATE!");
    } else {
      Serial.println("No baud rate change for us :'(");
    }

    display.gfx_ScreenMode(PORTRAIT);

    width = display.gfx_Get(X_MAX) + 1;
    height = display.gfx_Get(Y_MAX) + 1;
    display.touch_Set(TOUCH_ENABLE);
    display.touch_Set(TOUCH_REGIONDEFAULT);
}

uint16_t Screen::getWidth() {
  return Screen::width;
}

uint16_t Screen::getHeight() {
  return Screen::height;
}