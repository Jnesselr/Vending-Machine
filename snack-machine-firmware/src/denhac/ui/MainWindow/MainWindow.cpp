#ifdef VENDING_MAIN_BOARD

#include "denhac/ui/MainWindow/MainWindow.h"
#include "denhac/ui/MainWindow/Callbacks.h"
#include "denhac/ProductManager.h"
#include "denhac/Session.h"

#include "ui/WindowManager.h"

#include "motors.h"
#include "utils.h"
#include <avr/wdt.h>
#include <EEPROM.h>

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

  drawOrder();

  Session::moneyAvailableCallback = callback<StaticCallbackType::MONEY_AVAILABLE, uint32_t>(moneyAvailable);
  Session::onCustomerLookupStarted = callback<StaticCallbackType::CUSTOMER_LOOKUP_STARTED>(customerLookupStarted);
  Session::onOrdersRetrieved = callback<StaticCallbackType::ORDERS_RETRIEVED>(ordersRetrieved);
  Session::onNoOrders = callback<StaticCallbackType::ORDERS_RETRIEVED>(noOrders);
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
  // This avoids the unsigned long rollover bug
  if(current_loop_millis > 4000000000ul) {
    // TOOD Check if session is active
    while(true); // Force a reset with watchdog
  }

  if(current_loop_millis > lastGridValidityScan + 200) {
    verifyGridValidity();
  }

  if(state.gridIsShown() && !oldLoopState.gridIsShown()) {
    drawGrid();
    verifyGridValidity();
  } else if(!state.gridIsShown() && oldLoopState.gridIsShown()) {
    // Currently only the VEND_SCREEN
    display->gfx_RectangleFilled(0, cancelOrderButton.top - 4, screenWidth - 1, gridBottom, WHITESMOKE);
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

  // TODO Maybe add a "couldAddItem" and "couldAddRow" to Session that also takes into account current orer items
  for (uint8_t i = 0; i < 8; i++)
  {
    CellButton* button = rowButton(i);
    bool isEnabled = button->isEnabled();
    bool shouldBeEnabled = Motors::rowExists(i) && ProductManager::hasStockAvailable(i);

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
    bool shouldBeEnabled = Motors::exists(selectedRow, i) && ProductManager::hasStockAvailable(selectedRow, i);
    button->setEnabled(shouldBeEnabled);
  }
}

void MainWindow::drawOrder() {
  Order* order = Session::getCurrentOrder();

  Serial.println("Draw order!");
  display->txt_FGcolour(BLACK);
  display->txt_BGcolour(WHITESMOKE);
  
  // This section allows us to draw the whole list of items but not overwrite letters/numbers
  if(state == MainWindowState::LETTERS_VISIBLE || state == MainWindowState::NUMBERS_VISIBLE) {
    display->gfx_ClipWindow(0, 0, screenWidth - 1, gridTop - 5);
    display->gfx_Clipping(1);
  } else {
    display->gfx_Clipping(0);
  }

  uint16_t orderDrawBottom = cancelOrderButton.top - 4;
  // - 3 is height of drawn bar. -48 is 2x 32 height text. -16 is spacing above, below, and between text
  uint16_t totalsDrawTop = orderDrawBottom - 3 - (2 * 32) - 16;

  display->gfx_RectangleFilled(0, 0, screenWidth - 1, orderDrawBottom - 1, WHITESMOKE);

  // Draw totals and credit at a larger font size
  display->txt_Width(3);
  display->txt_Height(3);

  // Draw credit
  drawCredit();

  display->gfx_MoveTo(8, totalsDrawTop + 44);
  display->putstr((char*) "Total");
  uint16_t totalWidth = 24 * moneyCharacterWidth(order->total);
  display->gfx_MoveTo(screenWidth - totalWidth - 8, totalsDrawTop + 44);
  drawMoney(order->total);

  display->gfx_RectangleFilled(4, orderDrawBottom - 3, screenWidth - 5, orderDrawBottom - 1, GRAY);
  display->gfx_RectangleFilled(4, totalsDrawTop - 3, screenWidth - 5, totalsDrawTop - 1, GRAY);

  // 2 characters on the left at 16 px wide each. We're drawing in the space after that.
  // Which means we're drawing between 32 and 47 inclusive.
  display->gfx_RectangleFilled(38, 0, 41, totalsDrawTop - 1, GRAY);

  display->txt_Width(2);
  display->txt_Height(2);

  uint16_t currentLineY = 8;
  for (uint8_t i = 0; i < order->getNumItems(); i++)
  {
    Item item = order->getItem(i);
    Product product = ProductManager::get(item.productId);
    if(! product.valid) {
      continue;
    }

    uint8_t offset = item.quantity < 10 ? 16 : 0;
    display->gfx_MoveTo(offset, currentLineY);
    display->print(item.quantity);

    display->gfx_MoveTo(3 * 16, currentLineY);
    display->print(product.name);

    uint32_t price = product.price * item.quantity;
    uint8_t moneyLength = moneyCharacterWidth(price);
    uint8_t nameLength = strlen(product.name) + 1 + moneyLength;

    while(nameLength > 27) {
      nameLength -= 27;
      currentLineY += 24;
    }

    uint16_t priceStartX = 480 - moneyLength * 16;
    display->gfx_MoveTo(priceStartX, currentLineY);
    drawMoney(price);

    currentLineY += 24 + 8; // +24 for new line item, +8 for spacing between items
  }

  display->gfx_Clipping(0);  // Disable clipping so other graphics can run
}

