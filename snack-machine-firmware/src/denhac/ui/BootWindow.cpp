#ifdef VENDING_MAIN_BOARD

#include "denhac/ui/BootWindow.h"

#include "ui/WindowManager.hpp"
#include "ui/Screen.h"
#include "denhac/ui/MainWindow/MainWindow.h"

#include "utils.h"

Diablo_Serial_4DLib* BootWindow::display;

unsigned long BootWindow::lastChangeMillis = 0;
bool BootWindow::billValidatorIdle = false;
bool BootWindow::coinChangerIdle = false;
bool BootWindow::siteLinkIdle = false;
bool BootWindow::wifiOnline = false;
bool BootWindow::denhacOrgLink = false;
bool BootWindow::motorsIdle = false;

bool BootWindow::redrawBillValidator = true;
bool BootWindow::redrawCoinChanger = true;
bool BootWindow::redrawSiteLink = true;
bool BootWindow::redrawWifi = true;
bool BootWindow::redrawDenhacOrg = true;
bool BootWindow::redrawMotors = true;

uint16_t BootWindow::billValidatorY;
uint16_t BootWindow::coinChangerY;
uint16_t BootWindow::siteLinkY;
uint16_t BootWindow::wifiY;
uint16_t BootWindow::denhacOrgY;
uint16_t BootWindow::motorsY;

uint8_t BootWindow::numStepsCompleted = 0;
uint8_t BootWindow::numStepsTotal = 64 + 6;

constexpr uint16_t text_x_value = 96;
constexpr uint16_t circle_x_value = text_x_value - 36;
constexpr uint16_t check_x_value = circle_x_value - 20;

void BootWindow::teardown() {
  Motors::onSystemStateChanged = nullptr;
  Motors::onMotorAvailability = nullptr;
  BillValidator::onStateChanged = nullptr;
  CoinChanger::onStateChanged = nullptr;
  SiteLink::onStateChanged = nullptr;
  SiteLink::statusCallback = nullptr;
}

void BootWindow::setup() {
  display = &Screen::display;

  Motors::onSystemStateChanged = BootWindow::onMotorSystemStateChanged;
  Motors::onMotorAvailability = BootWindow::onMotorAvailability;
  BillValidator::onStateChanged = BootWindow::onBillValidatorStateCallback;
  CoinChanger::onStateChanged = BootWindow::onCoinChangerStateCallback;
  SiteLink::onStateChanged = BootWindow::onSiteLinkStateCallback;
  SiteLink::statusCallback = BootWindow::onSiteLinkStatusCallback;

  display->gfx_BGcolour(WHITESMOKE);
  display->gfx_Cls();

  display->txt_Height(8);
  display->txt_Width(8);
  display->txt_FGcolour(BLACK);
  display->txt_BGcolour(WHITESMOKE);
  display->txt_FontID(FONT_11);
  display->txt_Wrap(0);

  display->gfx_MoveTo(0, 0);
  uint16_t width = Screen::getWidth();
  display->gfx_MoveTo((width - 376) / 2, 10);

  // Width = 376, Height = 80
  display->putstr((char*) "DENHAC");

  display->txt_Height(6);
  display->txt_Width(6);
  
  display->gfx_MoveTo((width - 330) / 2, 110);
  // Width = 330, Height = 72
  display->putstr((char*) "vending");

  display->gfx_MoveTo((width - 330) / 2, 182);
  // Width = 330, Height = 60
  display->putstr((char*) "machine");

  display->txt_Height(3);
  display->txt_Width(3);
  
  // Lowest Y of "machine" text == 242
  // Height of status text combined == 210
  billValidatorY = 350; // 242 + (Screen::getHeight() - 242 - 210) / 2;
  coinChangerY = billValidatorY + 60;
  siteLinkY = coinChangerY + 60;
  wifiY = siteLinkY + 60;
  denhacOrgY = wifiY + 60;
  motorsY = denhacOrgY + 60;

  display->gfx_MoveTo(text_x_value, billValidatorY);
  display->putstr((char*) "Bill Validator");

  display->gfx_MoveTo(text_x_value, coinChangerY);
  display->putstr((char*) "Coin Changer");

  display->gfx_MoveTo(text_x_value, siteLinkY);
  display->putstr((char*) "Site Link");

  display->gfx_MoveTo(text_x_value, wifiY);
  display->putstr((char*) "WiFi Connected");

  display->gfx_MoveTo(text_x_value, denhacOrgY);
  display->putstr((char*) "denhac.org link");

  display->gfx_MoveTo(text_x_value, motorsY);
  display->putstr((char*) "Motors");

  // Reset it back to normal
  display->gfx_MoveTo(0, 0);
}

