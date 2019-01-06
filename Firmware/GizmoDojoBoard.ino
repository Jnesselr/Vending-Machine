#ifdef GIZMODOJO_BOARD_CONFIG

class GizmoDojoBoard: public VendingMachine {
  public:
    void setup() {
      Serial.begin(9600);
    }
    void loop() {
      Serial.println("Hello World from the Gizmo Dojo!");
    }
};

VendingMachine* VendingMachine::instance = new GizmoDojoBoard();

#endif