void MainWindow::drawCredit() {
  // Yes, this function redoes some stuff in drawOrder
  if(state != MainWindowState::VEND_SCREEN) {
    return;
  }

  display->txt_FGcolour(BLACK);
  display->txt_BGcolour(WHITESMOKE);
  display->txt_Width(3);
  display->txt_Height(3);

  // Math is explained above
  uint16_t orderDrawBottom = cancelOrderButton.top - 4;
  uint16_t totalsDrawTop = orderDrawBottom - 3 - (2 * 32) - 16;

  display->gfx_MoveTo(8, totalsDrawTop + 4);
  display->putstr((char*) "Credit");
  uint32_t currentCredit = Session::getCurrentAvailableMoney();
  uint16_t creditWidth = 24 * moneyCharacterWidth(currentCredit);
  display->gfx_MoveTo(screenWidth - creditWidth - 8, totalsDrawTop + 4);
  drawMoney(currentCredit);
}

void MainWindow::drawMoney(uint32_t money) {
  uint16_t dollars = money / 100;
  uint8_t cents = money % 100;
  display->print('$');
  display->print(dollars);
  display->print('.');
  if(cents < 10) {
    display->print('0');
  }
  display->print(cents);
}

uint8_t MainWindow::moneyCharacterWidth(uint32_t money) {
  uint8_t numberWidth;
  if(money == 0) {
    numberWidth = 3; // Special case where log base 10 doesn't work as well.
  } else {
   numberWidth = (uint8_t) log10(money) + 1;  // Width of dollars and cents
  }
  return numberWidth + 2; // +2 is for "$" and ".";
}

void MainWindow::handleVendEnabled() {
  Serial.println("Handle vend enabled!");
  if(Session::canVend()) {
    Serial.println("enabled");
    vendButton.enable();
  } else {
    Serial.println("disabled");
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
    // Force the order to draw since we might have been covering part of the screen
    mainWindow->drawOrder();
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
  mainWindow->addItemButton.disable();

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
    setState(MainWindowState::VEND_SCREEN);
    Session::addToCurrentOrder(selectedRow, col);

    cancelOrderButton.enable();
  }
}

void MainWindow::moneyAvailable(MainWindow* mainWindow, uint32_t amount) {
  mainWindow->handleVendEnabled();

  if(amount == 0) {
    return;
  }

  mainWindow->cancelOrderButton.enable();
  mainWindow->drawCredit();
}

void MainWindow::addItemScreen(MainWindow* mainWindow) {
  mainWindow->display->gfx_RectangleFilled(
    0,
    mainWindow->gridTop - 4,
    mainWindow->screenWidth - 1,
    mainWindow->screenHeight - 1,
    WHITESMOKE
  );
  mainWindow->setState(MainWindowState::LETTERS_VISIBLE);
}

void MainWindow::customerLookupStarted(MainWindow* mainWindow) {
  mainWindow->membershipButton.setState(MembershipButtonState::PLEASE_WAIT);
  mainWindow->membershipButton.disable();
  mainWindow->cancelOrderButton.enable();
  mainWindow->setState(MainWindowState::VEND_SCREEN);
}

void MainWindow::ordersRetrieved(MainWindow* mainWindow) {
  mainWindow->membershipButton.setState(MembershipButtonState::ORDER_AVAILALBLE);
}

void MainWindow::noOrders(MainWindow* mainWindow) {
  mainWindow->membershipButton.setState(MembershipButtonState::NO_ORDERS);
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
  /// TODO Remove this method entirely when we remove that button
}

void MainWindow::currentOrderUpdated(MainWindow* mainWindow) {
  mainWindow->drawOrder();
  mainWindow->handleVendEnabled();

  Order* order = Session::getCurrentOrder();

  if(order->getNumItems() > 0) {
    mainWindow->cancelOrderButton.enable();
    // TODO PENDING and UNKNOWN may be the only two that CAN add an item
    if(order->status == OrderStatus::PROCESSING) {
      mainWindow->addItemButton.disable();
    }
  }
}

#endif