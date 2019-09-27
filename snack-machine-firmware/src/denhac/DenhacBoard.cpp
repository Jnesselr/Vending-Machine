#include "denhac/DenhacBoard.h"
#include "utils.h"

EvtManager DenhacBoard::eventManager;

OutputPort<PORT_G, 3, 1> DenhacBoard::displayResetPin;
HardwareSerial DenhacBoard::displaySerial = Serial1;
Diablo_Serial_4DLib DenhacBoard::display(&DenhacBoard::displaySerial);

EvtTimeListener DenhacBoard::billValidatorLoop(250, true, LISTENER {
  BillValidator::loop();
  return false;
});

EvtTimeListener DenhacBoard::coinChangerLoop(250, true, LISTENER {
  CoinChanger::loop();
  return false;
});

void mycallback(int ErrCode, unsigned char Errorbyte)
{
  Serial.print("Code: ");
  Serial.println(ErrCode);
  Serial.print("Byte: ");
  Serial.println(Errorbyte);
}

void DenhacBoard::setup()
{
  Serial.begin(9600);
  Serial.println("Hey");

  // display.Callback4D = mycallback ;

  // displaySerial.begin(9600);
  // Serial.println("Began serial for display");
  
  // displayResetPin.setup();
  // displayResetPin.write(0x1);
  // delay(100);
  // displayResetPin.write(0x0);

  // delay(5000);

  // Serial.println("RESET");

  // display.gfx_ScreenMode(PORTRAIT_R);
  // Serial.println("Screen mode set");
  // display.gfx_Cls();
  // Serial.println("Cleared");
  // display.println("Denhac Vending Machine");
  // Serial.println("Display serial done");

  MDB::setup();

  Serial.println("MDB Done");

  eventManager.addListener(&billValidatorLoop);
  eventManager.addListener(&coinChangerLoop);
}

void DenhacBoard::loop()
{
  eventManager.loopIteration();
}