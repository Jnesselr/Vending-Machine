#include "denhac/data/Order.h"

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

Order::Order() {
  orderId = 0;
  status = 0;
  paid = 0;
  total = 0;
  numItems = 0;
}

Order::Order(uint32_t orderId, uint8_t status, uint32_t paid, uint32_t total) {
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
}