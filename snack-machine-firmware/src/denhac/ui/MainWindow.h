#pragma once

#include "ui/Window.h"
#include "ui/Button.h"

class CellButton : public Button {
  public:
    CellButton();
    void show();
    void hide();

    Diablo_Serial_4DLib* display;
    char character;
    bool enabled;
    uint16_t left;
    uint16_t right;
    uint16_t top;
    uint16_t bottom;
};

class MainWindow : public Window {
  public:
    void show();
    void loop();
    void touch(uint8_t touchMode, uint16_t x, uint16_t y);
  private:
    void setupMemberVariables();
    void drawGrid();
    void drawGridBackArrow(bool pressed);
    void drawGridLetters();

    bool memberVariablesSet = false;

    uint16_t screenWidth;
    uint16_t screenHeight;

    const uint8_t CELL_WIDTH = 156;
    const uint8_t CELL_HEIGHT = 104;
    const uint16_t GRID_PADDING = 4;
    uint16_t gridLeft;
    uint16_t gridRight;
    uint16_t gridBottom;
    uint16_t gridTop;

    // BackButton backButton;

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
};