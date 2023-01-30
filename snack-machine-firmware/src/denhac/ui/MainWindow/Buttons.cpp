#ifdef VENDING_MAIN_BOARD

#include "denhac/ui/MainWindow/Buttons.h"

#include "denhac/Session.h"

CellButton::CellButton() {
  display = nullptr;
  enabled = true;
  left = right = top = bottom = 0;
  character = ' ';
}

void CellButton::show() {
  if(!redrawNeeded) {
    return;
  }

  display->txt_Width(8);
  display->txt_Height(8);

  word backgroundColor = WHITESMOKE;
  word textColor = BLACK;

  if(!enabled) {
    textColor = LIGHTGREY;
  } else if(pressed) {
    backgroundColor = BLACK;
    textColor = WHITE;
  }

  display->txt_BGcolour(backgroundColor);
  display->txt_FGcolour(textColor);

  display->gfx_RectangleFilled(left, top, right, bottom, backgroundColor);

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
  word insetColor = borderColor;
  word textColor = WHITE;

  if(!enabled) {
    borderColor = DARKGRAY;
    insetColor = WHITE;
    textColor = DARKGRAY;
  } else if(pressed) {
    insetColor = WHITE;
    textColor = BLACK;
  }

  uint16_t mid = (top + bottom) / 2;
  uint16_t arrowLeftX = left + (mid - top);
  word xValuesLarge[] = {left, arrowLeftX, right, right, arrowLeftX};
  word yValuesLarge[] = { mid, top, top, bottom, bottom};

  uint8_t nLarge = sizeof(xValuesLarge) / sizeof(word);

  display->gfx_PolygonFilled(nLarge, xValuesLarge, yValuesLarge, borderColor);


  constexpr uint8_t borderThickness = 2; // This should be even
  // The idea is that the arrow points left and the top left most point (not the left most point) should angle down and to the right for the border inset.
  // I recognize that's hard to visualize, but it makes the most visual sense for how the arrow should look.
  word xValuesSmaller[] = {
    left + borderThickness + borderThickness / 2,
    arrowLeftX + borderThickness / 2,
    right - borderThickness,
    right - borderThickness,
    arrowLeftX + borderThickness / 2
  };
  word yValuesSmaller[] = {
    mid,
    top + borderThickness,
    top + borderThickness,
    bottom - borderThickness,
    bottom - borderThickness
  };

  uint8_t nSmaller = sizeof(xValuesSmaller) / sizeof(word);

  // Save a command if there's not going to be a visual difference
  if(insetColor != borderColor) {
    display->gfx_PolygonFilled(nSmaller, xValuesSmaller, yValuesSmaller, insetColor);
  }

  display->txt_BGcolour(insetColor);
  display->txt_FGcolour(textColor);
  display->txt_Width(3);
  display->txt_Height(3);
  display->gfx_MoveTo(arrowLeftX + 2, top + 24);
  display->putstr((char*) "Cancel");
  // display->gfx_MoveTo(arrowLeftX + 14, top + 42);
  // display->putstr((char*) "Order");

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
  word insetColor = borderColor;
  word textColor = WHITE;

  if(!enabled) {
    borderColor = DARKGRAY;
    insetColor = WHITE;
    textColor = DARKGRAY;
  } else if(pressed) {
    insetColor = WHITE;
    textColor = BLACK;
  }

  display->gfx_RectangleFilled(left, top, right, bottom, borderColor);

  if(borderColor != insetColor) {
    constexpr uint8_t borderThickness = 2;
    display->gfx_RectangleFilled(
      left + borderThickness,
      top + borderThickness,
      right - borderThickness,
      bottom - borderThickness,
      insetColor
    );
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
  word insetColor = borderColor;
  word textColor = WHITE;

  if(!enabled) {
    borderColor = DARKGRAY;
    textColor = DARKGRAY;
    insetColor = WHITE;
  } else if(pressed) {
    insetColor = WHITE;
    textColor = BLACK;
  }

  display->gfx_RectangleFilled(left, top, right, bottom, borderColor);

  if(borderColor != insetColor) {
    constexpr uint8_t borderThickness = 2;
    display->gfx_RectangleFilled(
      left + borderThickness,
      top + borderThickness,
      right - borderThickness,
      bottom - borderThickness,
      insetColor
    );
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
  word insetColor = borderColor;
  word textColor = WHITE;

  if(state == MembershipButtonState::ORDER_AVAILALBLE) {
    enable();
  }

  if(!redrawNeeded) {
    return;
  }

  if(!enabled) {
    borderColor = DARKGRAY;
    insetColor = WHITE;
    textColor = DARKGRAY;
  } else if(pressed) {
    insetColor = WHITE;
    textColor = BLACK;
  }

  display->gfx_RectangleFilled(left, top, right, bottom, borderColor);

  if(borderColor != insetColor) {
    constexpr uint8_t borderThickness = 2;
    display->gfx_RectangleFilled(
      left + borderThickness,
      top + borderThickness,
      right - borderThickness,
      bottom - borderThickness,
      insetColor
    );
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
  } else if(state == MembershipButtonState::ORDER_AVAILALBLE) {
    display->gfx_MoveTo(left + 4 + 22, top + 6);
    display->putstr((char*) "Order");
    display->gfx_MoveTo(left + 4 + 22, top + 42);
    display->putstr((char*) "Ready");
  } else if(state == MembershipButtonState::NO_ORDERS) {
    display->gfx_MoveTo(left + 4 + 58, top + 6);
    display->putstr((char*) "No");
    display->gfx_MoveTo(left + 4 + 10, top + 42);
    display->putstr((char*) "Orders");
  } else if(state == MembershipButtonState::UNKNOWN_CARD) {
    display->txt_Width(2);
    display->txt_Height(2);
    display->gfx_MoveTo(left + 4 + 25, top + 18);
    display->putstr((char*) "Unknown");
    display->gfx_MoveTo(left + 4 + 49, top + 42);
    display->putstr((char*) "Card");
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