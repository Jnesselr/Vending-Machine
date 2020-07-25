#pragma once

#include "Arduino.h"

template <uint8_t bufferSize, typename T>
class RingBuffer
{
public:
  RingBuffer(const T& notFoundValue);

  boolean isEmpty();
  boolean isFull();
  uint8_t count();

  void push(T data);
  T pop();
  void clear();

private:
  T ringBuffer[bufferSize];
  const T notFoundValue;

  uint8_t head;
  uint8_t tail;
};

template <uint8_t bufferSize, typename T>
RingBuffer<bufferSize, T>::RingBuffer(const T& notFoundValue) : notFoundValue(notFoundValue)
{
  memset(ringBuffer, 0, sizeof(T) * bufferSize);

  head = 0;
  tail = 0;
}

template <uint8_t bufferSize, typename T>
boolean RingBuffer<bufferSize, T>::isEmpty()
{
  return head == tail;
}

template <uint8_t bufferSize, typename T>
boolean RingBuffer<bufferSize, T>::isFull()
{
  return ((head + 1) % bufferSize) == tail;
}

template <uint8_t bufferSize, typename T>
uint8_t RingBuffer<bufferSize, T>::count()
{
  return (head + bufferSize - tail) % bufferSize;
}

template <uint8_t bufferSize, typename T>
void RingBuffer<bufferSize, T>::push(T data)
{
  if (isFull())
  {
    return;
  }

  uint8_t next = (head + 1) % bufferSize;

  ringBuffer[head] = data;
  head = next;
}

template <uint8_t bufferSize, typename T>
T RingBuffer<bufferSize, T>::pop()
{
  if (isEmpty())
  {
    return notFoundValue;
  }

  T result = ringBuffer[tail];

  ringBuffer[tail] = notFoundValue;

  tail = (tail + 1) % bufferSize;

  return result;
}

template <uint8_t bufferSize, typename T>
void RingBuffer<bufferSize, T>::clear()
{
  head = 0;
  tail = 0;
}
