#include "config.h"
#include "vendingMachine.h"

void setup() {
  VendingMachine::instance->setup();
}

void loop() {
  VendingMachine::instance->loop();
}

