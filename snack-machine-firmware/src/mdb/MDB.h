#ifndef _MDB_H_
#define _MDB_H_

#include "mdb/RingBuffer.h"

class MDBResult {
  public:
    MDBResult();

    void reset();

    uint16_t data[64];
    uint8_t length;
    bool timeout;

    static const uint16_t ACK = 0x100;
};

class MDB {
  public:
    static void setup();
    
    static void write(const uint16_t data[], size_t length);
    static void writeForResult(const uint16_t data[], size_t length, MDBResult* result);

    static void ack();
  private:
    static const int BAUD_RATE = 9600;
};

#endif
