#ifdef VENDING_MAIN_BOARD

#include "Arduino.h"
#include "motors.h"

const int Motors::ROWS[] = {
  Motors::ROW_1,
  Motors::ROW_2,
  Motors::ROW_3,
  Motors::ROW_4,
  Motors::ROW_5,
  Motors::ROW_6,
  Motors::ROW_7,
  Motors::ROW_8
};

const int Motors::COLS[] = {
  Motors::COL_1,
  Motors::COL_2,
  Motors::COL_3,
  Motors::COL_4,
  Motors::COL_5,
  Motors::COL_6,
  Motors::COL_7,
  Motors::COL_8
};

void Motors::setup() {
  pinMode(ROWS[0], OUTPUT);
  pinMode(ROWS[1], OUTPUT);
  pinMode(ROWS[2], OUTPUT);
  pinMode(ROWS[3], OUTPUT);
  pinMode(ROWS[4], OUTPUT);
  pinMode(ROWS[5], OUTPUT);
  pinMode(ROWS[6], OUTPUT);
  pinMode(ROWS[7], OUTPUT);
  pinMode(COLS[0], OUTPUT);
  pinMode(COLS[1], OUTPUT);
  pinMode(COLS[2], OUTPUT);
  pinMode(COLS[3], OUTPUT);
  pinMode(COLS[4], OUTPUT);
  pinMode(COLS[5], OUTPUT);
  pinMode(COLS[6], OUTPUT);
  pinMode(COLS[7], OUTPUT);
  Motors::off();

  pinMode(MOTORS_ENABLE, OUTPUT);
  digitalWrite(MOTORS_ENABLE, LOW);

  pinMode(MOTORS_SENSE, INPUT);
}

bool Motors::exists(int row, int col) {
  if(!valid(row, col)) {
    return false;
  }

  bool result = false;

  digitalWrite(MOTORS_ENABLE, LOW);
  digitalWrite(ROWS[row], HIGH);
  digitalWrite(COLS[col], HIGH);
  delay(1000);
  int value = analogRead(MOTORS_SENSE);
  if(value < 100) {
    result = true;
  }
  off();

  return result;
}

void Motors::vend(int row, int col) {
  if(!Motors::valid(row, col)) {
    return;
  }
  
  digitalWrite(MOTORS_ENABLE, HIGH);
  digitalWrite(ROWS[row], HIGH);
  digitalWrite(COLS[col], HIGH);
  delay(400);
  digitalWrite(COLS[col], LOW);
  delay(3000);
  off();
}

void Motors::off() {
  digitalWrite(MOTORS_ENABLE, LOW);
  digitalWrite(ROWS[0], LOW);
  digitalWrite(ROWS[1], LOW);
  digitalWrite(ROWS[2], LOW);
  digitalWrite(ROWS[3], LOW);
  digitalWrite(ROWS[4], LOW);
  digitalWrite(ROWS[5], LOW);
  digitalWrite(ROWS[6], LOW);
  digitalWrite(ROWS[7], LOW);
  digitalWrite(COLS[0], LOW);
  digitalWrite(COLS[1], LOW);
  digitalWrite(COLS[2], LOW);
  digitalWrite(COLS[3], LOW);
  digitalWrite(COLS[4], LOW);
  digitalWrite(COLS[5], LOW);
  digitalWrite(COLS[6], LOW);
  digitalWrite(COLS[7], LOW);
}

bool Motors::valid(int row, int col) {
  if(row < 1) return false;
  if(row > 8) return false;
  if(col < 1) return false;
  if(col > 8) return false;
  return true;
}

#endif