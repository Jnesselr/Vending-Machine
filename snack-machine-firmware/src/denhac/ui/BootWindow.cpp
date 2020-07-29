#include "denhac/ui/BootWindow.h"

#include "ui/WindowManager.h"
#include "denhac/ui/DenhacUI.h"

#include "utils.h"

void BootWindow::draw() {
  display->gfx_BGcolour(WHITESMOKE);
  display->gfx_Cls();

  display->txt_Height(8);
  display->txt_Width(8);
  display->txt_FGcolour(BLACK);
  display->txt_BGcolour(WHITESMOKE);
  display->txt_FontID(FONT_11);
  display->txt_Wrap(0);

  display->gfx_MoveTo(0, 0);
  uint16_t width = WindowManager::getWidth();
  display->gfx_MoveTo((width - 376) / 2, 10);

  // Width = 376, Height = 80
  display->putstr("DENHAC");

  display->txt_Height(6);
  display->txt_Width(6);
  
  display->gfx_MoveTo((width - 330) / 2, 110);
  // Width = 330, Height = 72
  display->putstr("vending");

  display->gfx_MoveTo((width - 330) / 2, 182);
  // Width = 330, Height = 60
  display->putstr("machine");

  display->txt_Height(3);
  display->txt_Width(3);

  /**
   * (height - 242 - 120) / 5 is room between
   * (height - 242 - 210) / 5 is
   * 
   * We want the stuff to be left aligned with adequate spacing
   * The largest is 333
   * 
   */
  
  uint16_t start_y = 416;

  display->gfx_MoveTo(94, start_y);
  // Width = 333, Height = 30
  display->putstr("Bill Validator");

  display->gfx_MoveTo(94, start_y + 60);
  // Width = 285, Height = 30
  display->putstr("Coin Changer");

  display->gfx_MoveTo(94, start_y + 120);
  // Width = 213 Height = 30
  display->putstr("Site Link");

  display->gfx_MoveTo(94, start_y + 180);
  // Width = 141 Height = 30
  display->putstr("Motors");
}

void BootWindow::loop() {
  uint16_t start_y = 416;
  uint8_t size = 20;
  word color = GREEN;

  if(redrawBillValidator) {
    redrawBillValidator = false;
    color = billValidatorIdle ? GREEN : RED;
    display->gfx_CircleFilled(
      80 - size,
      start_y + 15,
      size, color);
  }

  if(redrawCoinChanger) {
    redrawCoinChanger = false;
    color = coinChangerIdle ? GREEN : RED;
    display->gfx_CircleFilled(
      80 - size,
      start_y + 60 + 15,
      size, color);
  }

  if(redrawSiteLink) {
    redrawSiteLink = false;
    color = siteLinkIdle ? GREEN : RED;
    display->gfx_CircleFilled(
      80 - size,
      start_y + 120 + 15,
      size, color);
  }

  if(redrawMotors) {
    redrawMotors = false;
    color = motorsIdle ? GREEN : RED;
    display->gfx_CircleFilled(
      80 - size,
      start_y + 180 + 15,
      size, color);
  }

  if(billValidatorIdle &&
    coinChangerIdle &&
    siteLinkIdle &&
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

void BootWindow::setMotorsIdle(bool isIdle) {
  if(isIdle != motorsIdle) {
    redrawMotors = true;
    lastChangeMillis = current_loop_millis;
  }
  motorsIdle = isIdle;
}

void BootWindow::setSiteLinkIdle(bool isIdle) {
  if(isIdle != siteLinkIdle) {
    redrawSiteLink = true;
    lastChangeMillis = current_loop_millis;
  }
  siteLinkIdle = isIdle;
}