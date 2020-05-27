#ifdef VENDING_MAIN_BOARD

#include "denhac/DenhacBoard.h"
#include "utils.h"

EvtManager DenhacBoard::eventManager;

EvtTimeListener DenhacBoard::billValidatorLoop(200, true, LISTENER {
  BillValidator::loop();
  return false;
});

EvtTimeListener DenhacBoard::coinChangerLoop(200, true, LISTENER {
  CoinChanger::loop();
  return false;
});

EvtTimeListener DenhacBoard::rfidLoop(100, true, LISTENER {
  RFID::loop();
  return false;
});

EvtTimeListener DenhacBoard::uiLoop(20, true, LISTENER {
  WindowManager::loop();
  return false;
});

void DenhacBoard::setup()
{
  Serial.begin(9600);

  WindowManager::setup();
  MDB::setup();
  RFID::setup();
  Motors::setup();

  eventManager.addListener(&uiLoop);
  eventManager.addListener(&billValidatorLoop);
  eventManager.addListener(&coinChangerLoop);
  eventManager.addListener(&rfidLoop);
}

void DenhacBoard::loop()
{
  eventManager.loopIteration();
}

#endif