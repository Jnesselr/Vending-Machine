#pragma once

#include "ui/Window.h"

class MainWindow : public Window {
  public:
    MainWindow();
    void draw();
    void loop();
  private:
    unsigned long lastMillis = 0;
};