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
uint32_t Session::onlineCredit = 0;
uint32_t Session::moneyInsertedInMachine = 0;
bool Session::useRFIDForPayment = false;
VoidCallback Session::onReset = nullptr;
MoneyCallback Session::moneyInsertedCallback = nullptr;
MoneyCallback Session::moneyAvailableCallback = nullptr;
MoneyCallback Session::creditAvailableCallback = nullptr;
VoidCallback Session::onCustomerLookupStarted = nullptr;
VoidCallback Session::onOrdersRetrieved = nullptr;
VoidCallback Session::onNoOrders = nullptr;
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
  useRFIDForPayment = false;

  CALLBACK(onReset);
  CALLBACK(moneyAvailableCallback, 0);
  CALLBACK(onCurrentOrderUpdated);
}

Order* Session::getCurrentOrder() {
  return &currentOrder;
}

void Session::addToCurrentOrder(uint8_t row, uint8_t col) {
  Product product = ProductManager::get(row, col);
  currentOrder.add(product);  // This is afe to call even if the product is invalid

  CALLBACK(onCurrentOrderUpdated);
}

void Session::cardScanned(uint32_t cardNum) {
  // If a new user scans their card, reset the session for the previous user first
  if(Session::cardNum != 0 && Session::cardNum != cardNum) {
    Session::reset();
  }

  Session::cardNum = cardNum;
  CALLBACK(onCustomerLookupStarted);

  SiteLink::getCreditByCard(cardNum, onGetCreditByCardError, onGetCreditByCardSuccess);

  // If we're in an active order, don't bother fetching any orders.
  // Otherwise, we would overwrite the current active order.
  if(! active) {
    SiteLink::getOrdersByCard(cardNum, onGetOrdersByCardError, onGetOrdersByCardSuccess);
  }
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

void Session::onGetOrdersByCardSuccess(const Order& order) {
  // Previous session should have been reset and then cardNum set,
  // but user may have hit cancel on the lookup. Order status of Unknown
  // just means we don't have any order to go off of.

  if(Session::cardNum == 0) {  // User canceled this
    return;
  }

  if(order.status == OrderStatus::UNKNOWN) {
    Session::active = true;
    CALLBACK(onNoOrders);
  } else {
    Session::currentOrder = order;
    Session::active = true;
    CALLBACK(onOrdersRetrieved);
    CALLBACK(onCurrentOrderUpdated);
  }
}

void Session::onGetCreditByCardError(uint8_t statusCode) {
  // TODO
}

void Session::onGetCreditByCardSuccess(uint32_t credit, bool useRFIDForPayment) {
  if(cardNum != 0) {
    Session::onlineCredit = credit;
    Session::useRFIDForPayment = useRFIDForPayment;

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
    Session::moneyInsertedInMachine -= diffCredit;

    CALLBACK(creditAvailableCallback, totalCredit);
    CALLBACK(moneyAvailableCallback, getCurrentAvailableMoney())
  }
}

void Session::onUpdateOrderError(uint8_t statusCode) {
  // TODO
  Serial.println("Update went wrong!");
  Serial.print("Status: ");
  Serial.println(statusCode);
  Session::reset();
}

void Session::onUpdateOrderSuccess(const Order& order) {
  if(currentOrder.status == OrderStatus::PROCESSING) {
    Serial.println("Order was already processing");
    // We know this order has been paid for, so we're just updating
    // vended amounts
    if(order.status == OrderStatus::COMPLETED) {
      Serial.println("It was all vended!");
      if(moneyInsertedInMachine >= order.total) {
        moneyInsertedInMachine -= order.total;
      }

      Session::reset();
      return;
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
      Session::reset();
      return;
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

  SiteLink::updateCreditByCard(cardNum, moneyInsertedInMachine, onUpdateCreditByCardError, onUpdateCreditByCardSuccess);
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

bool Session::canAddRow(uint8_t row) {
  return canAddItem(row, 0) ||
        canAddItem(row, 1) ||
        canAddItem(row, 2) ||
        canAddItem(row, 3) ||
        canAddItem(row, 4) ||
        canAddItem(row, 5) ||
        canAddItem(row, 6) ||
        canAddItem(row, 7);
}

bool Session::canAddItem(uint8_t row, uint8_t col) {
  Product product = ProductManager::get(row, col);
  if(! product.valid) {
    return false;  // Can't add an invlid product
  }

  uint8_t currentStockAvailable = product.stockAvailable;
  uint8_t numOrderItems = currentOrder.getNumItems();
  bool seenItem = false;
  for (uint8_t i = 0; i < numOrderItems; i++)
  {
    Item& item = currentOrder.getItem(i);
    if(item.productId == product.id) {
      currentStockAvailable -= item.quantity;
      seenItem = true;
      break;
    }
  }

  if(! seenItem && numOrderItems == Order::MAX_NUM_ITEMS) {
    return false; // We don't have this item already in the order and can't add a new line item
  }

  return currentStockAvailable > 0;
}

bool Session::canVend() {
  Order* order = Session::getCurrentOrder();

  if(order->status == OrderStatus::PROCESSING) {
    return true;
  }

  if(order->getNumItems() == 0) {
    return false;
  }

  uint32_t total = order->total;
  uint32_t paid = order->paid;
  uint32_t remaining = total - paid;

  if(Session::getCurrentAvailableMoney() >= remaining) {
    return true;
  } else if(Session::useRFIDForPayment) {
    return true;
  } else {
    return false;
  }
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
    Session::uploadCurrentOrder();
  }
}

bool Session::vendNextItem() {
  for (uint8_t i = 0; i < currentOrder.getNumItems(); i++)
  {
    Item& item = currentOrder.getItem(i);
    if(item.quantity > item.vended && !item.skip) {
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

      // If we can't find this item, just skip it and pretend we vended something.
      if (! product.valid) {
        Serial.println("Item wasn't valid, skipping.");
        item.skip = true;
        return true;
      }

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