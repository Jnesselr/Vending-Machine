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
  BillValidator::onBillRouted = DenhacBindings::onBillRoutedCallback;

  CoinChanger::onStateChanged = DenhacBindings::onCoinChangerStateCallback;
  CoinChanger::onCoinDeposited = DenhacBindings::onCoinDepositedCallback;

  SiteLink::onStateChanged = DenhacBindings::onSiteLinkStateCallback;
  SiteLink::productUpdatedCallback = ProductManager::productUpdated;
  SiteLink::productRemovedCallback = ProductManager::productRemoved;

  Motors::onItemVended = Session::itemVended;
}

void DenhacBindings::onCardScanned(unsigned long cardCode) {
  Session::cardScanned((uint32_t) cardCode);
}

void DenhacBindings::onMotorSystemStateChanged(
  MotorSystemState oldState,
  MotorSystemState newState) {
    if(newState == MotorSystemState::IDLE) {
      DenhacUI::bootWindow.setMotorsIdle(true);
    }
}

void DenhacBindings::onBillValidatorStateCallback(
  BillValidatorState oldState,
  BillValidatorState newState) {
    if(newState == BillValidatorState::IDLE) {
      DenhacUI::bootWindow.setBillValidatorIdle(true);
    }
}

void DenhacBindings::onBillRoutedCallback(BillRouting routing, uint8_t billType) {
  switch(routing) {
    case BillRouting::ESCROW_POSITION:
      BillValidator::acceptBill();
      break;
    case BillRouting::BILL_STACKED:
    case BillRouting::BILL_TO_RECYCLER:
      Session::moneyInserted(BillValidator::billValue(billType));
      break;
  }
}

void DenhacBindings::onCoinChangerStateCallback(
  CoinChangerState oldState,
  CoinChangerState newState) {
    if(newState == CoinChangerState::IDLE) {
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
      DenhacUI::bootWindow.setSiteLinkIdle(true);
    }
}

#endif