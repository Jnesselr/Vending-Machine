#include "denhac/ui/MainWindow.h"

MainWindow::MainWindow() : Window() {}

void MainWindow::draw(Diablo_Serial_4DLib& display) {
  display.gfx_BGcolour(LIGHTGREY);
  display.gfx_Cls();
  display.println("Hello from a Window!");
}