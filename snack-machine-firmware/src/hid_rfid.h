#ifndef _HID_RFID_H_
#define _HID_RFID_H_

// TODO Some sort of "on card scanned code"
// More than likely, we'll have to figure out the various
// different formats that can happen, but we'll just give them the
// "card code" as bytes.k

typedef void (*CardScannedCallback)(unsigned long cardCode);

class RFID
{
public:
  static void setup();
  static void loop();

  static CardScannedCallback onCardScanned;
private:
  static bool cardScanned();
  static void ISR_INT0();
  static void ISR_INT1();
  static void readInBit(bool bitValueIsOne);
  static unsigned long getCardCode(uint8_t start, uint8_t end);

  static const int MAX_BITS = 128;
  static uint8_t cardBits[];
  static uint8_t bitsRead;
  static unsigned long lastBitReadAtMillis;
  static bool isSetup;
};

#endif