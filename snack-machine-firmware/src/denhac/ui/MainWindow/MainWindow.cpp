#ifdef VENDING_MAIN_BOARD

#include "denhac/ui/MainWindow/MainWindow.h"
#include "denhac/ui/MainWindow/Callbacks.h"
#include "denhac/ProductManager.h"
#include "denhac/Session.h"

#include "ui/WindowManager.h"

#include "motors.h"
#include "utils.h"
#include <avr/wdt.h>

void MainWindow::show() {
  setupMemberVariables();

  display->gfx_BGcolour(WHITESMOKE);
  display->gfx_Cls();

  gridRedrawNeeded = true;

  StaticCallback<StaticCallbackType::MONEY_AVAILABLE, uint32_t>::mainWindow = this;
  Session::moneyAvailableCallback = StaticCallback<StaticCallbackType::MONEY_AVAILABLE, uint32_t>::callback;
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
  backButton.bottom = backButton.top + CELL_HEIGHT - 1;
  StaticCallback<StaticCallbackType::BACK>::mainWindow = this;
  backButton.tapped = StaticCallback<StaticCallbackType::BACK>::callback;

  cellButtonA.display = display;
  cellButtonA.character = 'A';
  cellButtonA.left = gridLeft + 1;
  cellButtonA.right = cellButtonA.left + CELL_WIDTH - 1;
  cellButtonA.top = gridTop + 1;
  cellButtonA.bottom = cellButtonA.top + CELL_HEIGHT - 1;
  RowCallback<0>::mainWindow = this;
  cellButtonA.tapped = RowCallback<0>::tapped;

  cellButtonB.display = display;
  cellButtonB.character = 'B';
  cellButtonB.left = gridLeft + CELL_WIDTH + 2;
  cellButtonB.right = cellButtonB.left + CELL_WIDTH - 1;
  cellButtonB.top = gridTop + 1;
  cellButtonB.bottom = cellButtonB.top + CELL_HEIGHT - 1;
  RowCallback<1>::mainWindow = this;
  cellButtonB.tapped = RowCallback<1>::tapped;

  cellButtonC.display = display;
  cellButtonC.character = 'C';
  cellButtonC.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButtonC.right = cellButtonC.left + CELL_WIDTH - 1;
  cellButtonC.top = gridTop + 1;
  cellButtonC.bottom = cellButtonC.top + CELL_HEIGHT - 1;
  RowCallback<2>::mainWindow = this;
  cellButtonC.tapped = RowCallback<2>::tapped;

  cellButtonD.display = display;
  cellButtonD.character = 'D';
  cellButtonD.left = gridLeft + 1;
  cellButtonD.right = cellButtonD.left + CELL_WIDTH - 1;
  cellButtonD.top = gridTop + CELL_HEIGHT + 2;
  cellButtonD.bottom = cellButtonD.top + CELL_HEIGHT - 1;
  RowCallback<3>::mainWindow = this;
  cellButtonD.tapped = RowCallback<3>::tapped;

  cellButtonE.display = display;
  cellButtonE.character = 'E';
  cellButtonE.left = gridLeft + CELL_WIDTH + 2;
  cellButtonE.right = cellButtonE.left + CELL_WIDTH - 1;
  cellButtonE.top = gridTop + CELL_HEIGHT + 2;
  cellButtonE.bottom = cellButtonE.top + CELL_HEIGHT - 1;
  RowCallback<4>::mainWindow = this;
  cellButtonE.tapped = RowCallback<4>::tapped;

  cellButtonF.display = display;
  cellButtonF.character = 'F';
  cellButtonF.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButtonF.right = cellButtonF.left + CELL_WIDTH - 1;
  cellButtonF.top = gridTop + CELL_HEIGHT + 2;
  cellButtonF.bottom = cellButtonF.top + CELL_HEIGHT - 1;
  RowCallback<5>::mainWindow = this;
  cellButtonF.tapped = RowCallback<5>::tapped;

  cellButtonG.display = display;
  cellButtonG.character = 'G';
  cellButtonG.left = gridLeft + CELL_WIDTH + 2;
  cellButtonG.right = cellButtonG.left + CELL_WIDTH - 1;
  cellButtonG.top = gridTop + 2 * CELL_HEIGHT + 3;
  cellButtonG.bottom = cellButtonG.top + CELL_HEIGHT - 1;
  RowCallback<6>::mainWindow = this;
  cellButtonG.tapped = RowCallback<6>::tapped;

  cellButtonH.display = display;
  cellButtonH.character = 'H';
  cellButtonH.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButtonH.right = cellButtonH.left + CELL_WIDTH - 1;
  cellButtonH.top = gridTop + 2 * CELL_HEIGHT + 3;
  cellButtonH.bottom = cellButtonH.top + CELL_HEIGHT - 1;
  RowCallback<7>::mainWindow = this;
  cellButtonH.tapped = RowCallback<7>::tapped;

  cellButton1.display = display;
  cellButton1.character = '1';
  cellButton1.left = gridLeft + 1;
  cellButton1.right = cellButton1.left + CELL_WIDTH - 1;
  cellButton1.top = gridTop + 1;
  cellButton1.bottom = cellButton1.top + CELL_HEIGHT - 1;
  ColCallback<0>::mainWindow = this;
  cellButton1.tapped = ColCallback<0>::tapped;

  cellButton2.display = display;
  cellButton2.character = '2';
  cellButton2.left = gridLeft + CELL_WIDTH + 2;
  cellButton2.right = cellButton2.left + CELL_WIDTH - 1;
  cellButton2.top = gridTop + 1;
  cellButton2.bottom = cellButton2.top + CELL_HEIGHT - 1;
  ColCallback<1>::mainWindow = this;
  cellButton2.tapped = ColCallback<1>::tapped;

  cellButton3.display = display;
  cellButton3.character = '3';
  cellButton3.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButton3.right = cellButton3.left + CELL_WIDTH - 1;
  cellButton3.top = gridTop + 1;
  cellButton3.bottom = cellButton3.top + CELL_HEIGHT - 1;
  ColCallback<2>::mainWindow = this;
  cellButton3.tapped = ColCallback<2>::tapped;

  cellButton4.display = display;
  cellButton4.character = '4';
  cellButton4.left = gridLeft + 1;
  cellButton4.right = cellButton4.left + CELL_WIDTH - 1;
  cellButton4.top = gridTop + CELL_HEIGHT + 2;
  cellButton4.bottom = cellButton4.top + CELL_HEIGHT - 1;
  ColCallback<3>::mainWindow = this;
  cellButton4.tapped = ColCallback<3>::tapped;

  cellButton5.display = display;
  cellButton5.character = '5';
  cellButton5.left = gridLeft + CELL_WIDTH + 2;
  cellButton5.right = cellButton5.left + CELL_WIDTH - 1;
  cellButton5.top = gridTop + CELL_HEIGHT + 2;
  cellButton5.bottom = cellButton5.top + CELL_HEIGHT - 1;
  ColCallback<4>::mainWindow = this;
  cellButton5.tapped = ColCallback<4>::tapped;

  cellButton6.display = display;
  cellButton6.character = '6';
  cellButton6.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButton6.right = cellButton6.left + CELL_WIDTH - 1;
  cellButton6.top = gridTop + CELL_HEIGHT + 2;
  cellButton6.bottom = cellButton6.top + CELL_HEIGHT - 1;
  ColCallback<5>::mainWindow = this;
  cellButton6.tapped = ColCallback<5>::tapped;

  cellButton7.display = display;
  cellButton7.character = '7';
  cellButton7.left = gridLeft + CELL_WIDTH + 2;
  cellButton7.right = cellButton7.left + CELL_WIDTH - 1;
  cellButton7.top = gridTop + 2 * CELL_HEIGHT + 3;
  cellButton7.bottom = cellButton7.top + CELL_HEIGHT - 1;
  ColCallback<6>::mainWindow = this;
  cellButton7.tapped = ColCallback<6>::tapped;

  cellButton8.display = display;
  cellButton8.character = '8';
  cellButton8.left = gridLeft + 2 * CELL_WIDTH + 3;
  cellButton8.right = cellButton8.left + CELL_WIDTH - 1;
  cellButton8.top = gridTop + 2 * CELL_HEIGHT + 3;
  cellButton8.bottom = cellButton8.top + CELL_HEIGHT - 1;
  ColCallback<7>::mainWindow = this;
  cellButton8.tapped = ColCallback<7>::tapped;

  cancelOrderButton.display = display;
  cancelOrderButton.enabled = false;
  cancelOrderButton.left = gridLeft;
  cancelOrderButton.right = 191;
  cancelOrderButton.bottom = gridBottom - CELL_HEIGHT - 6; // TODO This needs to be 4 spaces betwen vend button and here
  cancelOrderButton.top = cancelOrderButton.bottom - 74 - 7;
  StaticCallback<StaticCallbackType::CANCEL_ORDER>::mainWindow = this;
  cancelOrderButton.tapped = StaticCallback<StaticCallbackType::CANCEL_ORDER>::callback;

  state = MainWindowState::LETTERS_VISIBLE;
  memberVariablesSet = true;
}

