#pragma once

#include "Arduino.h"
#include "config.h"
#include "vendingMachine.h"

#include <WiFi.h>
#include <HTTPClient.h>

class DenhacWifiBridge: public VendingMachine {
  public:
    static void setup();
    static void loop();
};