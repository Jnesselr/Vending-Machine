#ifdef VENDING_MAIN_BOARD

#include "denhac/Session.h"

#include "denhac/SiteLink.h"

unsigned long lastChangeMillis = 0;
bool Session::active = false;
uint32_t Session::cardNum = 0;
Order Session::currentOrder;
uint32_t Session::onlineCredit = 0;
uint32_t Session::moneyInsertedInMachine = 0;
MoneyCallback Session::moneyInsertedCallback = nullptr;
MoneyCallback Session::moneyAvailableCallback = nullptr;
VoidCallback Session::onCustomerLookupStarted = nullptr;

void Session::reset() {
  active = false;
  cardNum = 0;
  currentOrder.reset();
  moneyInsertedInMachine = 0;
  onlineCredit = 0;

  CALLBACK(moneyAvailableCallback, 0);
}

Order* Session::getCurrentOrder() {
  return &currentOrder;
}

void Session::cardScanned(uint32_t cardNum) {
  CALLBACK(onCustomerLookupStarted);

  SiteLink::getOrdersByCard(cardNum, onGetOrdersByCardError, onGetOrdersByCardSuccess);

  Session::cardNum = cardNum;
}

void Session::onGetOrdersByCardError(uint8_t statusCode) {
  // TODO
  Serial.println("Got a status from orders by card!");
  Serial.println(statusCode);
}

void Session::onGetOrdersByCardSuccess(Order orders[], uint8_t numOrders) {
  // TODO
  Serial.println("Got the orders!");
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

#endif