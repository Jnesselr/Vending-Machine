#ifdef VENDING_MAIN_BOARD

#include "denhac/ui/MainWindow/MainWindow.h"
#include "denhac/ui/MainWindow/Callbacks.h"
#include "denhac/ProductManager.h"
#include "denhac/Session.h"

#include "ui/WindowManager.h"

#include "motors.h"
#include "utils.h"
#include <avr/wdt.h>

template<StaticCallbackType type, typename... Args>
MainWindow* StaticCallback<type, Args...>::mainWindow = nullptr;
template<StaticCallbackType type, typename... Args>
WindowCallback<Args...> StaticCallback<type, Args...>::windowCallback = nullptr;

#define CALL_ON_BUTTONS(function_call) \
if(state == MainWindowState::VEND_SCREEN) { \
    cancelOrderButton.function_call; \
    membershipButton.function_call; \
    addItemButton.function_call; \
    vendButton.function_call; \
  } else if(state == MainWindowState::LETTERS_VISIBLE) { \
    backButton.function_call; \
    cellButtonA.function_call; \
    cellButtonB.function_call; \
    cellButtonC.function_call; \
    cellButtonD.function_call; \
    cellButtonE.function_call; \
    cellButtonF.function_call; \
    cellButtonG.function_call; \
    cellButtonH.function_call; \
  } else if(state == MainWindowState::NUMBERS_VISIBLE) { \
    backButton.function_call; \
    cellButton1.function_call; \
    cellButton2.function_call; \
    cellButton3.function_call; \
    cellButton4.function_call; \
    cellButton5.function_call; \
    cellButton6.function_call; \
    cellButton7.function_call; \
    cellButton8.function_call; \
  }

void MainWindow::show() {
  setupMemberVariables();

  display->gfx_BGcolour(WHITESMOKE);
  display->gfx_Cls();

  state = MainWindowState::LETTERS_VISIBLE;
  oldLoopState = MainWindowState::VEND_SCREEN; // Technically not true, but it redraws the grid this way

  drawCurrentCredit();
  drawOrder();

  Session::moneyAvailableCallback = callback<StaticCallbackType::MONEY_AVAILABLE, uint32_t>(moneyAvailable);
  Session::onCustomerLookupStarted = callback<StaticCallbackType::CUSTOMER_LOOKUP_STARTED>(customerLookupStarted);
  Session::onOrdersRetrieved = callback<StaticCallbackType::ORDERS_RETRIEVED>(ordersRetrieved);
  Session::onUnknownCard = callback<StaticCallbackType::UNKNOWN_CARD>(unknownCard);
  Session::onReset = callback<StaticCallbackType::SESSION_RESET>(sessionReset);
  Session::onCurrentOrderUpdated = callback<StaticCallbackType::CURRENT_ORDER_UPDATED>(currentOrderUpdated);
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
  backButton.tapped = callback<StaticCallbackType::BACK>(back);

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

  vendButton.display = display;
  vendButton.left = gridLeft;
  vendButton.right = gridRight;
  vendButton.bottom = gridBottom;
  vendButton.top = vendButton.bottom - CELL_HEIGHT - 7;
  vendButton.tapped = callback<StaticCallbackType::VEND>(vend);
  vendButton.disable();

  cancelOrderButton.display = display;
  cancelOrderButton.left = gridLeft;
  cancelOrderButton.right = 193;
  cancelOrderButton.bottom = vendButton.top - 5;
  cancelOrderButton.top = cancelOrderButton.bottom - 74 - 7;
  cancelOrderButton.tapped = callback<StaticCallbackType::CANCEL_ORDER>(cancelOrder);
  cancelOrderButton.disable();

  addItemButton.display = display;
  addItemButton.left = gridRight - 105;
  addItemButton.right = gridRight;
  addItemButton.bottom = vendButton.top - 5;
  addItemButton.top = addItemButton.bottom - 74 - 7;
  addItemButton.tapped = callback<StaticCallbackType::ADD_ITEM>(addItemScreen);

  membershipButton.display = display;
  membershipButton.left = cancelOrderButton.right + 5;
  membershipButton.right = addItemButton.left - 5;
  membershipButton.bottom = vendButton.top - 5;
  membershipButton.top = addItemButton.top;
  membershipButton.tapped = callback<StaticCallbackType::MEMBERSHIP_BUTTON_TAPPED>(membershipButtonTapped);
  membershipButton.disable();

  memberVariablesSet = true;
}

void MainWindow::loop() {
  if(current_loop_millis > lastGridValidityScan + 200) {
    verifyGridValidity();
  }

  if(state.gridIsShown() && !oldLoopState.gridIsShown()) {
    drawGrid();
    verifyGridValidity();
  } else if(!state.gridIsShown() && oldLoopState.gridIsShown()) {
    // Currently only the VEND_SCREEN
    display->gfx_RectangleFilled(0, gridTop, screenWidth - 1, gridBottom, WHITESMOKE);
  }

  CALL_ON_BUTTONS(show())

  oldLoopState = state;
}

void MainWindow::touch(uint8_t touchMode, uint16_t x, uint16_t y) {
  CALL_ON_BUTTONS(touch(touchMode, x, y))
}

