#pragma once

#include <stdint.h>
#include "denhac/data/Order.h"

class Session {
  public:
    static void cardScanned(uint32_t);
    static bool isActive();

  private:
    static void onGetOrdersByCardError(uint8_t statusCode);
    static void onGetOrdersByCardSuccess(Order orders[], uint8_t numOrders);

    static unsigned long lastChangeMillis;
    static bool active;
    static uint32_t cardNum;
};