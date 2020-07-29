#include "denhac/ui/MainWindow.h"

#include "ui/WindowManager.h"
#include "utils.h"
#include <avr/wdt.h>

MainWindow::MainWindow() : Window() {
  memset(on, 0, sizeof(on));
  memset(on, 0, sizeof(next));
}

void MainWindow::draw() {
  display->gfx_BGcolour(BLACK);
  display->gfx_Cls();

  width = WindowManager::getWidth();
  height = WindowManager::getHeight();

  lastMillis = current_loop_millis;
  display->gfx_Line(0, 0, width-1, 0, BLUE);

  display->gfx_PutPixel(width / 2, 0, WHITE);
  on[width/2] = true;
  y = 1;
  y_inc = 1;
}

void MainWindow::loop() {
  uint16_t start_x = 0;
  bool shouldDrawBackground;
  if(y == height || y == 0) {
    y_inc = - y_inc;
  }

  for (uint16_t x = 0; x < width; x++)
  {
    bool leftPixelOn = false;
    bool rightPixelOn = false;

    if(x > 0) {
      leftPixelOn = on[x - 1];
    }

    if(x < width - 1) {
      rightPixelOn = on[x + 1];
    }

    if(leftPixelOn ^ rightPixelOn) {
      next[x] = true;
      display->gfx_PutPixel(x, y, WHITE);
      if(shouldDrawBackground) {
        shouldDrawBackground = false;
        display->gfx_Line(start_x, y, x-1, y, BLUE);
      }
    } else {
      next[x] = false;
      if(!shouldDrawBackground) {
        shouldDrawBackground = true;
        start_x = x;
      }
    }
  }

  if(shouldDrawBackground) {
    shouldDrawBackground = false;
    display->gfx_Line(start_x, y, width-1, y, BLUE);
  }

  for (uint16_t j = 0; j < sizeof(on); j++)
  {
    on[j] = next[j];
  }
  y += y_inc;
}