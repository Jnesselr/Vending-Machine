#ifdef VENDING_MAIN_BOARD

#include "denhac/Session.h"

#include "denhac/SiteLink.h"

unsigned long lastChangeMillis = 0;
bool Session::active = false;
uint32_t Session::cardNum = 0;
Order Session::currentOrder;

Order* Session::getCurrentOrder() {
  return &currentOrder;
}

void Session::cardScanned(uint32_t cardNum) {
  // If there's no active session, request orders by card
  if(!active) {
    SiteLink::getOrdersByCard(cardNum, onGetOrdersByCardError, onGetOrdersByCardSuccess);
  }

  Session::cardNum = cardNum;
  Session::active = true;
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

#endif