void MainWindow::setState(MainWindowState state) {
  if(this->state != state) {
    this->state = state;
    CALL_ON_BUTTONS(forceRedrawNeeded())
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
    bool isEnabled = button->isEnabled();
    bool shouldBeEnabled = Motors::rowExists(i) && ProductManager::isValid(i);

    if(isEnabled != shouldBeEnabled) {
      if(state == MainWindowState::NUMBERS_VISIBLE && selectedRow == i) {
        setState(MainWindowState::LETTERS_VISIBLE);
      }
    }

    button->setEnabled(shouldBeEnabled);
  }

  if(state != MainWindowState::NUMBERS_VISIBLE) {
    return;
  }

  for (uint8_t i = 0; i < 8; i++)
  {
    CellButton* button = colButton(i);
    bool shouldBeEnabled = Motors::exists(selectedRow, i) && ProductManager::isValid(selectedRow, i);
    button->setEnabled(shouldBeEnabled);
  }
}

void MainWindow::drawOrder() {
  display->txt_Width(2);
  display->txt_Height(2);
  display->txt_FGcolour(BLACK);
  display->txt_BGcolour(WHITESMOKE);
  display->gfx_RectangleFilled(0, 24, screenWidth - 1, 300, WHITESMOKE);

  Order* order = Session::getCurrentOrder();

  uint16_t dollars = order->total / 100;
  uint8_t cents = order->total % 100;
  uint8_t dollarsWidth = (uint8_t) log10(dollars) + 1;
  // Max is 30 wide, 4 of those are $. and cents. 2 of those are spaces
  display->txt_MoveCursor(0, 24 - dollarsWidth);
  display->print("  ");
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
  display->print("  ");
}

void MainWindow::handleVendEnabled() {
  Order* order = Session::getCurrentOrder();

  if(order->status == OrderStatus::PROCESSING) {
    vendButton.enable();
    return;
  }

  if(order->getNumItems() == 0) {
    return;
  }

  uint32_t total = order->total;
  uint32_t paid = order->paid;
  uint32_t remaining = total - paid;

  if(Session::getCurrentAvailableMoney() >= remaining) {
    vendButton.enable();
  } else {
    vendButton.disable();
  }
}

template<StaticCallbackType type, typename... Args>
VariableCallback<Args...> MainWindow::callback(VariableCallback<MainWindow*, Args...> function) {
  StaticCallback<type, Args...>::mainWindow = this;
  StaticCallback<type, Args...>::windowCallback = function;
  return StaticCallback<type, Args...>::callback;
}

template<StaticCallbackType type, typename... Args>
void StaticCallback<type, Args...>::callback(Args... args) {
  windowCallback(mainWindow, args...);
}

void MainWindow::back(MainWindow* mainWindow) {
  if(mainWindow->state == MainWindowState::LETTERS_VISIBLE) {
    mainWindow->setState(MainWindowState::VEND_SCREEN);
  } else if(mainWindow->state == MainWindowState::NUMBERS_VISIBLE) {
    mainWindow->setState(MainWindowState::LETTERS_VISIBLE);
    mainWindow->verifyGridValidity();
  }
}

void MainWindow::cancelOrder(MainWindow* mainWindow) {
  Session::reset();
  mainWindow->drawOrder();
}

void MainWindow::vend(MainWindow* mainWindow) {
  mainWindow->vendButton.disable();
  mainWindow->cancelOrderButton.disable();

  Session::vend();
}

void MainWindow::rowTapped(uint8_t row) {
  if(state == MainWindowState::LETTERS_VISIBLE) {
    selectedRow = row;
    setState(MainWindowState::NUMBERS_VISIBLE);
    verifyGridValidity();
  }
}

void MainWindow::colTapped(uint8_t col) {
  if(state == MainWindowState::NUMBERS_VISIBLE) {
    Session::addToCurrentOrder(selectedRow, col);

    setState(MainWindowState::VEND_SCREEN);
    cancelOrderButton.enable();
  }
}

void MainWindow::moneyAvailable(MainWindow* mainWindow, uint32_t amount) {
  mainWindow->drawCurrentCredit();

  if(amount == 0) {
    return;
  }

  mainWindow->cancelOrderButton.enable();
  mainWindow->handleVendEnabled();
}

void MainWindow::addItemScreen(MainWindow* mainWindow) {
  mainWindow->setState(MainWindowState::LETTERS_VISIBLE);
}

void MainWindow::customerLookupStarted(MainWindow* mainWindow) {
  mainWindow->membershipButton.setState(MembershipButtonState::PLEASE_WAIT);
  mainWindow->membershipButton.disable();
  mainWindow->setState(MainWindowState::VEND_SCREEN);
}

void MainWindow::ordersRetrieved(MainWindow* mainWindow) {
  mainWindow->membershipButton.setState(MembershipButtonState::NUM_ORDERS);
}

void MainWindow::unknownCard(MainWindow* mainWindow) {
  mainWindow->membershipButton.setState(MembershipButtonState::UNKNOWN_CARD);
}

void MainWindow::sessionReset(MainWindow* mainWindow) {
  mainWindow->membershipButton.setState(MembershipButtonState::SCAN_CARD);
  mainWindow->membershipButton.disable();
  mainWindow->cancelOrderButton.disable();
  mainWindow->vendButton.disable();
  mainWindow->addItemButton.enable();
}

void MainWindow::membershipButtonTapped(MainWindow* mainWindow) {
  if(Session::getNumOrders() > 0) {
    Session::setCurrentOrderNum(0);
  }

  // TODO What if the order count isn't 1?
}

void MainWindow::currentOrderUpdated(MainWindow* mainWindow) {
  mainWindow->drawOrder();
  mainWindow->handleVendEnabled();

  Order* order = Session::getCurrentOrder();

  if(order->getNumItems() > 0) {
    mainWindow->cancelOrderButton.enable();
    if(order->status == OrderStatus::PROCESSING) {
      mainWindow->addItemButton.disable();
    }
  }
}

#endif