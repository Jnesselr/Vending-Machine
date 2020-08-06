#pragma once

#include "ui/Window.h"
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

enum class StaticCallbackType {
  BACK,
  CANCEL_ORDER,
  MONEY_AVAILABLE,
  ADD_ITEM,
  VEND,
  CUSTOMER_LOOKUP_STARTED,
  ORDERS_RETRIEVED,
  SESSION_RESET,
  MEMBERSHIP_BUTTON_TAPPED,
  CURRENT_ORDER_UPDATED,
  UNKNOWN_CARD,
};

template<typename... Args>
using VariableCallback = void (*)(Args... args);

class MainWindow : public Window {
  public:
    void show();
    void loop();
    void touch(uint8_t touchMode, uint16_t x, uint16_t y);

    // Public for callbacks
    void rowTapped(uint8_t row);
    void colTapped(uint8_t col);
  private:
    template<StaticCallbackType type, typename... Args>
    VariableCallback<Args...> callback(VariableCallback<MainWindow*, Args...> function);

    static void back(MainWindow*);
    static void moneyAvailable(MainWindow*, uint32_t amount);
    static void sessionReset(MainWindow*);
    static void customerLookupStarted(MainWindow*);
    static void ordersRetrieved(MainWindow*);
    static void unknownCard(MainWindow*);
    static void currentOrderUpdated(MainWindow*);
    static void cancelOrder(MainWindow*);
    static void addItemScreen(MainWindow*);
    static void membershipButtonTapped(MainWindow*);
    static void vend(MainWindow*);

    void setupMemberVariables();
    void drawGrid();
    void drawCurrentCredit();
    void drawOrder();

    CellButton* rowButton(uint8_t row);
    CellButton* colButton(uint8_t col);

    void verifyGridValidity();
    void handleVendEnabled();

    bool memberVariablesSet = false;
    unsigned long lastGridValidityScan = 0;

    uint16_t screenWidth;
    uint16_t screenHeight;

    void setState(MainWindowState state);
    MainWindowState state;
    MainWindowState oldLoopState;

    const uint8_t CELL_WIDTH = 156;
    const uint8_t CELL_HEIGHT = 104;
    const uint16_t GRID_PADDING = 4;
    uint16_t gridLeft;
    uint16_t gridRight;
    uint16_t gridBottom;
    uint16_t gridTop;

    uint8_t selectedRow;

    BackButton backButton;

    CellButton cellButtonA;
    CellButton cellButtonB;
    CellButton cellButtonC;
    CellButton cellButtonD;
    CellButton cellButtonE;
    CellButton cellButtonF;
    CellButton cellButtonG;
    CellButton cellButtonH;
    CellButton cellButton1;
    CellButton cellButton2;
    CellButton cellButton3;
    CellButton cellButton4;
    CellButton cellButton5;
    CellButton cellButton6;
    CellButton cellButton7;
    CellButton cellButton8;

    CancelOrderButton cancelOrderButton;
    AddItemButton addItemButton;
    VendButton vendButton;
    MembershipButton membershipButton;
};

template<typename... Args>
using WindowCallback = void (*)(MainWindow*, Args...);

template<StaticCallbackType type, typename... Args>
struct StaticCallback {
  static MainWindow* mainWindow;
  static WindowCallback<Args...> windowCallback;
  static void callback(Args...);
};