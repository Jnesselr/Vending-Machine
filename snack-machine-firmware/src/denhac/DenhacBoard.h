#include <Diablo_Serial_4DLib.h>

#include "mdb/MDB.h"
#include "mdb/devices/BillValidator.h"
#include "mdb/devices/CoinChanger.h"

#include "vendingMachine.h"

class DenhacBoard: public VendingMachine {
  public:
    static void setup();
    static void loop();
  private:
    static HardwareSerial DisplaySerial;
    static Diablo_Serial_4DLib Display;

    static BillValidator billValidator;
    // static CoinChanger coinChanger;
};