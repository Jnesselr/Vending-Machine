#pragma once

#include <stdint.h>

// Building blocks
constexpr uint8_t COMMAND_BYTE_BYTES = 1;
constexpr uint8_t ID_BYTES = 5;
constexpr uint8_t CARD_BYTES = 5;
constexpr uint8_t NUM_THINGS_BYTES = 1;
constexpr uint8_t STATUS_BYTES = 1;
constexpr uint8_t MONEY_BYTES = 5;

// Actual data
constexpr uint8_t PACKET_ORDERS_BY_CARD = COMMAND_BYTE_BYTES + CARD_BYTES + NUM_THINGS_BYTES;
constexpr uint8_t PACKET_ORDERS_BY_ID = COMMAND_BYTE_BYTES;
constexpr uint8_t PACKET_ORDER_HEADER = ID_BYTES + STATUS_BYTES + MONEY_BYTES + MONEY_BYTES + NUM_THINGS_BYTES;
constexpr uint8_t PACKET_ITEM = ID_BYTES + ID_BYTES + NUM_THINGS_BYTES + NUM_THINGS_BYTES;