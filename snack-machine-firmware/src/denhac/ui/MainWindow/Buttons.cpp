#ifdef VENDING_MAIN_BOARD

#include "denhac/ui/MainWindow/Buttons.h"

#include "denhac/Session.h"

CellButton::CellButton() {
  display = nullptr;
  enabled = true;
  left = right = top = bottom = 0;
}

void CellButton::show() {
  if(!redrawNeeded) {
    return;
  }

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
    display->txt_FGcolour(LIGHTGREY);
  }

  display->gfx_MoveTo(
    (left + right) / 2 - 56 / 2,
    (top + bottom) / 2 - 72 / 2 - 8
  );
  display->putCH(character);

  redrawNeeded = false;
}

bool CellButton::inBounds(uint16_t x, uint16_t y) {
  return x > left && x < right && y < bottom && y > top;
}

BackButton::BackButton() {
  display = nullptr;
  enabled = true;
  left = right = top = bottom = 0;
}

void BackButton::show() {
  if(!redrawNeeded) {
    return;
  }

  word color = pressed ? BLUE : LIGHTSKYBLUE;
  display->gfx_RectangleFilled(left, top, right, bottom, color);

  // Cells are 156 x 104 (3 x 2 multiple of 52)
  word xValues[] = {32, 32, 59, 59, 120, 120, 59, 59};
  word yValues[] = {52, 51, 24, 45,  45,  58, 58, 79};

  SHIFT_POLY(xValues, left);
  SHIFT_POLY(yValues, top);

  uint8_t n = sizeof(xValues) / sizeof(word);
  display->gfx_PolygonFilled(n, xValues, yValues, WHITE);

  SHIFT_POLY(xValues, -left);
  SHIFT_POLY(yValues, -top);

  redrawNeeded = false;
}

void BackButton::hide() {
  disable();
  display->gfx_RectangleFilled(left, top, right, bottom, WHITESMOKE);
}

bool BackButton::inBounds(uint16_t x, uint16_t y) {
  return x > left && x < right && y < bottom && y > top;
}

CancelOrderButton::CancelOrderButton() {
  display = nullptr;
  enabled = true;
  left = right = top = bottom = 0;
}

void CancelOrderButton::show() {
  if(!redrawNeeded) {
    return;
  }

  word borderColor = RED;
  word insetColor = WHITE;
  word textColor = BLACK;

  if(!enabled) {
    borderColor = DARKGRAY;
    textColor = DARKGRAY;
  } else if(pressed) {
    insetColor = borderColor;
    textColor = WHITE;
  }

  uint16_t mid = (top + bottom) / 2;
  uint16_t arrowLeftX = left + (mid - top);
  word xValuesLarge[] = {left, arrowLeftX, right, right, arrowLeftX};
  word yValuesLarge[] = { mid, top, top, bottom, bottom};

  uint8_t nLarge = sizeof(xValuesLarge) / sizeof(word);

  display->gfx_PolygonFilled(nLarge, xValuesLarge, yValuesLarge, borderColor);

  word xValuesSmaller[] = {left + 6, arrowLeftX + 2, right - 4, right - 4, arrowLeftX + 2};
  word yValuesSmaller[] = { mid, top + 4, top + 4, bottom - 4, bottom - 4};

  uint8_t nSmaller = sizeof(xValuesSmaller) / sizeof(word);

  // Save a command if there's not going to be a visual difference
  if(insetColor != borderColor) {
    display->gfx_PolygonFilled(nSmaller, xValuesSmaller, yValuesSmaller, insetColor);
  }

  display->txt_BGcolour(insetColor);
  display->txt_FGcolour(textColor);
  display->txt_Width(3);
  display->txt_Height(3);
  display->gfx_MoveTo(arrowLeftX + 2, top + 6);
  display->putstr((char*) "Cancel");
  display->gfx_MoveTo(arrowLeftX + 14, top + 42);
  display->putstr((char*) "Order");

  redrawNeeded = false;
}

bool CancelOrderButton::inBounds(uint16_t x, uint16_t y) {
  return x > left && x < right && y < bottom && y > top;
}

AddItemButton::AddItemButton() {
  display = nullptr;
  enabled = true;
  left = right = top = bottom = 0;
}

