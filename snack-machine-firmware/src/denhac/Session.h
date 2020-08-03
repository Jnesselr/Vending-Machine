#pragma once

#include <stdint.h>
#include "denhac/data/Order.h"
#include "utils.h"

typedef void (*MoneyCallback)(uint32_t amount);

class Session {
  public:
    static void reset();
    static VoidCallback onReset;

    static uint8_t getNumOrders();
    static Order getOrder(uint8_t orderNum);
    static Order* getCurrentOrder();
    static void setCurrentOrderNum(uint8_t orderNum);
    static void addToCurrentOrder(uint8_t row, uint8_t col);

    static bool isActive();
    static uint32_t getCurrentAvailableMoney();

    static void cardScanned(uint32_t cardNum);

    static void moneyInserted(uint32_t amount);
    static MoneyCallback moneyInsertedCallback;
    static MoneyCallback moneyAvailableCallback;

    static VoidCallback onCustomerLookupStarted;
    static VoidCallback onOrdersRetrieved;

    static VoidCallback onCurrentOrderUpdated;
  private:
    static void onGetOrdersByCardError(uint8_t statusCode);
    static void onGetOrdersByCardSuccess(Order orders[], uint8_t numOrders);

    static unsigned long lastChangeMillis;
    static bool active;
    static uint32_t cardNum;
    static Order currentOrder;
    static uint8_t numOrders;
    static Order orders[8];

    static uint32_t moneyInsertedInMachine;
    static uint32_t onlineCredit;
};