#include "denhac/data/Order.h"

#include "denhac/ProductManager.h"

Item::Item() {
  itemId = 0;
  productId = 0;
  quantity = 0;
  vended = 0;
}

Item::Item(uint32_t itemId, uint32_t productId, uint8_t quantity, uint8_t vended) {
  this->itemId = itemId;
  this->productId = productId;
  this->quantity = quantity;
  this->vended = vended;
}

void Item::reset() {
  itemId = 0;
  productId = 0;
  quantity = 0;
  vended = 0;
}

Order::Order() {
  orderId = 0;
  status = OrderStatus::UNKNOWN;
  paid = 0;
  total = 0;
  numItems = 0;
}

// TODO Is there any point in having total here if we recalculate it every time we add an item?
Order::Order(uint32_t orderId, OrderStatus status, uint32_t paid, uint32_t total) {
  this->orderId = orderId;
  this->status = status;
  this->paid = paid;
  this->total = total;
  this->numItems = 0;
}

Order::Order(const Order& order) {
  this->orderId = order.orderId;
  this->status = order.status;
  this->paid = order.paid;
  this->total = order.total;
  this->numItems = order.numItems;
  for (uint8_t i = 0; i < numItems; i++)
  {
    this->items[i] = order.items[i];
  }
}

void Order::operator = (const Order& order) {
  this->orderId = order.orderId;
  this->status = order.status;
  this->paid = order.paid;
  this->total = order.total;
  this->numItems = order.numItems;
  for (uint8_t i = 0; i < numItems; i++)
  {
    this->items[i] = order.items[i];
  }
}

void Order::add(const Item& item) {
  this->items[numItems] = item;
  numItems++;
  recalculateTotal();
}

void Order::add(const Product& product) {
  for (uint8_t i = 0; i < numItems; i++)
  {
    Item* item = &(items[i]);
    if(item->productId == product.id) {
      if(item->quantity + 1 <= product.stockAvailable) {
        (item->quantity)++;
        recalculateTotal();
      }
      return;
    }
  }

  Item item(0, product.id, 1, 0);
  this->add(item);
}

uint8_t Order::getNumItems() {
  return numItems;
}

Item& Order::getItem(uint8_t itemNum) {
  return items[itemNum];
}

void Order::vendedItem(uint8_t itemNum) {
  items[itemNum].vended++;
}

void Order::recalculateTotal() {
  uint32_t newTotal = 0;
  for (uint8_t i = 0; i < numItems; i++)
  {
    Item* item = &(items[i]);
    Product product = ProductManager::get(item->productId);
    newTotal += item->quantity * product.price;
  }

  this->total = newTotal;
}

void Order::reset() {
  for (uint8_t i = 0; i < numItems; i++)
  {
    items[i].reset();
  }
  
  numItems = 0;
  orderId = 0;
  status = OrderStatus::UNKNOWN;
  paid = 0;
  total = 0;
}