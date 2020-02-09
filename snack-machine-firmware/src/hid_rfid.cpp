#ifdef VENDING_MAIN_BOARD

#include <Arduino.h>
#include "hid_rfid.h"

uint8_t RFID::cardBits[RFID::MAX_BITS / 8];
uint8_t RFID::bitsRead = 0;
unsigned long RFID::lastBitReadAtMillis = 0;
bool RFID::isSetup = false;
CardScannedCallback RFID::onCardScanned = NULL;

void RFID::setup()
{
  if (isSetup)
    return;

  attachInterrupt(digitalPinToInterrupt(2), RFID::ISR_INT0, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), RFID::ISR_INT1, FALLING);

  isSetup = true;
}

void RFID::loop()
{
  if (!cardScanned())
  {
    return;
  }

  if (onCardScanned != NULL)
  {
    if (bitsRead == 35)
    {
      onCardScanned(RFID::getCardCode(14, 33));
    }
    else if (bitsRead == 26)
    {
      onCardScanned(RFID::getCardCode(9, 24));
    }
  }

  bitsRead = 0;
  lastBitReadAtMillis = 0;
  memset(cardBits, 0, sizeof(cardBits));
}

unsigned long RFID::getCardCode(uint8_t start, uint8_t end)
{
  unsigned long cardCode = 0;
  for (uint8_t i = start; i <= end; i++)
  {
    uint8_t index = i / 8;
    uint8_t bitPosition = i - (index * 8);
    bool bitSet = cardBits[index] & (1 << bitPosition);
    cardCode <<= 1;
    cardCode |= bitSet;
  }
  return cardCode;
}

void RFID::ISR_INT0()
{
  readInBit(0);
}

void RFID::ISR_INT1()
{
  readInBit(1);
}

void RFID::readInBit(bool bitValueIsOne)
{
  uint8_t index = bitsRead / 8;
  uint8_t bitPosition = bitsRead - (index * 8);
  cardBits[index] |= (bitValueIsOne << bitPosition);
  bitsRead++;
  lastBitReadAtMillis = millis();
}

/**
 * A card is considered scanned if we have any number of bits read
 * and at least 50 milliseconds has passed
 */
bool RFID::cardScanned()
{
  if (bitsRead == 0)
  {
    return false;
  }

  unsigned long elapsed = millis() - lastBitReadAtMillis;

  if (elapsed > 50)
  {
    return true;
  }
  return false;
}

#endif