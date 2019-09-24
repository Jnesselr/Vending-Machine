#ifdef GIZMODOJO_BOARD_CONFIG

class GizmoDojoBoard: public VendingMachine {
  public:
    void setup();
    void loop();
};

VendingMachine* VendingMachine::instance = new GizmoDojoBoard();

void GizmoDojoBoard::setup() {
  Serial.begin(9600);
}

void GizmoDojoBoard::loop() {
  Serial.println("Hello World from the Gizmo Dojo!");
}

#endif
