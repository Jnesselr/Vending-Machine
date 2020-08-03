#ifdef VENDING_MAIN_BOARD

#include "denhac/Session.h"
#include "denhac/ProductManager.h"
#include "denhac/SiteLink.h"

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
VoidCallback Session::onCustomerLookupStarted = nullptr;
VoidCallback Session::onOrdersRetrieved = nullptr;
VoidCallback Session::onCurrentOrderUpdated = nullptr;

void Session::reset() {
  active = false;
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

  SiteLink::getOrdersByCard(cardNum, onGetOrdersByCardError, onGetOrdersByCardSuccess);
}

void Session::onGetOrdersByCardError(uint8_t statusCode) {
  // TODO
  Serial.println("Got a status from orders by card!");
  Serial.println(statusCode);
}

void Session::onGetOrdersByCardSuccess(Order orders[], uint8_t numOrders) {
  Session::numOrders = numOrders;
  for (uint8_t i = 0; i < numOrders; i++)
  {
    Session::orders[i] = orders[i];
  }

  Serial.println("Got the orders!");
  if(cardNum != 0) {
    CALLBACK(onOrdersRetrieved);
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

#endif