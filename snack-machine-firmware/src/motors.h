class Motors {
  public:
    static void setup();

    static bool exists(int row, int col);
    static void vend(int row, int col);
    static void off();
  private:
    static bool valid(int row, int col);

    static const int MOTORS_ENABLE = 20;
    static const int MOTORS_SENSE = PIN_A12;
    static const int ROW_1 = 49;
    static const int ROW_2 = 48;
    static const int ROW_3 = 47;
    static const int ROW_4 = 46;
    static const int ROW_5 = 45;
    static const int ROW_6 = 44;
    static const int ROW_7 = 43;
    static const int ROW_8 = 42;
    static const int COL_1 = 37;
    static const int COL_2 = 36;
    static const int COL_3 = 35;
    static const int COL_4 = 34;
    static const int COL_5 = 33;
    static const int COL_6 = 32;
    static const int COL_7 = 31;
    static const int COL_8 = 30;

    static const int ROWS[8];
    static const int COLS[8];
};