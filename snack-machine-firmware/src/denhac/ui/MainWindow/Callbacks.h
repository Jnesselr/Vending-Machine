#pragma once

#include "denhac/ui/MainWindow/MainWindow.h"

enum class StaticCallbackType {
  BACK,
  CANCEL_ORDER,
  MONEY_AVAILABLE,
  ADD_ITEM,
  CUSTOMER_LOOKUP_STARTED,
  ORDERS_RETRIEVED,
  SESSION_RESET,
};

template<StaticCallbackType type, typename... Args>
struct StaticCallback {
  static MainWindow* mainWindow;
  static void callback(Args...);
};

template<uint8_t row>
struct RowCallback {
  static MainWindow* mainWindow;
  static void tapped();
};

template<uint8_t row>
struct ColCallback {
  static MainWindow* mainWindow;
  static void tapped();
};