#ifdef VENDING_MAIN_BOARD

#include "denhac/DenhacBoard.h"
#include "denhac/SiteLink.h"
#include "utils.h"

#include "mdb/MDB.h"
#include "mdb/devices/BillValidator.h"
#include "mdb/devices/CoinChanger.h"

#include "hid_rfid.h"
#include "motors.h"

#include "ui/WindowManager.h"

Task DenhacBoard::billValidatorLoop(200, []{
  BillValidator::loop();
});

Task DenhacBoard::coinChangerLoop(200, []{
  CoinChanger::loop();
});

Task DenhacBoard::rfidLoop(100, []{
  RFID::loop();
});

Task DenhacBoard::uiLoop(50, []{
  WindowManager::loop();
});

Task DenhacBoard::motorLoop(50, []{
  Motors::loop();
});

Task DenhacBoard::siteLinkLoop(500, []{
  SiteLink::loop();
});

void DenhacBoard::setup()
{
  Serial.begin(9600);

  WindowManager::setup();
  MDB::setup();
  RFID::setup();
  Motors::setup();
  SiteLink::setup();

  Looper::add(uiLoop);
  Looper::add(billValidatorLoop);
  Looper::add(coinChangerLoop);
  Looper::add(rfidLoop);
  Looper::add(motorLoop);
  Looper::add(siteLinkLoop);

  RFID::onCardScanned = DenhacBoard::onCardScanned;
}

void DenhacBoard::loop()
{
  Looper::loop();
}

void DenhacBoard::onCardScanned(unsigned long cardCode) {
  Serial.print("Card scan! ");
  Serial.println(cardCode);

  CoinChanger::dispense(2, 4);
  Motors::vend(0, 0);
}

#endif