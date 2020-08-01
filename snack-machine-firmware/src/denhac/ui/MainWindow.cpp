#include "denhac/ui/MainWindow.h"

#include "ui/WindowManager.h"

#include "motors.h"
#include "utils.h"
#include <avr/wdt.h>

void MainWindow::show() {
  setupMemberVariables();

  display->gfx_BGcolour(WHITESMOKE);
  display->gfx_Cls();

  drawGrid();
  drawGridLetters();
  backButton.show();
}

void MainWindow::setupMemberVariables() {
  // We only need to do setup once
  if(memberVariablesSet) {
    return;
  }

  screenWidth = WindowManager::getWidth();
  screenHeight = WindowManager::getHeight();
  
  gridLeft = GRID_PADDING;
  gridRight = screenWidth - GRID_PADDING - 1;
  gridBottom = screenHeight - GRID_PADDING - 1;
  gridTop = gridBottom - 3 - (3 * CELL_HEIGHT);

  backButton.display = display;
  backButton.left = gridLeft + 1;
  backButton.right = backButton.left + CELL_WIDTH - 1;
  backButton.top = gridTop + 2 * CELL_HEIGHT + 3;
  backButton.bottom  = backButton.top + CELL_HEIGHT - 1;

  cellButtonA.display = display;
  cellButtonA.character = 'A';
  cellButtonA.left = gridLeft + 1;
  cellButtonA.right = cellButtonA.left + CELL_WIDTH - 1;
  cellButtonA.top = gridTop + 1;
  cellButtonA.bottom = cellButtonA.top + CELL_HEIGHT - 1;

  cellButtonB.display = display;
  cellButtonB.character = 'B';
  cellButtonB.left = gridLeft + CELL_WIDTH + 2;
  cellButtonB.right = cellButtonB.left + CELL_WIDTH - 1;
  cellButtonB.top = gridTop + 1;
  cellButtonB.bottom = cellButtonB.top + CELL_HEIGHT - 1;

  cellButtonC.display = display;
  cellButtonC.character = 'C';
  cellButtonC.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButtonC.right = cellButtonC.left + CELL_WIDTH - 1;
  cellButtonC.top = gridTop + 1;
  cellButtonC.bottom = cellButtonC.top + CELL_HEIGHT - 1;

  cellButtonD.display = display;
  cellButtonD.character = 'D';
  cellButtonD.left = gridLeft + 1;
  cellButtonD.right = cellButtonD.left + CELL_WIDTH - 1;
  cellButtonD.top = gridTop + CELL_HEIGHT + 2;
  cellButtonD.bottom = cellButtonD.top + CELL_HEIGHT - 1;

  cellButtonE.display = display;
  cellButtonE.character = 'E';
  cellButtonE.left = gridLeft + CELL_WIDTH + 2;
  cellButtonE.right = cellButtonE.left + CELL_WIDTH - 1;
  cellButtonE.top = gridTop + CELL_HEIGHT + 2;
  cellButtonE.bottom = cellButtonE.top + CELL_HEIGHT - 1;

  cellButtonF.display = display;
  cellButtonF.character = 'F';
  cellButtonF.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButtonF.right = cellButtonF.left + CELL_WIDTH - 1;
  cellButtonF.top = gridTop + CELL_HEIGHT + 2;
  cellButtonF.bottom = cellButtonF.top + CELL_HEIGHT - 1;

  cellButtonG.display = display;
  cellButtonG.character = 'G';
  cellButtonG.left = gridLeft + CELL_WIDTH + 2;
  cellButtonG.right = cellButtonG.left + CELL_WIDTH - 1;
  cellButtonG.top = gridTop + 2 * CELL_HEIGHT + 3;
  cellButtonG.bottom = cellButtonG.top + CELL_HEIGHT - 1;

  cellButtonH.display = display;
  cellButtonH.character = 'H';
  cellButtonH.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButtonH.right = cellButtonH.left + CELL_WIDTH - 1;
  cellButtonH.top = gridTop + 2 * CELL_HEIGHT + 3;
  cellButtonH.bottom = cellButtonH.top + CELL_HEIGHT - 1;

  cellButton1.display = display;
  cellButton1.character = '1';
  cellButton1.left = gridLeft + 1;
  cellButton1.right = cellButton1.left + CELL_WIDTH - 1;
  cellButton1.top = gridTop + 1;
  cellButton1.bottom = cellButton1.top + CELL_HEIGHT - 1;

  cellButton2.display = display;
  cellButton2.character = '2';
  cellButton2.left = gridLeft + CELL_WIDTH + 2;
  cellButton2.right = cellButton2.left + CELL_WIDTH - 1;
  cellButton2.top = gridTop + 1;
  cellButton2.bottom = cellButton2.top + CELL_HEIGHT - 1;

  cellButton3.display = display;
  cellButton3.character = '3';
  cellButton3.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButton3.right = cellButton3.left + CELL_WIDTH - 1;
  cellButton3.top = gridTop + 1;
  cellButton3.bottom = cellButton3.top + CELL_HEIGHT - 1;

  cellButton4.display = display;
  cellButton4.character = '4';
  cellButton4.left = gridLeft + 1;
  cellButton4.right = cellButton4.left + CELL_WIDTH - 1;
  cellButton4.top = gridTop + CELL_HEIGHT + 2;
  cellButton4.bottom = cellButton4.top + CELL_HEIGHT - 1;

  cellButton5.display = display;
  cellButton5.character = '5';
  cellButton5.left = gridLeft + CELL_WIDTH + 2;
  cellButton5.right = cellButton5.left + CELL_WIDTH - 1;
  cellButton5.top = gridTop + CELL_HEIGHT + 2;
  cellButton5.bottom = cellButton5.top + CELL_HEIGHT - 1;

  cellButton6.display = display;
  cellButton6.character = '6';
  cellButton6.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButton6.right = cellButton6.left + CELL_WIDTH - 1;
  cellButton6.top = gridTop + CELL_HEIGHT + 2;
  cellButton6.bottom = cellButton6.top + CELL_HEIGHT - 1;

  cellButton7.display = display;
  cellButton7.character = '7';
  cellButton7.left = gridLeft + CELL_WIDTH + 2;
  cellButton7.right = cellButton7.left + CELL_WIDTH - 1;
  cellButton7.top = gridTop + 2 * CELL_HEIGHT + 3;
  cellButton7.bottom = cellButton7.top + CELL_HEIGHT - 1;

  cellButton8.display = display;
  cellButton8.character = '8';
  cellButton8.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButton8.right = cellButton8.left + CELL_WIDTH - 1;
  cellButton8.top = gridTop + 2 * CELL_HEIGHT + 3;
  cellButton8.bottom = cellButton8.top + CELL_HEIGHT - 1;

  memberVariablesSet = true;
}

