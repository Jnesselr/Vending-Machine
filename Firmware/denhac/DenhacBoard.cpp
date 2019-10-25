#ifdef DENHAC_BOARD_CONFIG

// Library: Diablo16-Serial-Arduino-Library
#include <Diablo_Const4D.h> 
#include <Diablo_Serial_4DLib.h>

#include "MDB.h"
#include "MotorGrid.h"

class DenhacBoard: public VendingMachine {
  public:
    DenhacBoard();
    void setup();
    void loop();
  private:
    HardwareSerial* DisplaySerial;
    Diablo_Serial_4DLib* Display;

    MDB* mdb;

    MotorGrid* motorGrid;
};

VendingMachine* VendingMachine::instance = new DenhacBoard();

DenhacBoard::DenhacBoard() {
  this->DisplaySerial = &Serial1;
  this->Display = new Diablo_Serial_4DLib(this->DisplaySerial);

//  this->mdb = MDB::getInstance();

  this->motorGrid = new MotorGrid();
}

void DenhacBoard::setup() {
  Serial.begin(9600);
  this->DisplaySerial->begin(9600);
  this->Display->gfx_ScreenMode(PORTRAIT_R);
  this->Display->gfx_Cls();
  this->Display->println("Denhac Vending Machine");
  
  this->motorGrid->setup();
}

void DenhacBoard::loop() {
  Serial.println("Hello World from the denhac!");
}

#endif