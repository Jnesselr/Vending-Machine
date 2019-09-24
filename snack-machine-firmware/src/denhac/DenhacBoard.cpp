#include "denhac/DenhacBoard.h"
#include "utils.h"

EvtManager DenhacBoard::eventManager;

HardwareSerial DenhacBoard::DisplaySerial = Serial1;
Diablo_Serial_4DLib DenhacBoard::Display(&DenhacBoard::DisplaySerial);

EvtTimeListener DenhacBoard::billValidatorLoop(250, true, LISTENER {
                            BillValidator::loop();
                            return false;
                          });

void DenhacBoard::setup()
{
  Serial.begin(9600);
  DisplaySerial.begin(9600);
  Display.gfx_ScreenMode(PORTRAIT_R);
  Display.gfx_Cls();
  Display.println("Denhac Vending Machine");

  MDB::setup();

  eventManager.addListener(&billValidatorLoop);
}

void DenhacBoard::loop()
{
  eventManager.loopIteration();
}