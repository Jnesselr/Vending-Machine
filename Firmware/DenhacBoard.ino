#ifdef DENHAC_BOARD_CONFIG

// Library: Diablo16-Serial-Arduino-Library
#include <Diablo_Const4D.h> 
#include <Diablo_Serial_4DLib.h>

#include "MDB.h"

class DenhacBoard: public VendingMachine {
  public:
    DenhacBoard();
    void setup();
    void loop();
  private:
    HardwareSerial* DisplaySerial;
    Diablo_Serial_4DLib* Display;

    MDB* mdb;
};

VendingMachine* VendingMachine::instance = new DenhacBoard();

DenhacBoard::DenhacBoard() {
  this->DisplaySerial = &Serial1;
  this->Display = new Diablo_Serial_4DLib(this->DisplaySerial);

  this->mdb = MDB::getInstance();
}

void DenhacBoard::setup() {
  Serial.begin(9600);
  this->DisplaySerial->begin(9600);
}

void DenhacBoard::loop() {
  Serial.println("Hello World from the denhac!");
}

#endif
