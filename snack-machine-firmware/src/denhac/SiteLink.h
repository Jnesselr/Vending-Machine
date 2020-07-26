#pragma once

#include <HardwareSerial.h>
#include <DirectIO.h>

enum class SiteLinkState {
  UNKNOWN,
  WAITING,
  HANDSHAKE,
  IDLE
};

typedef void (*BridgeStatusCallback)(uint8_t statusCode);
typedef void (*ProductUpdatedCallback)(
  uint32_t id,
  char name[51],
  uint32_t price,
  uint8_t stock,
  uint8_t row,
  uint8_t col
);

typedef void (*ProductRemovedCallback)(uint8_t row, uint8_t col);

class SiteLink {
  public:
    static void setup();
    static void loop();

    // Status refers
    static BridgeStatusCallback statusCallback;
    static ProductUpdatedCallback productUpdatedCallback;
    static ProductRemovedCallback productRemovedCallback;
  private:
    static void handleWaiting();
    static void handleHandshake();
    static void handleNormalCommands();

    static void handleStatus();
    static void handleProductUpdated();
    static void handleProductRemoved();

    static SiteLinkState state;

    static OutputPort<PORT_H, 6, 1> huzzahResetPin;
    static HardwareSerial* linkSerial;
    static uint8_t handshakeCount;
    static uint8_t garbageLoopCount;
};