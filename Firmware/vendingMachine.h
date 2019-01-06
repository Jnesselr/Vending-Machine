class VendingMachine {
  public:
    virtual void setup() = 0;
    virtual void loop() = 0;
    static VendingMachine* instance;
};

