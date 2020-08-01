#ifdef VENDING_MAIN_BOARD

#include <Arduino.h>

#include "denhac/DenhacBindings.h"
#include "denhac/ui/DenhacUI.h"
#include "denhac/Session.h"

#include "hid_rfid.h"

void DenhacBindings::setup() {
  RFID::onCardScanned = DenhacBindings::onCardScanned;

  Motors::onSystemStateChanged = DenhacBindings::onMotorSystemStateChanged;

  BillValidator::onStateChanged = DenhacBindings::onBillValidatorStateCallback;

  CoinChanger::onStateChanged = DenhacBindings::onCoinChangerStateCallback;

  SiteLink::onStateChanged = DenhacBindings::onSiteLinkStateCallback;
  SiteLink::productUpdatedCallback = DenhacBindings::onProductUpdatedCallback;
}

void DenhacBindings::onCardScanned(unsigned long cardCode) {
  Session::cardScanned((uint32_t) cardCode);
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

void DenhacBindings::onProductUpdatedCallback(const Product& product) {
  Serial.println("Product updated!");
  Serial.print("ID: ");
  Serial.println(product.id);
  Serial.print("Name: ");
  Serial.println(product.name);
  Serial.print("Row: ");
  Serial.println(product.row);
  Serial.print("Col: ");
  Serial.println(product.col);
  Serial.print("Price: ");
  Serial.println(product.price);
  Serial.print("Stock Available: ");
  Serial.println(product.stockAvailable);
  Serial.print("Stock In Machine: ");
  Serial.println(product.stockInMachine);
}

#endif