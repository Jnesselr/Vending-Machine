#include "denhac/DenhacBoard.h"

// Library: Diablo16-Serial-Arduino-Library

HardwareSerial DenhacBoard::DisplaySerial = Serial1;
Diablo_Serial_4DLib DenhacBoard::Display(&DenhacBoard::DisplaySerial);

void DenhacBoard::setup() {
  Serial.begin(9600);
  DisplaySerial.begin(9600);
  Display.gfx_ScreenMode(PORTRAIT_R);
  Display.gfx_Cls();
  Display.println("Denhac Vending Machine");

  MDB::setup();
}

void DenhacBoard::loop() {
  // DenhacBoard::coinChanger.loop();
  // DenhacBoard::billValidator.loop();
  delay(1000);
}

/**
 * Here's what I'm thinking. It looks like it's going to be WAY easier to wire up all
 * of the callbacks if the various classes are static. I don't have anything against
 * making a lot of this static because there will be only one so "construction"
 * doesn't really make sense. It's really all just setup. The only issue becomes how
 * to initialize and call into those things.
 * 
 * One way we could do this is through Eventually. We could setup time events or even
 * custom listeners for stuff like touch events. 
 * 
 * I think instead of a vending machine instance, we could do static setup methods.
 * 
 */