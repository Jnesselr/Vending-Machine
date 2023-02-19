#pragma once

#include <Diablo_Serial_4DLib.h>
#include <DirectIO.h>

class Screen {
public:
  static void setup();
  static Diablo_Serial_4DLib display;


  static uint16_t getWidth();
  static uint16_t getHeight();

private:
    static OutputPort<PORT_H, 2, 1> displayResetPin;
    static HardwareSerial* displaySerial;

    static uint16_t width;
    static uint16_t height;
};