#include "denhac/DenhacBoard.h"
#include "utils.h"

EvtManager DenhacBoard::eventManager;

OutputPort<PORT_H, 2, 1> DenhacBoard::displayResetPin;
HardwareSerial* DenhacBoard::displaySerial = &Serial2;
Diablo_Serial_4DLib DenhacBoard::display(DenhacBoard::displaySerial);

EvtTimeListener DenhacBoard::billValidatorLoop(200, true, LISTENER {
  BillValidator::loop();
  return false;
});

EvtTimeListener DenhacBoard::coinChangerLoop(200, true, LISTENER {
  CoinChanger::loop();
  return false;
});

EvtTimeListener DenhacBoard::rfidLoop(20, true, LISTENER {
  RFID::loop();
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
  Serial.println("Hell World!");

  display.Callback4D = mycallback ;

  displaySerial->begin(9600);
  Serial.println("Began serial for display");
  
  displayResetPin.setup();
  Serial.println("Writing 0 to pin hopefully");
  displayResetPin.write(0xFF);
  Serial.println("Done");
  Serial.flush();
  delay(100); 
  displayResetPin.write(0x0);

  delay(5000);

  Serial.println("RESET");

  display.gfx_ScreenMode(PORTRAIT);
  Serial.println("Screen mode set");
  display.gfx_Cls();
  Serial.println("Cleared");
  display.println("Denhac Vending Machine");
  Serial.println("Display serial done");
  // display.print("Hello World!");

  MDB::setup();
  RFID::setup();

  RFID::onCardScanned = [](unsigned long cardCode) {
    Serial.println(cardCode);
    display.println(cardCode);
  };

  // TODO
  // - How to handle coin value added
  // - How to handle coin "vend" token
  // - How to handle coin value removed

  eventManager.addListener(&billValidatorLoop);
  eventManager.addListener(&coinChangerLoop);
  eventManager.addListener(&rfidLoop);
}

void DenhacBoard::loop()
{
  eventManager.loopIteration();
}