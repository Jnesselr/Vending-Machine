#include "Arduino.h"

#include "gizmodojo/GizmoDojoBoard.h"

void GizmoDojoBoard::setup() {
  Serial.begin(9600);
}

void GizmoDojoBoard::loop() {
  Serial.println("Hello World from the Gizmo Dojo!");
}