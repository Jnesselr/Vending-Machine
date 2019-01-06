#ifdef DENHAC_BOARD_CONFIG

class DenhacBoard: public VendingMachine {
  public:
    void setup();
    void loop();
};

VendingMachine* VendingMachine::instance = new DenhacBoard();


void DenhacBoard::setup() {
  Serial.begin(9600);
}

void DenhacBoard::loop() {
  Serial.println("Hello World from the denhac!");
}

#endif
