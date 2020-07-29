#pragma once

#include "ui/Window.h"

class MainWindow : public Window {
  public:
    MainWindow();
    void draw();
    void loop();
  private:
    unsigned long lastMillis = 0;
    uint16_t width = 0;
    uint16_t height = 0;
    uint16_t y = 0;
    uint8_t y_inc = 1;

    bool on[480];
    bool next[480];
};