void BootWindow::loop() {
  // If it's a minute and we're not done with this, hard reset
  uint32_t timeout = 60000;
  if(current_loop_millis > timeout) {
    while(true); // Force a reset with watchdog
  }

  uint8_t size = 20;
  word color = GREEN;

  if(redrawBillValidator) {
    redrawBillValidator = false;
    color = billValidatorIdle ? GREEN : RED;
    display->gfx_CircleFilled(circle_x_value, billValidatorY + 15, size, color);
    if(billValidatorIdle) {
      drawCheckAt(check_x_value, billValidatorY - 5);
    } else {
      drawXAt(check_x_value, billValidatorY - 5);
    }
  }

  if(redrawCoinChanger) {
    redrawCoinChanger = false;
    color = coinChangerIdle ? GREEN : RED;
    display->gfx_CircleFilled(circle_x_value, coinChangerY + 15, size, color);
    if(coinChangerIdle) {
      drawCheckAt(check_x_value, coinChangerY - 5);
    } else {
      drawXAt(check_x_value, coinChangerY - 5);
    }
  }

  if(redrawSiteLink) {
    redrawSiteLink = false;
    color = siteLinkIdle ? GREEN : RED;
    display->gfx_CircleFilled(circle_x_value, siteLinkY + 15, size, color);
    if(siteLinkIdle) {
      drawCheckAt(check_x_value, siteLinkY - 5);
    } else {
      drawXAt(check_x_value, siteLinkY - 5);
    }
  }

  if(redrawWifi) {
    redrawWifi = false;
    color = wifiOnline ? GREEN : RED;
    display->gfx_CircleFilled(circle_x_value, wifiY + 15, size, color);
    if(wifiOnline) {
      drawCheckAt(check_x_value, wifiY - 5);
    } else {
      drawXAt(check_x_value, wifiY - 5);
    }
  }

  if(redrawDenhacOrg) {
    redrawDenhacOrg = false;
    color = denhacOrgLink ? GREEN : RED;
    display->gfx_CircleFilled(circle_x_value, denhacOrgY + 15, size, color);
    if(denhacOrgLink) {
      drawCheckAt(check_x_value, denhacOrgY - 5);
    } else {
      drawXAt(check_x_value, denhacOrgY - 5);
    }
  }

  if(redrawMotors) {
    redrawMotors = false;
    color = motorsIdle ? GREEN : RED;
    display->gfx_CircleFilled(circle_x_value, motorsY + 15, size, color);
    if(motorsIdle) {
      drawCheckAt(check_x_value, motorsY - 5);
    } else {
      drawXAt(check_x_value, motorsY - 5);
    }
  }

  display->gfx_Rectangle(38, motorsY + 79, Screen::getWidth() - 38, motorsY + 86, LIGHTGREY);

  uint16_t totalWidth = Screen::getWidth() - 80;
  uint16_t widthUsed = (numStepsCompleted * totalWidth) / numStepsTotal;

  display->gfx_RectangleFilled(40, motorsY + 81, 40 + widthUsed, motorsY + 84, GREEN);

  if(billValidatorIdle &&
    coinChangerIdle &&
    siteLinkIdle &&
    wifiOnline &&
    denhacOrgLink &&
    motorsIdle) {
      LOOP_WAIT_MS(lastChangeMillis, 3000);
      WindowManager::show<MainWindow>();
    }
}

void BootWindow::onMotorSystemStateChanged(
  MotorSystemState oldState,
  MotorSystemState newState) {
  if(newState != MotorSystemState::IDLE || redrawMotors) {
    return;
  }

  motorsIdle = true;
  redrawMotors = true;
  lastChangeMillis = current_loop_millis;
  numStepsCompleted++;
}

void BootWindow::onBillValidatorStateCallback(
  BillValidatorState oldState,
  BillValidatorState newState) {
    if(newState != BillValidatorState::IDLE || redrawBillValidator) {
      return;
    }

    redrawBillValidator = true;
    lastChangeMillis = current_loop_millis;
    billValidatorIdle = true;
    numStepsCompleted++;
}

void BootWindow::onCoinChangerStateCallback(
  CoinChangerState oldState,
  CoinChangerState newState) {
    if(newState == CoinChangerState::IDLE || coinChangerIdle) {
      return;
    }

    redrawCoinChanger = true;
    coinChangerIdle = true;
    lastChangeMillis = current_loop_millis;
    numStepsCompleted++;
}

void BootWindow::onSiteLinkStateCallback(
  SiteLinkState oldState,
  SiteLinkState newState) {
    if(newState == SiteLinkState::IDLE || siteLinkIdle) {
      return;
    }

    redrawSiteLink = true;
    siteLinkIdle = true;
    lastChangeMillis = current_loop_millis;
    numStepsCompleted++;
}

void BootWindow::onSiteLinkStatusCallback(uint8_t statusCode) {
  if(statusCode == BridgeStatus::WIFI_CONNECTED) {
    if(!wifiOnline) {
      SiteLink::fetchProducts();
    }

    redrawWifi = true;
    wifiOnline = true;
    lastChangeMillis = current_loop_millis;
    numStepsCompleted++;
  } else if(statusCode == BridgeStatus::PRODUCTS_FETCHED) {
    redrawDenhacOrg = true;
    denhacOrgLink = true;
    lastChangeMillis = current_loop_millis;
    numStepsCompleted++;
  }

}

void BootWindow::onMotorAvailability(uint8_t row, uint8_t col, bool available) {
  numStepsCompleted++;
}

void BootWindow::drawXAt(uint16_t x, uint16_t y) {
  word xValues[] = {12, 20, 28, 32, 24, 32, 28, 20, 12,  8, 16,  8};
  word yValues[] = { 8, 16,  8, 12, 20, 28, 32, 24, 32, 28, 20, 12};

  uint8_t n = sizeof(xValues) / sizeof(word);

  SHIFT_POLY(xValues, x);
  SHIFT_POLY(yValues, y);

  display->gfx_PolygonFilled(n, xValues, yValues, WHITE);

  SHIFT_POLY(xValues, -x);
  SHIFT_POLY(yValues, -y);
}

void BootWindow::drawCheckAt(uint16_t x, uint16_t y) {
  word xValues[] = { 8, 16, 32, 28, 16, 12};
  word yValues[] = {24, 32, 16, 12, 24, 20};

  uint8_t n = sizeof(xValues) / sizeof(word);

  SHIFT_POLY(xValues, x);
  SHIFT_POLY(yValues, y);

  display->gfx_PolygonFilled(n, xValues, yValues, WHITE);

  SHIFT_POLY(xValues, -x);
  SHIFT_POLY(yValues, -y);
}

#endif