#include "denhac/ui/MainWindow.h"

#include "ui/WindowManager.h"
#include "utils.h"

MainWindow::MainWindow() : Window() {}

void MainWindow::draw() {
  display->gfx_BGcolour(LIGHTGREY);
  display->gfx_Cls();
  display->println("Hello from a Window!");
  display->print("Width: ");
  display->println(WindowManager::getWidth());
  display->print("Height: ");
  display->println(WindowManager::getHeight());
}

void MainWindow::loop() {
  LOOP_WAIT_MS(lastMillis, 500)

  display->println(current_loop_millis);
  lastMillis = current_loop_millis;
}