#pragma once

#include "ui/Button.h"

#include "denhac/ui/MainWindow/Buttons.h"

class MainWindowState
{
  public:
    enum Value : uint8_t
    {
      VEND_SCREEN,
      LETTERS_VISIBLE,
      NUMBERS_VISIBLE
    };

    MainWindowState() = default;
    constexpr MainWindowState(Value state) : value(state) { }

    constexpr bool operator==(MainWindowState a) const { return value == a.value; }
    constexpr bool operator!=(MainWindowState a) const { return value != a.value; }

    constexpr bool gridIsShown() const { return value == LETTERS_VISIBLE || value == NUMBERS_VISIBLE; }
  private:
    Value value;
};

class MainWindow {
public:
  static void setup();
  static void loop();
  static void teardown() {};
  static void touch(uint8_t touchMode, uint16_t x, uint16_t y);
private:
  static Diablo_Serial_4DLib* display;

  template <uint8_t row>
  static void rowTapped();
  template <uint8_t col>
  static void colTapped();

  static void back();
  static void moneyAvailable(uint32_t amount);
  static void sessionReset();
  static void customerLookupStarted();
  static void ordersRetrieved();
  static void noOrders();
  static void unknownCard();
  static void currentOrderUpdated();
  static void cancelOrder();
  static void addItemScreen();
  static void membershipButtonTapped();
  static void vend();

  static void setupMemberVariables();
  static void drawGrid();
  static void drawOrder();
  static void drawCredit();
  static void drawMoney(uint32_t money);
  static uint8_t moneyCharacterWidth(uint32_t money);

  static CellButton* rowButton(uint8_t row);
  static CellButton* colButton(uint8_t col);

  static void verifyRowsValidity();
  static void verifyColsValidity();
  static void handleVendEnabled();

  static uint16_t screenWidth;
  static uint16_t screenHeight;

  static void setState(MainWindowState state);
  static MainWindowState state;
  static MainWindowState oldLoopState;

  static const uint8_t CELL_WIDTH = 156;
  static const uint8_t CELL_HEIGHT = 104;
  static const uint16_t GRID_PADDING = 4;
  static uint16_t gridLeft;
  static uint16_t gridRight;
  static uint16_t gridBottom;
  static uint16_t gridTop;

  static uint8_t selectedRow;

  static BackButton backButton;

  static CellButton cellButtonA;
  static CellButton cellButtonB;
  static CellButton cellButtonC;
  static CellButton cellButtonD;
  static CellButton cellButtonE;
  static CellButton cellButtonF;
  static CellButton cellButtonG;
  static CellButton cellButtonH;
  static CellButton cellButton1;
  static CellButton cellButton2;
  static CellButton cellButton3;
  static CellButton cellButton4;
  static CellButton cellButton5;
  static CellButton cellButton6;
  static CellButton cellButton7;
  static CellButton cellButton8;

  static CancelOrderButton cancelOrderButton;
  static AddItemButton addItemButton;
  static VendButton vendButton;
  static MembershipButton membershipButton;
};