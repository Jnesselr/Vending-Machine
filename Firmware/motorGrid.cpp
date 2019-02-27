#include "motorGrid.h"

#include <Adafruit_INA219.h>

MotorGrid::MotorGrid() {
  this->ina219 = new Adafruit_INA219();
//  this->ina219->begin();

  pinMode(MotorGrid::PIN_ROW_1, OUTPUT);
  pinMode(MotorGrid::PIN_ROW_2, OUTPUT);
  pinMode(MotorGrid::PIN_ROW_3, OUTPUT);
  pinMode(MotorGrid::PIN_ROW_4, OUTPUT);
  pinMode(MotorGrid::PIN_ROW_5, OUTPUT);
  pinMode(MotorGrid::PIN_ROW_6, OUTPUT);
  pinMode(MotorGrid::PIN_ROW_7, OUTPUT);
  pinMode(MotorGrid::PIN_ROW_8, OUTPUT);
  
  pinMode(MotorGrid::PIN_COL_1, OUTPUT);
  pinMode(MotorGrid::PIN_COL_2, OUTPUT);
  pinMode(MotorGrid::PIN_COL_3, OUTPUT);
  pinMode(MotorGrid::PIN_COL_4, OUTPUT);
  pinMode(MotorGrid::PIN_COL_5, OUTPUT);
  pinMode(MotorGrid::PIN_COL_6, OUTPUT);
  pinMode(MotorGrid::PIN_COL_7, OUTPUT);
  pinMode(MotorGrid::PIN_COL_8, OUTPUT);
}

boolean MotorGrid::currentFlowing() {
  return this->ina219->getCurrent_mA() > 0;
}

boolean MotorGrid::isPresent(int row, int col) {
  this->on(row, col);
  delay(1000);
  this->off();
//  boolean retval = this->currentFlowing();

  return false;
}

boolean MotorGrid::vend(int row, int col) {
  return false;
}

void MotorGrid::on(int row, int col) {
  if(row < 1 || row > 8) return;
  if(col < 1 || col > 8) return;
  
  digitalWrite(MotorGrid::PIN_ROWS[row - 1], HIGH);
  digitalWrite(MotorGrid::PIN_COLS[col - 1], HIGH);
}

void MotorGrid::off() {
  digitalWrite(MotorGrid::PIN_ROW_1, LOW);
  digitalWrite(MotorGrid::PIN_ROW_2, LOW);
  digitalWrite(MotorGrid::PIN_ROW_3, LOW);
  digitalWrite(MotorGrid::PIN_ROW_4, LOW);
  digitalWrite(MotorGrid::PIN_ROW_5, LOW);
  digitalWrite(MotorGrid::PIN_ROW_6, LOW);
  digitalWrite(MotorGrid::PIN_ROW_7, LOW);
  digitalWrite(MotorGrid::PIN_ROW_8, LOW);
  
  digitalWrite(MotorGrid::PIN_COL_1, LOW);
  digitalWrite(MotorGrid::PIN_COL_2, LOW);
  digitalWrite(MotorGrid::PIN_COL_3, LOW);
  digitalWrite(MotorGrid::PIN_COL_4, LOW);
  digitalWrite(MotorGrid::PIN_COL_5, LOW);
  digitalWrite(MotorGrid::PIN_COL_6, LOW);
  digitalWrite(MotorGrid::PIN_COL_7, LOW);
  digitalWrite(MotorGrid::PIN_COL_8, LOW);
}

