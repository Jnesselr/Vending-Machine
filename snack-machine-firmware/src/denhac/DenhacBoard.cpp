#ifdef VENDING_MAIN_BOARD

#include <avr/wdt.h>
#include "denhac/DenhacBoard.h"
#include "denhac/SiteLink.h"
#include "utils.h"

#include "mdb/MDB.h"
#include "mdb/devices/BillValidator.h"
#include "mdb/devices/CoinChanger.h"

#include "hid_rfid.h"
#include "motors.h"

#include "ui/WindowManager.h"
#include "denhac/ui/DenhacUI.h"
#include "denhac/DenhacBindings.h"

Task DenhacBoard::billValidatorLoop(200, []{
  BillValidator::loop();
});

Task DenhacBoard::coinChangerLoop(200, []{
  CoinChanger::loop();
});

Task DenhacBoard::rfidLoop(100, []{
  RFID::loop();
});

Task DenhacBoard::uiLoop(10, []{
  WindowManager::loop();
});

Task DenhacBoard::motorLoop(40, []{
  Motors::loop();
});

Task DenhacBoard::siteLinkLoop(300, []{
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
  DenhacBindings::setup();

  Looper::add(uiLoop);
  Looper::add(billValidatorLoop);
  Looper::add(coinChangerLoop);
  Looper::add(rfidLoop);
  Looper::add(motorLoop);
  Looper::add(siteLinkLoop);

  WindowManager::show(DenhacUI::bootWindow);

  wdt_enable(WDTO_8S);
}

void DenhacBoard::loop()
{
  wdt_reset();
  Looper::loop();
}

#endif