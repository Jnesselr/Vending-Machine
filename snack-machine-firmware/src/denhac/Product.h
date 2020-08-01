#pragma once

#include "Arduino.h"

class Product {
  public:
    Product();
    Product(
      uint32_t id,
      char name[51],
      uint32_t price,
      uint8_t stockAvailable,
      uint8_t stockInMachine,
      uint8_t row,
      uint8_t col
    );
    Product(const Product& product);

    void operator = (const Product&);

    uint32_t id;
    char name[51];
    uint32_t price;
    uint8_t stockAvailable;
    uint8_t stockInMachine;
    uint8_t row;
    uint8_t col;
};