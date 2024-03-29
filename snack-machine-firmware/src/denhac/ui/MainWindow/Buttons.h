#pragma once

#include <Diablo_Serial_4DLib.h>

#include "ui/Button.h"

class BackButton : public Button {
  public:
    BackButton();
    void show();
    void hide();

    Diablo_Serial_4DLib* display;
    uint16_t left;
    uint16_t right;
    uint16_t top;
    uint16_t bottom;

  protected:
    bool inBounds(uint16_t x, uint16_t y);
};

class CellButton : public Button {
  public:
    CellButton();
    void show();

    Diablo_Serial_4DLib* display;
    char character;
    uint16_t left;
    uint16_t right;
    uint16_t top;
    uint16_t bottom;

  protected:
    bool inBounds(uint16_t x, uint16_t y);
};

class CancelOrderButton : public Button {
  public:
    CancelOrderButton();
    void show();

    Diablo_Serial_4DLib* display;
    uint16_t left;
    uint16_t right;
    uint16_t top;
    uint16_t bottom;

  protected:
    bool inBounds(uint16_t x, uint16_t y);
};

class AddItemButton : public Button {
  public:
    AddItemButton();
    void show();

    Diablo_Serial_4DLib* display;
    uint16_t left;
    uint16_t right;
    uint16_t top;
    uint16_t bottom;

  protected:
    bool inBounds(uint16_t x, uint16_t y);
};

class VendButton : public Button {
  public:
    VendButton();
    void show();

    Diablo_Serial_4DLib* display;
    uint16_t left;
    uint16_t right;
    uint16_t top;
    uint16_t bottom;

  protected:
    bool inBounds(uint16_t x, uint16_t y);
};

enum class MembershipButtonState {
  SCAN_CARD,
  PLEASE_WAIT,
  ORDER_AVAILALBLE,
  NO_ORDERS,
  UNKNOWN_CARD,
};

class MembershipButton : public Button {
  public:
    MembershipButton();
    void show();

    void setState(MembershipButtonState state);

    Diablo_Serial_4DLib* display;
    uint16_t left;
    uint16_t right;
    uint16_t top;
    uint16_t bottom;
  protected:
    bool inBounds(uint16_t x, uint16_t y);
    MembershipButtonState state;
};