#ifndef _VENDING_MACHINE_H_
#define _VENDING_MACHINE_H_

typedef void (*void_ptr)();

class VendingMachine {
  public:
    static void (*setup)();
    static void (*loop)();
};

#endif