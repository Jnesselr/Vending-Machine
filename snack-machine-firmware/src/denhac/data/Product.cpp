#ifdef VENDING_MAIN_BOARD

#include "denhac/data/Product.h"

Product::Product() {
  id = 0;
  memset(name, 0, sizeof(name));
  price = 0;
  stockAvailable = 0;
  stockInMachine = 0;
  row = 0;
  col = 0;
  valid = true;
}

Product::Product(
  uint32_t id,
  char name[51],
  uint32_t price,
  uint8_t stockAvailable,
  uint8_t stockInMachine,
  uint8_t row,
  uint8_t col
) {
  this->id = id;
  this->price = price;
  this->stockAvailable = stockAvailable;
  this->stockInMachine = stockInMachine;
  this->row = row;
  this->col = col;
  this->valid = true;

  memcpy(this->name, name, sizeof(this->name));
}

Product::Product(const Product& product) {
  this->id = product.id;
  this->price = product.price;
  this->stockAvailable = product.stockAvailable;
  this->stockInMachine = product.stockInMachine;
  this->row = product.row;
  this->col = product.col;
  this->valid = product.valid;

  memcpy(this->name, product.name, sizeof(product.name));
}

void Product::operator=(const Product& product) {
  this->id = product.id;
  this->price = product.price;
  this->stockAvailable = product.stockAvailable;
  this->stockInMachine = product.stockInMachine;
  this->row = product.row;
  this->col = product.col;
  this->valid = product.valid;

  memcpy(this->name, product.name, sizeof(product.name));
}

#endif