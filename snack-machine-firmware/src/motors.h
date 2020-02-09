class Motors {
  public:
    static void setup();

    static void rotate(int row, int col);
  private:

    static const int MOTORS_ENABLE = 20;
    static const int MOTORS_FAULT = 21;
};