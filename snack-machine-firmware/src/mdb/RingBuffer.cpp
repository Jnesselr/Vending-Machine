#include "mdb/RingBuffer.h"

RingBuffer::RingBuffer() {
    memset(ringBuffer, 0, RING_BUFFER_SIZE);

    head = 0;
    tail = 0;
}

boolean RingBuffer::isEmpty() {
    return head == tail;
}

boolean RingBuffer::isFull() {
    return ((head + 1) % RING_BUFFER_SIZE) == tail;
}

uint8_t RingBuffer::count() {
    return (head + RING_BUFFER_SIZE - tail) % RING_BUFFER_SIZE;
}

void RingBuffer::push(uint16_t data) {
    if(isFull()) {
        return;
    }

    uint8_t next = (head + 1) % RING_BUFFER_SIZE;

    // Serial.print(F(" 0x"));
    // Serial.print(data, HEX);

    ringBuffer[head] = data;
    head = next;
}

uint16_t RingBuffer::pop() {
    if(isEmpty()) {
        return -1;
    }

    uint16_t result = ringBuffer[tail];

    ringBuffer[tail] = 0;

    tail = (tail + 1) % RING_BUFFER_SIZE;

    return result;
}