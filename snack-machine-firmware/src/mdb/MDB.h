#ifndef _MDB_H_
#define _MDB_H_

#include "mdb/RingBuffer.h"

class MDBResult {
  public:
    MDBResult();

    void reset();

    void print(const char type[]);

    uint16_t data[64];
    uint8_t length;
    bool timeout;
    bool checksumValid;

    static const uint16_t ACK = 0x100;
};

typedef void (*MDBCallback)(MDBResult);

class MDBCommand {
  public:
    MDBCommand();
    MDBCommand(const uint16_t* data, size_t length);
    MDBCommand(const uint16_t* data, size_t length, MDBCallback timeout);
    MDBCommand(const uint16_t* data, size_t length, MDBCallback timeout, MDBCallback success);
    MDBCommand(const MDBCommand&);

    ~MDBCommand();

    void run();

  private:
    uint16_t* data;
    size_t length;
    MDBCallback timeout = NULL;
    MDBCallback success = NULL;
};

class MDB {
  public:
    static void setup();
    
    static void writeForResult(const uint16_t data[], size_t length, MDBResult* result);

    static void process(const MDBCommand &command);

    static void ack();
    static void copyAtMost16(const MDBResult &mdbResult, uint8_t start, uint8_t destination[16]);
  private:
    static void write(const uint16_t data[], size_t length);
    static const int BAUD_RATE = 9600;
};

#endif
