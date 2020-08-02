#ifdef VENDING_MAIN_BOARD

#include <Arduino.h>

#include "denhac/DenhacBindings.h"
#include "denhac/ui/DenhacUI.h"
#include "denhac/Session.h"
#include "denhac/ProductManager.h"

#include "hid_rfid.h"

void DenhacBindings::setup() {
  RFID::onCardScanned = DenhacBindings::onCardScanned;

  Motors::onSystemStateChanged = DenhacBindings::onMotorSystemStateChanged;

  BillValidator::onStateChanged = DenhacBindings::onBillValidatorStateCallback;

  CoinChanger::onStateChanged = DenhacBindings::onCoinChangerStateCallback;
  CoinChanger::onCoinDeposited = DenhacBindings::onCoinDepositedCallback;

  SiteLink::onStateChanged = DenhacBindings::onSiteLinkStateCallback;
  SiteLink::productUpdatedCallback = ProductManager::productUpdated;
  SiteLink::productRemovedCallback = ProductManager::productRemoved;
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

void DenhacBindings::onCoinDepositedCallback(
  CoinRouting routing,
  uint8_t coinType) {
    if(routing == CoinRouting::REJECT) {
      return;
    }

    Session::moneyInserted(CoinChanger::getValue(coinType));
}

void DenhacBindings::onSiteLinkStateCallback(
  SiteLinkState oldState,
  SiteLinkState newState) {
    if(newState == SiteLinkState::IDLE) {
      Serial.println("Site Link is idle!");
      DenhacUI::bootWindow.setSiteLinkIdle(true);
    }
}

#endif