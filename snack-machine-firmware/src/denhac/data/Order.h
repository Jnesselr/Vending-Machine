#pragma once

#include "Arduino.h"
#include "denhac/data/Product.h"
#include "denhac/data/OrderStatus.h"

class Item {
  public:
    Item();
    Item(uint32_t itemId, uint32_t productId, uint8_t quantity, uint8_t vended);

    void reset();

    uint32_t itemId;
    uint32_t productId;
    uint8_t quantity;
    uint8_t vended;
    bool skip;
};

class Order {
  public:
    Order();
    Order(uint32_t orderId, OrderStatus status, uint32_t paid, uint32_t total);
    Order(const Order&);

    void operator = (const Order&);

    void add(const Item& item);
    void add(const Product& product);

    uint8_t getNumItems();
    Item& getItem(uint8_t itemNum);
    void vendedItem(uint8_t itemNum);

    void reset();

    uint32_t orderId;
    OrderStatus status;
    uint32_t paid;
    uint32_t total;

    static const uint8_t MAX_NUM_ITEMS = 8;
  private:
    void recalculateTotal();
    Item items[Order::MAX_NUM_ITEMS];
    uint8_t numItems;
};