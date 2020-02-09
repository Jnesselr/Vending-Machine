#pragma once

typedef void (*void_ptr)();

class VendingMachine {
  public:
    static void (*setup)();
    static void (*loop)();
};