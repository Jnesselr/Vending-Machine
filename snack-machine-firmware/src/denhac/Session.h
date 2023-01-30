#pragma once

#include <stdint.h>
#include "denhac/data/Order.h"
#include "utils.h"

typedef void (*MoneyCallback)(uint32_t amount);

class Session {
  public:
    static void reset();
    static VoidCallback onReset;

    static Order* getCurrentOrder();
    static void addToCurrentOrder(uint8_t row, uint8_t col);

    static bool isActive();
    static uint32_t getCurrentAvailableMoney();

    static void cardScanned(uint32_t cardNum);

    static void moneyInserted(uint32_t amount);
    static MoneyCallback moneyInsertedCallback;
    static MoneyCallback moneyAvailableCallback;
    static MoneyCallback creditAvailableCallback;

    static bool canVend();
    static void vend();
    static void itemVended(uint8_t row, uint8_t col);

    static VoidCallback onCustomerLookupStarted;
    static VoidCallback onOrdersRetrieved;
    static VoidCallback onNoOrders;
    static VoidCallback onUnknownCard;

    static VoidCallback onCurrentOrderUpdated;
  private:
    static void onGetOrdersByCardError(uint8_t statusCode);
    static void onGetOrdersByCardSuccess(const Order& order);
    static void onGetCreditByCardError(uint8_t statusCode);
    static void onGetCreditByCardSuccess(uint32_t credit, bool useRFIDForPayment);
    static void onUpdateCreditByCardError(uint8_t statusCode);
    static void onUpdateCreditByCardSuccess(uint32_t totalCredit, uint32_t diffCredit);
    static void onUpdateOrderError(uint8_t statusCode);
    static void onUpdateOrderSuccess(const Order& order);

    static void saveMoneyInsertedToOnlineCredit();
    static void uploadCurrentOrder();

    // Call vend on the next item
    // Returns false if nothing to vend
    static bool vendNextItem();

    static unsigned long lastChangeMillis;
    static bool active;
    static uint32_t cardNum;
    static Order currentOrder;

    static uint32_t moneyInsertedInMachine;
    static uint32_t onlineCredit;
    static bool useRFIDForPayment;
};