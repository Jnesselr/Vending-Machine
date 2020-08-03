#pragma once

enum class OrderStatus {
  UNKNOWN = 0x00,
  PENDING = 0x01,
  PROCESSING = 0x02,
  ON_HOLD = 0x03,
  COMPLETED = 0x04,
  CANCELLED = 0x05,
  REFUNDED = 0x06,
  FAILED = 0x07
};