#ifdef VENDING_MAIN_BOARD

#include "denhac/ProductManager.h"

#include <EEPROM.h>

/**
 * Products are stored in EEPROM to handle network connectivity
 * issues and also mostly because we have nowhere else to put it
 * in an atmega2560 that's large enough.
 * 
 * Each product is stored in EEPROM like this:
 * uint8_t flag == 0xAA if product is there and valid
 * uint32_t id
 * char name[51]
 * uint32_t price
 * uint8_t stockAvailable
 * uint8_t stockInMachine
 * 
 * To find a particular product, it's start address is 62 * (8 * row + col)
 */

bool ProductManager::isValid(uint8_t row) {
  return isValid(row, 0) ||
        isValid(row, 1) ||
        isValid(row, 2) ||
        isValid(row, 3) ||
        isValid(row, 4) ||
        isValid(row, 5) ||
        isValid(row, 6) ||
        isValid(row, 7);
}

bool ProductManager::isValid(uint8_t row, uint8_t col) {
  uint16_t address = 62 * (8 * row + col);

  return EEPROM.read(address) == 0xAA &&
    EEPROM.read(address + 60) > 0;
}

Product ProductManager::get(uint8_t row, uint8_t col) {
  uint16_t startAddress = 62 * (8 * row + col);

  // TODO Handle invalid product
  Product product;

  product.id = readLong(startAddress + 1);
  readBytes(startAddress + 5, (uint8_t*) product.name, 51);
  product.price = readLong(startAddress + 56);
  product.stockAvailable = EEPROM.read(startAddress + 60);
  product.stockInMachine = EEPROM.read(startAddress + 61);
  product.row = row;
  product.col = col;

  return product;
}

Product ProductManager::get(uint32_t productId) {
  Product product;

  for (uint8_t row = 0; row < 8; row++)
  {
    for (uint8_t col = 0; col < 8; col++)
    {
      if(isValid(row, col)) {
        product = get(row, col);
        if(product.id == productId) {
          return product;
        }
      }
    }
  }

  // TODO Handle invalid product
  return Product();
}

void ProductManager::productUpdated(const Product& product) {
  uint16_t startAddress = 62 * (8 * product.row + product.col);

  EEPROM.update(startAddress, 0xAA);
  writeLong(startAddress + 1, product.id);
  writeBytes(startAddress + 5, (uint8_t*) product.name, 51);
  writeLong(startAddress + 56, product.price);
  EEPROM.update(startAddress + 60, product.stockAvailable);
  EEPROM.update(startAddress + 61, product.stockInMachine);
}

void ProductManager::productRemoved(uint8_t row, uint8_t col) {
  uint16_t address = 62 * (8 * row + col);

  // Invalidate the flag but don't overwite anything else to save
  // on EEPROM writes
  EEPROM.update(address, 0xFF);
}

void ProductManager::writeLong(uint16_t address, uint32_t value) {
  LongUnion unionValue;
  unionValue.longValue = value;

  writeBytes(address, unionValue.shortValues, sizeof(unionValue.shortValues));
}

/**
 * There's a potential race condition where the stock is physically
 * vended from the machine but we haven't gotten the website update yet.
 * In that time span, someone can try to vend more than the items we have
 * on hand, so we reduce stock manually and the update from the server should
 * match the reduced value so no EEPROM write needs to happen then.
 */
void ProductManager::reduceStock(uint8_t row, uint8_t col) {
  uint16_t address = 62 * (8 * row + col) + 61;

  uint8_t stockInMachine = EEPROM.read(address);
  EEPROM.write(address, stockInMachine - 1);
}

void ProductManager::writeBytes(
  uint16_t startAddress,
  uint8_t* value,
  size_t length) {
  for (size_t i = 0; i < length; i++)
  {
    EEPROM.update(startAddress + i, value[i]);
  }
}

uint32_t ProductManager::readLong(uint16_t address) {
  LongUnion unionValue;

  readBytes(address, unionValue.shortValues, sizeof(unionValue.shortValues));

  return unionValue.longValue;
}

void ProductManager::readBytes(
  uint16_t startAddress,
  uint8_t* value,
  size_t length) {
  for (size_t i = 0; i < length; i++)
  {
    value[i] = EEPROM.read(startAddress + i);
  }
}

#endif