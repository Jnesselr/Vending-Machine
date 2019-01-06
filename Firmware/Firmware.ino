#include "vendingMachine.h"

static VendingMachine* vendingMachine;

void setup() {
  vendingMachine->setup();
}

void loop() {
  vendingMachine->loop();
}

