#pragma once

#include "Arduino.h"
#include "denhac/data/Product.h"

class Item {
  public:
    Item();
    Item(uint32_t itemId, uint32_t productId, uint8_t quantity, uint8_t vended);

    uint32_t itemId;
    uint32_t productId;
    uint8_t quantity;
    uint8_t vended;
};

class Order {
  public:
    Order();
    Order(uint32_t orderId, uint8_t status, uint32_t paid, uint32_t total);
    Order(const Order&);

    void operator = (const Order&);

    void add(const Item& item);
    void add(const Product& product);

    uint8_t getNumItems();
    Item getItem(uint8_t itemNum);

    uint32_t orderId;
    uint8_t status;
    uint32_t paid;
    uint32_t total;
  
  private:
    Item items[8];
    uint8_t numItems;
};