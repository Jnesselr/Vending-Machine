#include "denhac/ui/MainWindow.h"

#include "ui/WindowManager.h"

MainWindow::MainWindow() : Window() {}

void MainWindow::draw(Diablo_Serial_4DLib& display) {
  display.gfx_BGcolour(LIGHTGREY);
  display.gfx_Cls();
  display.println("Hello from a Window!");
  display.print("Width: ");
  display.println(WindowManager::getWidth());
  display.print("Height: ");
  display.print(WindowManager::getHeight());
}