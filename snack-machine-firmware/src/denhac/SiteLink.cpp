#ifdef VENDING_MAIN_BOARD

#include "denhac/SiteLink.h"
#include "denhac/BridgeStatus.h"
#include "msgpck.h"

SiteLinkStatus SiteLink::status = SiteLinkStatus::UNKNOWN;

OutputPort<PORT_H, 6, 1> SiteLink::huzzahResetPin;
HardwareSerial* SiteLink::linkSerial = &Serial1;
uint8_t SiteLink::handshakeCount = 0;
uint8_t SiteLink::garbageLoopCount = 0;

void SiteLink::setup() {
  linkSerial->begin(115200);
}

void SiteLink::loop() {
  if(status == SiteLinkStatus::UNKNOWN) {
    // We might have just powered on or forced a reset
    // Bring the reset pin low to be safe
    huzzahResetPin.write(0x0);

    status = SiteLinkStatus::WAITING;
  }

  // Don't read more than X bytes in one go
  int bytesToRead = min(linkSerial->available(), 100);

  if(status == SiteLinkStatus::WAITING) {
    while(bytesToRead > 0) {
      if(msgpck_nil_next(linkSerial)) {
        handshakeCount++;

        // Only respond at exactly 5 because we may read more in
        // this loop alone
        if(handshakeCount == 5) {
          msgpck_write_nil(linkSerial); // Initiate the handshake
          status = SiteLinkStatus::HANDSHAKE;
        }
      } else {
        handshakeCount = 0;
      }

      int readValue = linkSerial->read();
      bytesToRead--;
    }

    // We do this regardless of whether we read bytes
    // This code doesn't run if the status isn't WAITING
    // It's only used to determine if the HUZZAH needs a reset
    garbageLoopCount++;

    if(garbageLoopCount > 10) {
      Serial.println("Resetting!");
      huzzahResetPin.write(0xFF);
      status = SiteLinkStatus::UNKNOWN;
      garbageLoopCount = 0;
    }
    return;
  }
  
  if(status == SiteLinkStatus::HANDSHAKE) {
    if(bytesToRead > 0) {
      // We might still have some NILs in the buffer to dispose of
      while(msgpck_nil_next(linkSerial)) {
        linkSerial->read();
      }

      // Try to read the READY status message
      uint8_t typeCode = 0;
      msgpck_read_integer(linkSerial, (byte*) &typeCode, sizeof(typeCode));
      uint8_t statusCode = 0;
      msgpck_read_integer(linkSerial, (byte*) &statusCode, sizeof(statusCode));
      if(typeCode == 0x01 && statusCode == BridgeStatus::READY) {
        Serial.println("We did it!");
        status = SiteLinkStatus::IDLE;
      } else {
        Serial.println("Oh no, something went wrong!");
        Serial.println(typeCode, HEX);
        Serial.println(statusCode, HEX);
      }
      Serial.flush();
    }
  }
}

#endif