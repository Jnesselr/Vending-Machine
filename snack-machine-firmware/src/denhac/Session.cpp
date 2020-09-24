#ifdef VENDING_MAIN_BOARD

#include "denhac/Session.h"
#include "denhac/ProductManager.h"
#include "denhac/SiteLink.h"
#include "denhac/data/BridgeStatus.h"
#include "mdb/devices/CoinChanger.h"
#include "motors.h"

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
  if(moneyInsertedInMachine > 0) {
    if(cardNum == 0) {
      CoinChanger::dispense(moneyInsertedInMachine);
    } else {
      saveMoneyInsertedToOnlineCredit();
    }
  }

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
}

void Session::onUpdateCreditByCardSuccess(uint32_t totalCredit, uint32_t diffCredit) {
  if(cardNum != 0) {
    Session::onlineCredit = totalCredit;

    CALLBACK(creditAvailableCallback, totalCredit);
    CALLBACK(moneyAvailableCallback, getCurrentAvailableMoney())
  }
}

void Session::onUpdateOrderError(uint8_t statusCode) {
  // TODO
  Serial.println("Update went wrong!");
  Serial.print("Status: ");
  Serial.println(statusCode);
}
void Session::onUpdateOrderSuccess(const Order& order) {
  if(currentOrder.status == OrderStatus::PROCESSING) {
    Serial.println("Order was already processing");
    // We know this order has been paid for, so we're just updating
    // vended amounts
    if(order.status == OrderStatus::COMPLETED) {
      Serial.println("It was all vended!");
      if(moneyInsertedInMachine > order.total) {
        CoinChanger::dispense(moneyInsertedInMachine - order.total);
      }
    }
  } else {
    // We did this update to verify the order was paid for
    if(order.status == OrderStatus::PROCESSING) {
      Serial.println("It was paid for yay!");
      currentOrder = order;
      // Good, it was paid for, we can vend
      Session::vend();
    } else {
      // TODO Uh oh something went wrong
      Serial.println("It wasn't paid for?");
    }
  }

  currentOrder = order;
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

  // uploadCurrentOrder();
}

void Session::uploadCurrentOrder() {
  // Only upload as much cash as is needed for the order
  uint32_t cashToUpload = min(moneyInsertedInMachine, currentOrder.total);

  SiteLink::updateOrder(
      cardNum,
      cashToUpload,
      currentOrder,
      onUpdateOrderError,
      onUpdateOrderSuccess
    );
}

void Session::vend() {
  if(currentOrder.status != OrderStatus::PROCESSING || currentOrder.orderId == 0) {
    Serial.println("Verifying order was paid for");
    uploadCurrentOrder();
    return;
  }

  Serial.println("Starting vend!");
  bool anyVended = vendNextItem();

  if(!anyVended) {
    // TODO Update the order so it gets marked as "complete"
    // Although it is very strange that nothing would be vended here
  }
}

void Session::itemVended(uint8_t row, uint8_t col) {
  ProductManager::reduceStock(row, col);
  Product product = ProductManager::get(row, col);
  Serial.println("Item vended!");
  Serial.print("Row: ");
  Serial.println(row);
  Serial.print("Col: ");
  Serial.println(col);

  for (uint8_t i = 0; i < currentOrder.getNumItems(); i++)
  {
    Item& item = currentOrder.getItem(i);
    if(item.productId == product.id) {
      currentOrder.vendedItem(i);
    }
  }

  bool anyVended = vendNextItem();

  if(!anyVended) {
    Serial.println("Vended them all woot!");
    SiteLink::updateOrder(
      Session::cardNum,
      Session::moneyInsertedInMachine,
      Session::currentOrder,
      onUpdateOrderError,
      onUpdateOrderSuccess
    );
  }
}

bool Session::vendNextItem() {
  for (uint8_t i = 0; i < currentOrder.getNumItems(); i++)
  {
    Item& item = currentOrder.getItem(i);
    if(item.quantity > item.vended) {
      Serial.println("Found an item to vend!");
      Serial.print("Item ID: ");
      Serial.println(item.itemId);
      Serial.print("Product ID: ");
      Serial.println(item.productId);
      Serial.print("Quantity: ");
      Serial.println(item.quantity);
      Serial.print("Vended: ");
      Serial.println(item.vended);

      Product product = ProductManager::get(item.productId);
      Serial.print("Row: ");
      Serial.println(product.row);
      Serial.print("Col: ");
      Serial.println(product.col);
      Motors::vend(product.row, product.col);
      return true;
    }
  }

  return false;
}

#endif