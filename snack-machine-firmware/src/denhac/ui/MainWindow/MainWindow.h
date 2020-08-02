#pragma once

#include "ui/Window.h"
#include "ui/Button.h"

#include "denhac/ui/MainWindow/Buttons.h"

enum class MainWindowState {
  VEND_SCREEN,
  LETTERS_VISIBLE,
  NUMBERS_VISIBLE
};

class MainWindow : public Window {
  public:
    void show();
    void loop();
    void touch(uint8_t touchMode, uint16_t x, uint16_t y);

    // Public for callbacks
    void rowTapped(uint8_t row);
    void colTapped(uint8_t col);
    void back();
    void cancelOrder();
    void moneyAvailable(uint32_t amount);
    void addItemScreen();
  private:
    void setupMemberVariables();
    void drawGrid();
    void drawGridLetters();
    void drawGridNumbers();
    void drawCurrentCredit();
    void drawVendScreen();

    CellButton* rowButton(uint8_t row);
    CellButton* colButton(uint8_t col);

    void verifyGridValidity();

    void drawOrder();

    bool memberVariablesSet = false;
    bool gridRedrawNeeded = false;
    bool gridContentRedrawNeeded = false;
    bool orderContentRedrawNeeded = false;
    bool vendScreenRedrawNeeded = false;
    unsigned long lastGridValidityScan = 0;

    uint16_t screenWidth;
    uint16_t screenHeight;

    MainWindowState state;

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
};