void MainWindow::loop() {
}

void MainWindow::touch(uint8_t touchMode, uint16_t x, uint16_t y) {
  backButton.touch(touchMode, x, y);

  if(state == MainWindowState::LETTERS_VISIBLE) {
    cellButtonA.touch(touchMode, x, y);
    cellButtonB.touch(touchMode, x, y);
    cellButtonC.touch(touchMode, x, y);
    cellButtonD.touch(touchMode, x, y);
    cellButtonE.touch(touchMode, x, y);
    cellButtonF.touch(touchMode, x, y);
    cellButtonG.touch(touchMode, x, y);
    cellButtonH.touch(touchMode, x, y);
  } else if(state == MainWindowState::NUMBERS_VISIBLE) {
    cellButton1.touch(touchMode, x, y);
    cellButton2.touch(touchMode, x, y);
    cellButton3.touch(touchMode, x, y);
    cellButton4.touch(touchMode, x, y);
    cellButton5.touch(touchMode, x, y);
    cellButton6.touch(touchMode, x, y);
    cellButton7.touch(touchMode, x, y);
    cellButton8.touch(touchMode, x, y);
  }
}

void MainWindow::drawGrid() {
  // Cells are 156 x 104 (3 x 2 multiple of 52)

  display->gfx_RectangleFilled(0, gridTop, screenWidth - 1, gridBottom, WHITESMOKE);

  // Outside Box
  display->gfx_Line(gridLeft, gridBottom, gridLeft, gridTop, BLACK);
  display->gfx_Line(gridLeft, gridTop, gridRight, gridTop, BLACK);
  display->gfx_Line(gridRight, gridBottom, gridRight, gridTop, BLACK);
  display->gfx_Line(gridLeft, gridBottom, gridRight, gridBottom, BLACK);

  // Columns
  uint16_t column = gridLeft + CELL_WIDTH + 1;
  display->gfx_Line(column, gridTop, column, gridBottom, BLACK);
  column = column + CELL_WIDTH + 1;
  display->gfx_Line(column, gridTop, column, gridBottom, BLACK);

  // Rows
  uint16_t row = gridTop + CELL_HEIGHT + 1;
  display->gfx_Line(gridLeft, row, gridRight, row, BLACK);
  row = row + CELL_HEIGHT + 1;
  display->gfx_Line(gridLeft, row, gridRight, row, BLACK);
}


void MainWindow::drawGridLetters() {
  cellButtonA.enabled = Motors::rowExists(0);
  cellButtonB.enabled = Motors::rowExists(1);
  cellButtonC.enabled = Motors::rowExists(2);
  cellButtonD.enabled = Motors::rowExists(3);
  cellButtonE.enabled = Motors::rowExists(4);
  cellButtonF.enabled = Motors::rowExists(5);
  cellButtonG.enabled = Motors::rowExists(6);
  cellButtonH.enabled = Motors::rowExists(7);

  cellButtonA.show();
  cellButtonB.show();
  cellButtonC.show();
  cellButtonD.show();
  cellButtonE.show();
  cellButtonF.show();
  cellButtonG.show();
  cellButtonH.show();
}

CellButton::CellButton() {
  display = nullptr;
  enabled = true;
  left = right = top = bottom = 0;
}

void CellButton::show() {
  display->txt_Width(8);
  display->txt_Height(8);

  word backgroundColor;
  if(enabled && pressed) {
    backgroundColor = DARKGRAY;
  } else {
    backgroundColor = WHITESMOKE;
  }
  display->txt_BGcolour(backgroundColor);
  display->gfx_RectangleFilled(left, top, right, bottom, backgroundColor);

  if(enabled && pressed) {
    display->txt_FGcolour(WHITE);
  } else if(enabled) {
    display->txt_FGcolour(BLACK);
  } else {
    display->txt_FGcolour(GRAY);
  }

  display->gfx_MoveTo(
    (left + right) / 2 - 56 / 2,
    (top + bottom) / 2 - 72 / 2 - 8
  );
  display->putCH(character);
}

bool CellButton::inBounds(uint16_t x, uint16_t y) {
  return x > left && x < right && y < bottom && y > top;
}

void BackButton::show() {
  word color = pressed ? DEEPSKYBLUE : LIGHTSKYBLUE;
  display->gfx_RectangleFilled(left, top, right, bottom, color);
}

bool BackButton::inBounds(uint16_t x, uint16_t y) {
  return x > left && x < right && y < bottom && y > top;
}