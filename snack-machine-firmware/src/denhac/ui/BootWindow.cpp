#ifdef VENDING_MAIN_BOARD

#include "denhac/ui/BootWindow.h"

#include "ui/WindowManager.h"
#include "ui/Screen.h"
#include "denhac/ui/DenhacUI.h"

#include "utils.h"

void BootWindow::show() {
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
  billValidatorY = 242 + (Screen::getHeight() - 242 - 210) / 2;
  coinChangerY = billValidatorY + 60;
  siteLinkY = coinChangerY + 60;
  wifiY = siteLinkY + 60;
  motorsY = wifiY + 60;

  display->gfx_MoveTo(102, billValidatorY);
  display->putstr((char*) "Bill Validator");

  display->gfx_MoveTo(102, coinChangerY);
  display->putstr((char*) "Coin Changer");

  display->gfx_MoveTo(102, siteLinkY);
  display->putstr((char*) "Site Link");

  display->gfx_MoveTo(102, wifiY);
  display->putstr((char*) "WiFi Connected");

  display->gfx_MoveTo(102, motorsY);
  display->putstr((char*) "Motors");
}

void BootWindow::loop() {
  // If it's a minute and we're not done with this, hard reset
  uint32_t timeout = 15 * 1000;
  if(current_loop_millis > timeout) {
    while(true); // Force a reset with watchdog
  }

  uint8_t size = 20;
  word color = GREEN;

  if(redrawBillValidator) {
    redrawBillValidator = false;
    color = billValidatorIdle ? GREEN : RED;
    display->gfx_CircleFilled(66, billValidatorY + 15, size, color);
    if(billValidatorIdle) {
      drawCheckAt(46, billValidatorY - 5);
    } else {
      drawXAt(46, billValidatorY - 5);
    }
  }

  if(redrawCoinChanger) {
    redrawCoinChanger = false;
    color = coinChangerIdle ? GREEN : RED;
    display->gfx_CircleFilled(66, coinChangerY + 15, size, color);
    if(coinChangerIdle) {
      drawCheckAt(46, coinChangerY - 5);
    } else {
      drawXAt(46, coinChangerY - 5);
    }
  }

  if(redrawSiteLink) {
    redrawSiteLink = false;
    color = siteLinkIdle ? GREEN : RED;
    display->gfx_CircleFilled(66, siteLinkY + 15, size, color);
    if(siteLinkIdle) {
      drawCheckAt(46, siteLinkY - 5);
    } else {
      drawXAt(46, siteLinkY - 5);
    }
  }

  if(redrawWifi) {
    redrawWifi = false;
    color = wifiOnline ? GREEN : RED;
    display->gfx_CircleFilled(66, wifiY + 15, size, color);
    if(wifiOnline) {
      drawCheckAt(46, wifiY - 5);
    } else {
      drawXAt(46, wifiY - 5);
    }
  }

  if(redrawMotors) {
    redrawMotors = false;
    color = motorsIdle ? GREEN : RED;
    display->gfx_CircleFilled(66, motorsY + 15, size, color);
    if(motorsIdle) {
      drawCheckAt(46, motorsY - 5);
    } else {
      drawXAt(46, motorsY - 5);
    }
  }

  if(billValidatorIdle &&
    coinChangerIdle &&
    siteLinkIdle &&
    wifiOnline &&
    motorsIdle) {
      LOOP_WAIT_MS(lastChangeMillis, 3000);
      WindowManager::show(DenhacUI::mainWindow);
    }
}

void BootWindow::setBillValidatorIdle(bool isIdle) {
  if(isIdle != billValidatorIdle) {
    redrawBillValidator = true;
    lastChangeMillis = current_loop_millis;
  }
  billValidatorIdle = isIdle;
}

void BootWindow::setCoinChangerIdle(bool isIdle) {
  if(isIdle != coinChangerIdle) {
    redrawCoinChanger = true;
    lastChangeMillis = current_loop_millis;
  }
  coinChangerIdle = isIdle;
}

void BootWindow::setSiteLinkIdle(bool isIdle) {
  if(isIdle != siteLinkIdle) {
    redrawSiteLink = true;
    lastChangeMillis = current_loop_millis;
  }
  siteLinkIdle = isIdle;
}

void BootWindow::setWifiOnline(bool online) {
  if(online != wifiOnline) {
    redrawWifi = true;
    lastChangeMillis = current_loop_millis;
  }
  wifiOnline = online;
}

void BootWindow::setMotorsIdle(bool isIdle) {
  if(isIdle != motorsIdle) {
    redrawMotors = true;
    lastChangeMillis = current_loop_millis;
  }
  motorsIdle = isIdle;
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