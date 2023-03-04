#ifdef VENDING_MAIN_BOARD

#include <Arduino.h>

#include "denhac/DenhacBindings.h"
#include "denhac/data/BridgeStatus.h"
#include "denhac/Session.h"
#include "denhac/ProductManager.h"

#include "hid_rfid.h"

void DenhacBindings::setup() {
  RFID::onCardScanned = DenhacBindings::onCardScanned;

  BillValidator::onBillRouted = DenhacBindings::onBillRoutedCallback;

  CoinChanger::onCoinDeposited = DenhacBindings::onCoinDepositedCallback;

  SiteLink::productUpdatedCallback = ProductManager::productUpdated;
  SiteLink::productRemovedCallback = ProductManager::productRemoved;

  Motors::onItemVended = Session::itemVended;
}

void DenhacBindings::onCardScanned(unsigned long cardCode) {
  Session::cardScanned((uint32_t) cardCode);
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

void DenhacBindings::onCoinDepositedCallback(
  CoinRouting routing,
  uint8_t coinType) {
    if(routing == CoinRouting::REJECT) {
      return;
    }

    Session::moneyInserted(CoinChanger::getValue(coinType));
}

#endif