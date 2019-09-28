#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include "Arduino.h"

template <typename T>
class RingBuffer
{
public:
  RingBuffer();

  boolean isEmpty();
  boolean isFull();
  uint8_t count();

  void push(T data);
  T pop();

private:
  static const int RING_BUFFER_SIZE = 64;
  T ringBuffer[RING_BUFFER_SIZE];

  uint8_t head;
  uint8_t tail;
};

template <typename T>
RingBuffer<T>::RingBuffer()
{
  memset(ringBuffer, 0, RING_BUFFER_SIZE);

  head = 0;
  tail = 0;
}

template <typename T>
boolean RingBuffer<T>::isEmpty()
{
  return head == tail;
}

template <typename T>
boolean RingBuffer<T>::isFull()
{
  return ((head + 1) % RING_BUFFER_SIZE) == tail;
}

template <typename T>
uint8_t RingBuffer<T>::count()
{
  return (head + RING_BUFFER_SIZE - tail) % RING_BUFFER_SIZE;
}

template <typename T>
void RingBuffer<T>::push(T data)
{
  if (isFull())
  {
    return;
  }

  uint8_t next = (head + 1) % RING_BUFFER_SIZE;

  // Serial.print(F(" 0x"));
  // Serial.print(data, HEX);

  ringBuffer[head] = data;
  head = next;
}

template <typename T>
T RingBuffer<T>::pop()
{
  if (isEmpty())
  {
    return -1;
  }

  uint16_t result = ringBuffer[tail];

  ringBuffer[tail] = 0;

  tail = (tail + 1) % RING_BUFFER_SIZE;

  return result;
}

#endif