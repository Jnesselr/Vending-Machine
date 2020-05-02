#ifdef VENDING_MAIN_BOARD

#include "denhac/DenhacBoard.h"
#include "utils.h"

EvtManager DenhacBoard::eventManager;

OutputPort<PORT_H, 2, 1> DenhacBoard::displayResetPin;
HardwareSerial* DenhacBoard::displaySerial = &Serial2;
Diablo_Serial_4DLib DenhacBoard::display(DenhacBoard::displaySerial);

int DenhacBoard::moneyInserted = 0;

const int PI_COST = 10 * 100;

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

  // display.Callback4D = mycallback ;

  displaySerial->begin(9600);
  
  displayResetPin.setup();
  displayResetPin.write(0xFF);
  delay(100); 
  displayResetPin.write(0x0);

  delay(5000);

  display.gfx_ScreenMode(PORTRAIT_R);
  display.gfx_Cls();
  printMessage();

  MDB::setup();
  RFID::setup();
  Motors::setup();

  BillValidator::onBillAccepted = DenhacBoard::billAccepted;
  BillValidator::onStateChanged = [](BillValidatorState oldState, BillValidatorState newState) {
    display.print("State: ");
    display.print((uint8_t)oldState);
    display.print(" -> ");
    display.println((uint8_t)newState);
  };

  BillValidator::onRecyclerStateChanged = [](BillRecyclerState oldState, BillRecyclerState newState) {
    display.print("Recycler State: ");
    display.print((uint8_t)oldState);
    display.print(" -> ");
    display.println((uint8_t)newState);
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

void DenhacBoard::billAccepted(BillRouting billRouting, uint8_t billType) {
  display.println((int)billRouting);
  display.println(billType);

  if(billRouting == BillRouting::ESCROW_POSITION) {
    BillValidator::acceptBill();
  }
  if(billRouting == BillRouting::BILL_STACKED || billRouting == BillRouting::BILL_TO_RECYCLER) {
    moneyInserted += BillValidator::billValue(billType);
    if(moneyInserted < PI_COST) {
      display.print("I have been fed ");
      display.print(moneyInserted);
      display.print(" cent");
      if(moneyInserted != 1) {
        display.print("s");
      }
      display.println("");

      display.print("Give me ");
      display.print(PI_COST - moneyInserted);
      display.println(" more to get your Pi!");
    } else {
      display.gfx_Cls();
      if(moneyInserted >= PI_COST) {
        display.println("The pi is yours!");
        Motors::vend(3, 4);
        moneyInserted -= PI_COST;
      }

      if(moneyInserted > 0) {
        display.print("You have ");
        display.print(moneyInserted);
        display.print(" cent");
        if(moneyInserted != 1) {
          display.print("s");
        }
        display.println(" leftover for the next transaction.");
      }
      display.println("");
      printMessage();
    }
  }
}

void DenhacBoard::printMessage() {
  display.println("Denhac Vending Machine");
  display.print("Insert ");
  display.print(PI_COST);
  display.println(" cents to get a Pi Zero!");
  display.println("I can't make change yet!");
}

#endif