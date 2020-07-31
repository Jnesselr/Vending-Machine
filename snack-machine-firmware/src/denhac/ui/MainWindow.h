#pragma once

#include "ui/Window.h"

class MainWindow : public Window {
  public:
    MainWindow();
    void show();
    void loop();
  private:
    unsigned long lastMillis = 0;
    uint16_t width = 0;
    uint16_t height = 0;
    uint16_t y = 0;

    bool on[480];
    bool next[480];
};