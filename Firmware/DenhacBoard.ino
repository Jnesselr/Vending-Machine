#ifdef DENHAC_BOARD_CONFIG

class DenhacBoard: public VendingMachine {
  public:
    void setup() {
      Serial.begin(9600);
    }
    void loop() {
      Serial.println("Hello World from the denhac!");
    }
};

VendingMachine* VendingMachine::instance = new DenhacBoard();

#endif
