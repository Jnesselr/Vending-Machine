#include "Arduino.h"
#include "motors.h"

static const int COL_1 = 37;
static const int COL_2 = 36;
static const int COL_3 = 35;
static const int COL_4 = 34;
static const int COL_5 = 33;
static const int COL_6 = 32;
static const int COL_7 = 31;
static const int COL_8 = 30;

const int ROWS[] = {49, 48, 47, 46, 45, 44, 43, 42};

const int COLS[] = {37, 36, 35, 34, 33, 32, 31, 30};

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
  pinMode(Motors::MOTORS_ENABLE, OUTPUT);
  digitalWrite(MOTORS_ENABLE, HIGH);
}

void Motors::rotate(int row, int col) {
  digitalWrite(ROWS[row], HIGH);
  digitalWrite(COLS[col], HIGH);
  delay(1000);
  digitalWrite(COLS[col], LOW);
}