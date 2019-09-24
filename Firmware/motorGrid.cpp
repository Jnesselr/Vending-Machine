#include "motorGrid.h"

MotorGrid::MotorGrid() {
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

void MotorGrid::setup() {
  this->off();
}

boolean MotorGrid::currentFlowing() {
  float a = analogRead(A0);
  Serial.print(a);
  Serial.print(" ");
  boolean retval = a >= 4.0;
  Serial.println(retval);
  Serial.flush();
  return retval;
}

boolean MotorGrid::isPresent(int row, int col) {
  this->on(row, col);
  boolean retval = this->currentFlowing();
  for(int count = 0; count < 100; count++) {
    retval = this->currentFlowing();
  }
  this->off();
  Serial.println("Off");
  for(int count = 0; count < 100; count++) {
    retval = this->currentFlowing();
  }

  return retval;
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

