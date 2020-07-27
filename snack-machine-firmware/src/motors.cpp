#ifdef VENDING_MAIN_BOARD

#include "Arduino.h"
#include "motors.h"
#include "utils.h"

MotorSystemState Motors::systemState = MotorSystemState::UNKNOWN;
MotorState Motors::motorState = MotorState::NONE_SELECTED;

unsigned long Motors::lastStateChangeTime = 0;
uint64_t Motors::motorsScanResult = 0;
uint8_t Motors::selectedRow = 0;
uint8_t Motors::selectedCol = 0;

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

void Motors::loop() {
  if(systemState == MotorSystemState::UNKNOWN) {
    // It's fine to immediately go to the scanning state
    systemState = MotorSystemState::SCANNING;
  }

  if(systemState == MotorSystemState::SCANNING) {
    handleInitialScan();
    return;
  }

  if(motorState == MotorState::VEND_START) {
    LOOP_WAIT_MS(lastStateChangeTime, 400);

    digitalWrite(COLS[selectedCol], LOW);
    motorState = MotorState::VEND_WAIT;
    lastStateChangeTime = current_loop_millis;
  } else if (motorState == MotorState::VEND_WAIT) {
    LOOP_WAIT_MS(lastStateChangeTime, 3000);

    off();
    selectedRow = 0;
    selectedCol = 0;
    lastStateChangeTime = current_loop_millis;
  }
}

void Motors::handleInitialScan() {
  if(motorState == MotorState::NONE_SELECTED) {
    digitalWrite(MOTORS_ENABLE, LOW);
    digitalWrite(ROWS[selectedRow], HIGH);
    digitalWrite(COLS[selectedCol], HIGH);
    lastStateChangeTime = current_loop_millis;
    motorState = MotorState::SCAN_SELECTED;
    return;
  } else if(motorState == MotorState::SCAN_SELECTED) {
    // Wait at least 20ms
    LOOP_WAIT_MS(lastStateChangeTime, 20)

    // Serial.print("Motor (");
    // Serial.print(selectedRow);
    // Serial.print(", ");
    // Serial.print(selectedCol);
    // Serial.print(") ");

    int value = analogRead(MOTORS_SENSE);
    if(value < 100) {
      uint64_t mask = 1 << (8 * selectedRow + selectedCol);
      motorsScanResult |= mask;
      // Serial.println("EXISTS");
    } else {
      // Serial.println("does NOT exist");
    }
    // Serial.flush();

    off();

    selectedCol++;
    if(selectedCol == 9) {
      selectedRow++;
      selectedCol = 0;
    }

    // Are we done!
    if(selectedRow == 9) {
      // Sane values
      selectedRow = 0;
      selectedCol = 0;
      systemState = MotorSystemState::IDLE;
    }
  }
}

/**
 * row - Row 0-7
 * col - Col 0-7
 */
bool Motors::exists(int row, int col) {
  if(!valid(row, col)) {
    return false;
  }

  uint64_t mask = 1 << (8 * row + col);
  return motorsScanResult & mask;
}

/**
 * row - Row 0-7
 * col - Col 0-7
 */
void Motors::vend(int row, int col) {
  if(!Motors::valid(row, col)) {
    return;
  }

  if(systemState != MotorSystemState::IDLE) {
    return;
  }

  if(motorState == MotorState::SCAN_SELECTED) {
    // Sorry if you were scanning, vending takes priority
    off();
  } else if(motorState != MotorState::NONE_SELECTED) {
    // Something is already vending, so you can't vend
    return;
  }

  digitalWrite(MOTORS_ENABLE, HIGH);
  digitalWrite(ROWS[row], HIGH);
  digitalWrite(COLS[col], HIGH);
  selectedRow = row;
  selectedCol = col;
  motorState = MotorState::VEND_START;
  lastStateChangeTime = current_loop_millis;
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
  motorState = MotorState::NONE_SELECTED;
}

bool Motors::valid(int row, int col) {
  if(row < 0) return false;
  if(row > 7) return false;
  if(col < 0) return false;
  if(col > 7) return false;
  return true;
}

#endif