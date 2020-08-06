#ifdef VENDING_MAIN_BOARD

#include "denhac/Session.h"
#include "denhac/ProductManager.h"
#include "denhac/SiteLink.h"
#include "denhac/data/BridgeStatus.h"

unsigned long lastChangeMillis = 0;
bool Session::active = false;
uint32_t Session::cardNum = 0;
Order Session::currentOrder;
uint8_t Session::numOrders = 0;
Order Session::orders[8];
uint32_t Session::onlineCredit = 0;
uint32_t Session::moneyInsertedInMachine = 0;
VoidCallback Session::onReset = nullptr;
MoneyCallback Session::moneyInsertedCallback = nullptr;
MoneyCallback Session::moneyAvailableCallback = nullptr;
MoneyCallback Session::creditAvailableCallback = nullptr;
VoidCallback Session::onCustomerLookupStarted = nullptr;
VoidCallback Session::onOrdersRetrieved = nullptr;
VoidCallback Session::onUnknownCard = nullptr;
VoidCallback Session::onCurrentOrderUpdated = nullptr;

void Session::reset() {
  active = false;
  saveMoneyInsertedToOnlineCredit();
  cardNum = 0;
  currentOrder.reset();
  moneyInsertedInMachine = 0;
  onlineCredit = 0;

  for (uint8_t i = 0; i < numOrders; i++)
  {
    orders[i].reset();
  }
  numOrders = 0;

  CALLBACK(onReset);
  CALLBACK(moneyAvailableCallback, 0);
  CALLBACK(onCurrentOrderUpdated);
}

uint8_t Session::getNumOrders() {
  return numOrders;
}
Order Session::getOrder(uint8_t orderNum) {
  return orders[orderNum];
}

Order* Session::getCurrentOrder() {
  return &currentOrder;
}

void Session::setCurrentOrderNum(uint8_t orderNum) {
  currentOrder = orders[orderNum];

  CALLBACK(onCurrentOrderUpdated);
}

void Session::addToCurrentOrder(uint8_t row, uint8_t col) {
  currentOrder.add(ProductManager::get(row, col));

  CALLBACK(onCurrentOrderUpdated);
}

void Session::cardScanned(uint32_t cardNum) {
  Session::cardNum = cardNum;
  CALLBACK(onCustomerLookupStarted);

  SiteLink::getCreditByCard(cardNum, onGetCreditByCardError, onGetCreditByCardSuccess);
  SiteLink::getOrdersByCard(cardNum, onGetOrdersByCardError, onGetOrdersByCardSuccess);
}

void Session::onGetOrdersByCardError(uint8_t statusCode) {
  // TODO
  Serial.println("Got an error status from orders by card!");
  Serial.println(statusCode);

  if(cardNum == 0) {
    return;
  }

  if(statusCode == BridgeStatus::REST_NOT_FOUND) {
    CALLBACK(onUnknownCard);
  }
}

void Session::onGetOrdersByCardSuccess(Order orders[], uint8_t numOrders) {
  Session::numOrders = numOrders;
  for (uint8_t i = 0; i < numOrders; i++)
  {
    Session::orders[i] = orders[i];
  }

  if(cardNum != 0) {
    CALLBACK(onOrdersRetrieved);
  }
}

void Session::onGetCreditByCardError(uint8_t statusCode) {
  // TODO
  Serial.println("Got an error status from credit by card!");
  Serial.println(statusCode);
}

void Session::onGetCreditByCardSuccess(uint32_t credit) {
  if(cardNum != 0) {
    Session::onlineCredit = credit;

    CALLBACK(creditAvailableCallback, credit);
    CALLBACK(moneyAvailableCallback, getCurrentAvailableMoney())
  }
}

void Session::onUpdateCreditByCardError(uint8_t statusCode) {
  // TODO
  Serial.println("Got an error status from update credit by card!");
  Serial.println(statusCode);
}

void Session::onUpdateCreditByCardSuccess(uint32_t totalCredit, uint32_t diffCredit) {
  Serial.println("Yay, credit updated!");

  if(cardNum != 0) {
    Session::onlineCredit = totalCredit;

    CALLBACK(creditAvailableCallback, totalCredit);
    CALLBACK(moneyAvailableCallback, getCurrentAvailableMoney())
  }
}

bool Session::isActive() {
  return active;
}

uint32_t Session::getCurrentAvailableMoney() {
  return onlineCredit + moneyInsertedInMachine;
}

void Session::moneyInserted(uint32_t amount) {
  moneyInsertedInMachine += amount;

  CALLBACK(moneyInsertedCallback, amount)
  CALLBACK(moneyAvailableCallback, getCurrentAvailableMoney())
}

void Session::saveMoneyInsertedToOnlineCredit() {
  if(cardNum == 0) {
    return;
  }

  if(moneyInsertedInMachine == 0) {
    return;
  }

  Serial.println("Let's save our money!");

  SiteLink::updateCreditByCard(cardNum, moneyInsertedInMachine, onUpdateCreditByCardError, onUpdateCreditByCardSuccess);
}

#endif