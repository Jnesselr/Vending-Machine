#pragma once

#include "ui/Window.h"

class MainWindow : public Window {
  public:
    MainWindow();
    void draw(Diablo_Serial_4DLib& display);
};