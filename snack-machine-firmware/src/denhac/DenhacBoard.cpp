#include "denhac/DenhacBoard.h"
#include "utils.h"

EvtManager DenhacBoard::eventManager;

OutputPort<PORT_H, 2, 1> DenhacBoard::displayResetPin;
HardwareSerial* DenhacBoard::displaySerial = &Serial2;
Diablo_Serial_4DLib DenhacBoard::display(DenhacBoard::displaySerial);

int DenhacBoard::dollarsGiven = 0;

const int PI_COST = 10;

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

  display.gfx_ScreenMode(PORTRAIT);
  display.gfx_Cls();
  printMessage();

  MDB::setup();
  RFID::setup();
  Motors::setup();

  BillValidator::onBillAccepted = DenhacBoard::billAccepted;

  CoinChanger::onCoinDeposited = [](CoinRouting routing, uint8_t coinType) {
    // display.println((int)routing);
    // display.println(coinType);
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
  // display.println((int)billRouting);
  // display.println(billType);

  if(billRouting == BillRouting::ESCROW_POSITION ||
    billRouting == BillRouting::BILL_STACKED) {
    BillValidator::acceptBill();
    dollarsGiven++;
    if(dollarsGiven < PI_COST) {
      display.print("I have been fed ");
      display.print(dollarsGiven);
      display.print(" dollar");
      if(dollarsGiven != 1) {
        display.print("s");
      }
      display.println("");

      display.print("Give me ");
      display.print(PI_COST - dollarsGiven);
      display.println(" more to get your Pi!");
    } else {
      display.println("The pi is yours!");
      Motors::rotate(3, 4);
      dollarsGiven = 0;
      display.println("");
      printMessage();
    }
  }
}

void DenhacBoard::printMessage() {
  display.println("Denhac Vending Machine");
  display.print("Insert $");
  display.print(PI_COST);
  display.println(" to get a Pi Zero!");
  display.println("Please use $1 bills, I can't make change yet!");
}