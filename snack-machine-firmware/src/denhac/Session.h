#pragma once

#include <stdint.h>
#include "denhac/data/Order.h"

typedef void (*MoneyCallback)(uint32_t amount);

class Session {
  public:
    static Order* getCurrentOrder();
    static bool isActive();
    static uint32_t getCurrentAvailableMoney();

    static void cardScanned(uint32_t cardNum);

    static void moneyInserted(uint32_t amount);
    static MoneyCallback moneyInsertedCallback;
    static MoneyCallback moneyAvailableCallback;

  private:
    static void onGetOrdersByCardError(uint8_t statusCode);
    static void onGetOrdersByCardSuccess(Order orders[], uint8_t numOrders);

    static unsigned long lastChangeMillis;
    static bool active;
    static uint32_t cardNum;
    static Order currentOrder;

    static uint32_t moneyInsertedInMachine;
    static uint32_t onlineCredit;
};