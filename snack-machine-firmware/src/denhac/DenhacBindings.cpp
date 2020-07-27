#include <Arduino.h>

#include "denhac/DenhacBindings.h"

#include "denhac/SiteLink.h"

#include "hid_rfid.h"

void DenhacBindings::setup() {
  RFID::onCardScanned = DenhacBindings::onCardScanned;
}

void DenhacBindings::onCardScanned(unsigned long cardCode) {
  Serial.print("Card scan! ");
  Serial.println(cardCode);

  //CoinChanger::dispense(2, 4);
  //Motors::vend(0, 0);
  SiteLink::getOrdersByCard((uint32_t) cardCode,
  [](uint8_t statusCode){
    Serial.println("Got a status from orders by card!");
    Serial.println(statusCode);
  },
  [](Order orders[], uint8_t numOrders) {
    Serial.println("Got the orders!");
  });
}