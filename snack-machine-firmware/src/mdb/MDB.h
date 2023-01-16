#pragma once

#include "mdb/RingBuffer.h"
#include "utils.h"

class MDBResult {
  public:
    MDBResult();

    void reset();

    void print(const char type[]) const;

    uint16_t data[64];
    uint8_t length;
    bool timeout;
    bool checksumValid;

    static const uint16_t ACK = 0x100;
};

class MDBCommand {
  public:
    MDBCommand();
    MDBCommand(const uint16_t* data, size_t length);
    MDBCommand(const uint16_t* data, size_t length, VoidCallback timeout);
    MDBCommand(const uint16_t* data, size_t length, VoidCallback timeout, VoidCallback success);
    MDBCommand(const MDBCommand&);

    void operator = (const MDBCommand&);

    void run();
    void print(const char type[]) const;

  private:
    static const uint8_t DATA_SIZE = 40;
    uint16_t data[DATA_SIZE];
    size_t length;
    VoidCallback timeout = NULL;
    VoidCallback success = NULL;
};

class MDB {
  public:
    static void setup();
    
    static void writeForResult(const uint16_t data[], size_t length);

    static void ack();
    static void copyAtMost16(uint8_t start, uint8_t destination[16]);

    static MDBResult mdbResult;  // Global MDB result
  private:
    static void write(const uint16_t data[], size_t length);
    static const int BAUD_RATE = 9600;
};