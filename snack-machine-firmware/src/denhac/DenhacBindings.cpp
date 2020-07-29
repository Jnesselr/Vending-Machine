#include <Arduino.h>

#include "denhac/DenhacBindings.h"
#include "denhac/ui/DenhacUI.h"

#include "hid_rfid.h"

void DenhacBindings::setup() {
  RFID::onCardScanned = DenhacBindings::onCardScanned;

  Motors::onSystemStateChanged = DenhacBindings::onMotorSystemStateChanged;

  BillValidator::onStateChanged = DenhacBindings::onBillValidatorStateCallback;

  CoinChanger::onStateChanged = DenhacBindings::onCoinChangerStateCallback;

  SiteLink::onStateChanged = DenhacBindings::onSiteLinkStateCallback;
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

void DenhacBindings::onMotorSystemStateChanged(
  MotorSystemState oldState,
  MotorSystemState newState) {
    if(newState == MotorSystemState::IDLE) {
      Serial.println("Motor state is idle!");
      DenhacUI::bootWindow.setMotorsIdle(true);
    }
}

void DenhacBindings::onBillValidatorStateCallback(
  BillValidatorState oldState,
  BillValidatorState newState) {
    if(newState == BillValidatorState::IDLE) {
      Serial.println("Bill Validator is idle!");
      DenhacUI::bootWindow.setBillValidatorIdle(true);
    }
}

void DenhacBindings::onCoinChangerStateCallback(
  CoinChangerState oldState,
  CoinChangerState newState) {
    if(newState == CoinChangerState::IDLE) {
      Serial.println("Coin Changer is idle!");
      DenhacUI::bootWindow.setCoinChangerIdle(true);
    }
}

void DenhacBindings::onSiteLinkStateCallback(
  SiteLinkState oldState,
  SiteLinkState newState) {
    if(newState == SiteLinkState::IDLE) {
      Serial.println("Site Link is idle!");
      DenhacUI::bootWindow.setSiteLinkIdle(true);
    }
}