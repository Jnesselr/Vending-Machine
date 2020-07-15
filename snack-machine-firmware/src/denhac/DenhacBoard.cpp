#ifdef VENDING_MAIN_BOARD

#include "denhac/DenhacBoard.h"
#include "utils.h"

// Task DenhacBoard::billValidatorLoop(200, []{
//   BillValidator::loop();
// });

Task DenhacBoard::coinChangerLoop(200, []{
  CoinChanger::loop();
});

Task DenhacBoard::rfidLoop(100, []{
  RFID::loop();
});

// Task DenhacBoard::uiLoop(20, []{
//   WindowManager::loop();
// });

void DenhacBoard::setup()
{
  Serial.begin(9600);

  //WindowManager::setup();
  MDB::setup();
  RFID::setup();
  //Motors::setup();

  // Looper::add(uiLoop);
  // Looper::add(billValidatorLoop);
  Looper::add(coinChangerLoop);
  // Looper::add(rfidLoop);
}

void DenhacBoard::loop()
{
  Looper::loop();
}

#endif