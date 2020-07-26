#ifdef VENDING_MAIN_BOARD

#include "denhac/SiteLink.h"
#include "denhac/BridgeStatus.h"
#include "msgpck.h"

#include "utils.h"

BridgeStatusCallback SiteLink::statusCallback = nullptr;
ProductUpdatedCallback SiteLink::productUpdatedCallback = nullptr;
ProductRemovedCallback SiteLink::productRemovedCallback = nullptr;

SiteLinkState SiteLink::state = SiteLinkState::UNKNOWN;

OutputPort<PORT_H, 6, 1> SiteLink::huzzahResetPin;
HardwareSerial* SiteLink::linkSerial = &Serial1;
uint8_t SiteLink::handshakeCount = 0;
uint8_t SiteLink::garbageLoopCount = 0;

void SiteLink::setup() {
  linkSerial->begin(115200);
}

void SiteLink::loop() {
  if(state == SiteLinkState::UNKNOWN) {
    // We might have just powered on or forced a reset
    // Bring the reset pin low to be safe
    huzzahResetPin.write(0x0);

    state = SiteLinkState::WAITING;
  } else if(state == SiteLinkState::WAITING) {
    handleWaiting();
  } else if(state == SiteLinkState::HANDSHAKE) {
    handleHandshake();
  } else {
    handleNormalCommands();
  }
}

void SiteLink::handleWaiting() {
  // Don't read more than X bytes in one go
  int bytesToRead = min(linkSerial->available(), 100);

  while(bytesToRead > 0) {
    if(msgpck_nil_next(linkSerial)) {
      handshakeCount++;

      // Only respond at exactly 5 because we may read more in
      // this loop alone
      if(handshakeCount == 5) {
        msgpck_write_nil(linkSerial); // Initiate the handshake
        state = SiteLinkState::HANDSHAKE;
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
    huzzahResetPin.write(0xFF);
    state = SiteLinkState::UNKNOWN;
    garbageLoopCount = 0;
  }
}

void SiteLink::handleHandshake() {
  if(linkSerial->available() == 0) {
    return;
  }

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
    state = SiteLinkState::IDLE;
    CALLBACK(statusCallback, statusCode);
  } else {
    Serial.println("Oh no, something went wrong!");
    Serial.println(typeCode, HEX);
    Serial.println(statusCode, HEX);
  }
  Serial.flush();
}

void SiteLink::handleNormalCommands() {
  if(linkSerial->available() == 0) {
    return;
  }

  uint8_t typeCode = 0;
  msgpck_read_integer(linkSerial, (byte*) &typeCode, sizeof(typeCode));

  switch (typeCode)
  {
  case 1:
    handleStatus();
    break;
  case 2:
    handleProductUpdated();
    break;
  case 6:
    handleProductRemoved();
    break;
  default:
    Serial.println("Unknown type code!");
    Serial.println(typeCode, HEX);
    while(true) {}
    break;
  }
}

void SiteLink::handleStatus() {
  Serial.println("Status code!");
  uint8_t statusCode = 0;
  msgpck_read_integer(linkSerial, (byte*) &statusCode, sizeof(statusCode));
  Serial.print("Code is: ");
  Serial.println(statusCode, HEX);
  Serial.flush();

  CALLBACK(statusCallback, statusCode);
}

void SiteLink::handleProductUpdated() {
  Serial.println("Product updated!");

  uint32_t id = 0;
  char name[51];
  memset(name, 0, sizeof(name));
  uint32_t price = 0;
  uint8_t stock = 0;
  uint8_t row = 0;
  uint8_t col = 0;

  msgpck_read_integer(linkSerial, (byte*) &id, sizeof(id));
  msgpck_read_string(linkSerial, name, sizeof(name));
  msgpck_read_integer(linkSerial, (byte*) &price, sizeof(price));
  msgpck_read_integer(linkSerial, (byte*) &stock, sizeof(stock));
  msgpck_read_integer(linkSerial, (byte*) &row, sizeof(row));
  msgpck_read_integer(linkSerial, (byte*) &col, sizeof(col));
  Serial.println(id);
  Serial.println(name);
  Serial.println(price);
  Serial.println(stock);
  Serial.println(row);
  Serial.println(col);

  CALLBACK(productUpdatedCallback, id, name, price, stock, row, col)
}

void SiteLink::handleProductRemoved() {
  Serial.println("Product removed!");

  uint8_t row = 0;
  uint8_t col = 0;

  msgpck_read_integer(linkSerial, (byte*) &row, sizeof(row));
  msgpck_read_integer(linkSerial, (byte*) &col, sizeof(col));
  Serial.println(row);
  Serial.println(col);

  CALLBACK(productRemovedCallback, row, col)
}

#endif