void MainWindow::loop() {
  if(current_loop_millis > lastGridValidityScan + 200) {
    verifyGridValidity();
  }

  if(gridRedrawNeeded) {
    drawGrid();
    gridRedrawNeeded = false;
    gridContentRedrawNeeded = true;
  }

  if(gridContentRedrawNeeded) {
    if(state == MainWindowState::LETTERS_VISIBLE) {
      drawGridLetters();
      backButton.show();
    } else if(state == MainWindowState::NUMBERS_VISIBLE) {
      drawGridNumbers();
      backButton.show();
    }
    gridContentRedrawNeeded = false;
  }

  if(vendScreenRedrawNeeded) {
    drawVendScreen();
    vendScreenRedrawNeeded = false;
  }

  if(orderContentRedrawNeeded) {
    drawOrder();
    orderContentRedrawNeeded = false;
  }
}

void MainWindow::touch(uint8_t touchMode, uint16_t x, uint16_t y) {
  if(state == MainWindowState::VEND_SCREEN) {
    cancelOrderButton.touch(touchMode, x, y);
  } else if(state == MainWindowState::LETTERS_VISIBLE) {
    backButton.touch(touchMode, x, y);
    cellButtonA.touch(touchMode, x, y);
    cellButtonB.touch(touchMode, x, y);
    cellButtonC.touch(touchMode, x, y);
    cellButtonD.touch(touchMode, x, y);
    cellButtonE.touch(touchMode, x, y);
    cellButtonF.touch(touchMode, x, y);
    cellButtonG.touch(touchMode, x, y);
    cellButtonH.touch(touchMode, x, y);
  } else if(state == MainWindowState::NUMBERS_VISIBLE) {
    backButton.touch(touchMode, x, y);
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
  verifyGridValidity();
  cellButtonA.show();
  cellButtonB.show();
  cellButtonC.show();
  cellButtonD.show();
  cellButtonE.show();
  cellButtonF.show();
  cellButtonG.show();
  cellButtonH.show();
}

void MainWindow::drawGridNumbers() {
  verifyGridValidity();
  cellButton1.show();
  cellButton2.show();
  cellButton3.show();
  cellButton4.show();
  cellButton5.show();
  cellButton6.show();
  cellButton7.show();
  cellButton8.show();
}

void MainWindow::drawVendScreen() {
  display->gfx_RectangleFilled(0, gridTop, screenWidth - 1, gridBottom, WHITESMOKE);
  display->gfx_RectangleFilled(gridLeft, gridBottom - CELL_HEIGHT - 1, gridRight, gridBottom, LIGHTGREEN);
  display->gfx_RectangleFilled(gridLeft + 4, gridBottom - CELL_HEIGHT - 1 + 4, gridRight - 4, gridBottom - 4, WHITE);

  cancelOrderButton.show();
}

CellButton* MainWindow::rowButton(uint8_t row) {
  switch(row) {
    case 0: return &cellButtonA;
    case 1: return &cellButtonB;
    case 2: return &cellButtonC;
    case 3: return &cellButtonD;
    case 4: return &cellButtonE;
    case 5: return &cellButtonF;
    case 6: return &cellButtonG;
    case 7: return &cellButtonH;
    default: return nullptr;
  }
}

CellButton* MainWindow::colButton(uint8_t col) {
  switch(col) {
    case 0: return &cellButton1;
    case 1: return &cellButton2;
    case 2: return &cellButton3;
    case 3: return &cellButton4;
    case 4: return &cellButton5;
    case 5: return &cellButton6;
    case 6: return &cellButton7;
    case 7: return &cellButton8;
    default: return nullptr;
  }
}

void MainWindow::verifyGridValidity() {
  lastGridValidityScan = current_loop_millis;

  for (uint8_t i = 0; i < 8; i++)
  {
    CellButton* button = rowButton(i);
    bool isEnabled = button->enabled;
    bool shouldBeEnabled = Motors::rowExists(i) && ProductManager::isValid(i);
    if(isEnabled != shouldBeEnabled) {
      if(state == MainWindowState::NUMBERS_VISIBLE && selectedRow == i) {
        state = MainWindowState::LETTERS_VISIBLE;
        gridContentRedrawNeeded = true;
      } else if(state == MainWindowState::LETTERS_VISIBLE) {
        gridContentRedrawNeeded = true;
      }
    }

    button->enabled = shouldBeEnabled;
  }

  if(state != MainWindowState::NUMBERS_VISIBLE) {
    return;
  }

  for (uint8_t i = 0; i < 8; i++)
  {
    CellButton* button = colButton(i);
    bool isEnabled = button->enabled;
    bool shouldBeEnabled = Motors::exists(selectedRow, i) && ProductManager::isValid(selectedRow, i);
    if(isEnabled != shouldBeEnabled) {
      gridContentRedrawNeeded = true;
    }

    button->enabled = shouldBeEnabled;
  }
}

void MainWindow::drawOrder() {
  display->txt_Width(2);
  display->txt_Height(2);
  display->txt_FGcolour(BLACK);
  display->txt_BGcolour(WHITESMOKE);
  display->gfx_RectangleFilled(0, 0, screenWidth - 1, 300, WHITESMOKE);

  Order* order = Session::getCurrentOrder();

  uint16_t dollars = order->total / 100;
  uint8_t cents = order->total % 100;
  uint8_t dollarsWidth = (uint8_t) log10(dollars) + 1;
  // Max is 30 wide, 4 of those are $. and cents
  display->txt_MoveCursor(0, 26 - dollarsWidth);
  display->print('$');
  display->print(dollars);
  display->print('.');
  if(cents < 10) {
    display->print('0');
  }
  display->print(cents);

  for (uint8_t i = 0; i < order->getNumItems(); i++)
  {
    display->txt_MoveCursor(2 * i + 1, 0);
    Item item = order->getItem(i);
    Product product = ProductManager::get(item.productId);
    display->print(product.name);
    display->print(" => ");
    display->print(item.quantity);
  }
}

void MainWindow::drawCurrentCredit() {
  display->txt_Width(2);
  display->txt_Height(2);
  display->txt_FGcolour(BLACK);
  display->txt_BGcolour(WHITESMOKE);

  uint32_t credit = Session::getCurrentAvailableMoney();
  uint16_t dollars = credit / 100;
  uint8_t cents = credit % 100;
  display->txt_MoveCursor(0, 0);
  display->print('$');
  display->print(dollars);
  display->print('.');
  if(cents < 10) {
    display->print('0');
  }
  display->print(cents);
}

void MainWindow::back() {
  if(state == MainWindowState::LETTERS_VISIBLE) {
    state = MainWindowState::VEND_SCREEN;
    vendScreenRedrawNeeded = true;
  } else if(state == MainWindowState::NUMBERS_VISIBLE) {
    state = MainWindowState::LETTERS_VISIBLE;
    gridContentRedrawNeeded = true;
  }
}

void MainWindow::cancelOrder() {
  // TODO
}

void MainWindow::rowTapped(uint8_t row) {
  if(state == MainWindowState::LETTERS_VISIBLE) {
    selectedRow = row;
    state = MainWindowState::NUMBERS_VISIBLE;
    gridContentRedrawNeeded = true;
  }
}

void MainWindow::colTapped(uint8_t col) {
  if(state == MainWindowState::NUMBERS_VISIBLE) {
    Order* order = Session::getCurrentOrder();

    order->add(ProductManager::get(selectedRow, col));
    orderContentRedrawNeeded = true;

    state = MainWindowState::VEND_SCREEN;
    vendScreenRedrawNeeded = true;
  }
}

void MainWindow::moneyAvailable(uint32_t amount) {
  drawCurrentCredit();

  if(!cancelOrderButton.enabled &&
    state == MainWindowState::VEND_SCREEN) {
    cancelOrderButton.enabled = true;
    cancelOrderButton.show(); // Redraw since it's available now
  }
}

#endif