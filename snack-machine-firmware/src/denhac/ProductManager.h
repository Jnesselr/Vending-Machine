#pragma once

#include "denhac/data/Product.h"

typedef union {
  uint32_t longValue;
  uint8_t shortValues[4];
} LongUnion;

class ProductManager {
  public:
    static bool hasStockAvailable(uint8_t row);
    static bool hasStockAvailable(uint8_t row, uint8_t col);
    static bool isValid(uint8_t row);
    static bool isValid(uint8_t row, uint8_t col);
    static Product get(uint8_t row, uint8_t col);
    static Product get(uint32_t productId);

    static void productUpdated(const Product& product);
    static void productRemoved(uint8_t row, uint8_t col);
    static void reduceStock(uint8_t row, uint8_t col);
  private:
    static void writeLong(uint16_t address, uint32_t value);
    static void writeBytes(uint16_t startAddress, uint8_t* value, size_t length);

    static uint32_t readLong(uint16_t address);
    static void readBytes(uint16_t startAddress, uint8_t* value, size_t length);
};