void AddItemButton::show() {
  if(!redrawNeeded) {
    return;
  }
  
  word borderColor = BLACK;
  word insetColor = WHITE;
  word textColor = BLACK;

  if(pressed) {
    insetColor = borderColor;
    textColor = WHITE;
  }

  display->gfx_RectangleFilled(left, top, right, bottom, borderColor);

  if(borderColor != insetColor) {
    display->gfx_RectangleFilled(left + 4, top + 4, right - 4, bottom - 4, insetColor);
  }

  display->txt_BGcolour(insetColor);
  display->txt_FGcolour(textColor);
  display->txt_Width(3);
  display->txt_Height(3);
  display->gfx_MoveTo(left + 20, top + 6);
  display->putstr((char*) "Add");
  display->gfx_MoveTo(left + 4, top + 42);
  display->putstr((char*) "Item");

  redrawNeeded = false;
}

bool AddItemButton::inBounds(uint16_t x, uint16_t y) {
  return x > left && x < right && y < bottom && y > top;
}

VendButton::VendButton() {
  display = nullptr;
  enabled = true;
  left = right = top = bottom = 0;
}

void VendButton::show() {
  if(!redrawNeeded) {
    return;
  }
  
  word borderColor = GREEN;
  word insetColor = WHITE;
  word textColor = BLACK;

  if(!enabled) {
    borderColor = DARKGRAY;
    textColor = DARKGRAY;
  } else if(pressed) {
    insetColor = borderColor;
    textColor = WHITE;
  }

  display->gfx_RectangleFilled(left, top, right, bottom, borderColor);

  if(borderColor != insetColor) {
    display->gfx_RectangleFilled(left + 4, top + 4, right - 4, bottom - 4, insetColor);
  }

  display->txt_Width(8);
  display->txt_Height(8);
  display->txt_FGcolour(textColor);
  display->txt_BGcolour(insetColor);
  display->gfx_MoveTo(left + 110, top + 12);
  display->putstr((char*)"VEND");

  redrawNeeded = false;
}

bool VendButton::inBounds(uint16_t x, uint16_t y) {
  return x > left && x < right && y < bottom && y > top;
}

MembershipButton::MembershipButton() {
  display = nullptr;
  enabled = true;
  left = right = top = bottom = 0;
  state = MembershipButtonState::SCAN_CARD;
}

void MembershipButton::show() {
  word borderColor = BLUE;
  word insetColor = WHITE;
  word textColor = BLACK;

  uint8_t numOrders = Session::getNumOrders();

  if(state == MembershipButtonState::NUM_ORDERS && numOrders > 0) {
    enable();
  }

  if(!redrawNeeded) {
    return;
  }

  if(!enabled) {
    borderColor = DARKGRAY;
    textColor = DARKGRAY;
  } else if(pressed) {
    insetColor = borderColor;
    textColor = WHITE;
  }

  display->gfx_RectangleFilled(left, top, right, bottom, borderColor);

  if(borderColor != insetColor) {
    display->gfx_RectangleFilled(left + 4, top + 4, right - 4, bottom - 4, insetColor);
  }
  display->txt_BGcolour(insetColor);
  display->txt_FGcolour(textColor);
  display->txt_Width(3);
  display->txt_Height(3);

  if(state == MembershipButtonState::SCAN_CARD) {
    display->gfx_MoveTo(left + 38, top + 6);
    display->putstr((char*) "Scan");
    display->gfx_MoveTo(left + 38, top + 42);
    display->putstr((char*) "Card");
  } else if(state == MembershipButtonState::PLEASE_WAIT) {
    display->gfx_MoveTo(left + 4 + 10, top + 6);
    display->putstr((char*) "Please");
    display->gfx_MoveTo(left + 4 + 34, top + 42);
    display->putstr((char*) "Wait");
  } else if(state == MembershipButtonState::NUM_ORDERS) {
    if(numOrders == 0) {
      display->gfx_MoveTo(left + 4 + 58, top + 6);
      display->putstr((char*) "No");
    } else {
      display->gfx_MoveTo(left + 4 + 70, top + 6);
      display->putCH(numOrders + '0');
    }

    if(numOrders == 0 || numOrders > 1) {
      display->gfx_MoveTo(left + 4 + 10, top + 42);
      display->putstr((char*) "Orders");
    } else {
      display->gfx_MoveTo(left + 4 + 22, top + 42);
      display->putstr((char*) "Order");
    }
  }

  redrawNeeded = false;
}

bool MembershipButton::inBounds(uint16_t x, uint16_t y) {
  return x > left && x < right && y < bottom && y > top;
}

void MembershipButton::setState(MembershipButtonState state) {
  if(this->state != state) {
    redrawNeeded = true;
  }

  this->state = state;
}

#endif