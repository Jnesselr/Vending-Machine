#ifndef _MOTORGRID_H_
#define _MOTORGRID_H_

#include <Adafruit_INA219.h>

class MotorGrid {
  public:
    MotorGrid();
    void setup();
    boolean isPresent(const int row, const int col);
    boolean vend(const int row, const int col);
    boolean currentFlowing();

  private:
    void on(const int row, const int col);
    void off();

    const int PIN_ROW_1 = 49;
    const int PIN_ROW_2 = 48;
    const int PIN_ROW_3 = 47;
    const int PIN_ROW_4 = 46;
    const int PIN_ROW_5 = 45;
    const int PIN_ROW_6 = 44;
    const int PIN_ROW_7 = 43;
    const int PIN_ROW_8 = 42;

    const int PIN_COL_1 = 37;
    const int PIN_COL_2 = 36;
    const int PIN_COL_3 = 35;
    const int PIN_COL_4 = 34;
    const int PIN_COL_5 = 33;
    const int PIN_COL_6 = 32;
    const int PIN_COL_7 = 31;
    const int PIN_COL_8 = 30;

    const int PIN_ROWS[8] = {
      MotorGrid::PIN_ROW_1,
      MotorGrid::PIN_ROW_2,
      MotorGrid::PIN_ROW_3,
      MotorGrid::PIN_ROW_4,
      MotorGrid::PIN_ROW_5,
      MotorGrid::PIN_ROW_6,
      MotorGrid::PIN_ROW_7,
      MotorGrid::PIN_ROW_8
    };

    const int PIN_COLS[8] = {
      MotorGrid::PIN_COL_1,
      MotorGrid::PIN_COL_2,
      MotorGrid::PIN_COL_3,
      MotorGrid::PIN_COL_4,
      MotorGrid::PIN_COL_5,
      MotorGrid::PIN_COL_6,
      MotorGrid::PIN_COL_7,
      MotorGrid::PIN_COL_8
    };
  
    Adafruit_INA219* ina219;
};

#endif
