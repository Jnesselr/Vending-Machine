#pragma once

typedef struct {
  uint64_t id;
  char name[52];
  uint32_t price;
  uint8_t stock_available;
  uint8_t stock_in_machine;
} Product;