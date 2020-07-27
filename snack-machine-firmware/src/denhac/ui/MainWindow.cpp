#include "denhac/ui/MainWindow.h"

#include "ui/WindowManager.h"

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
  unsigned long currentMillis = millis();
  if(currentMillis < lastMillis + 500) {
    return;
  }

  display->println(currentMillis);
  lastMillis = currentMillis;
}