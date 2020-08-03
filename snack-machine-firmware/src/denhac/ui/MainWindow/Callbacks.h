#pragma once

#include "denhac/ui/MainWindow/MainWindow.h"

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