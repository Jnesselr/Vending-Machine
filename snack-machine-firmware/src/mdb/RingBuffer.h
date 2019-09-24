#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include "Arduino.h"

class RingBuffer {
  public:
    RingBuffer();
    
    boolean isEmpty();
    boolean isFull();
    uint8_t count();

    void push(uint16_t data);
    uint16_t pop();
  private:
    static const int RING_BUFFER_SIZE = 64;
    uint16_t ringBuffer[RING_BUFFER_SIZE];

    uint8_t head;
    uint8_t tail;
};

#endif