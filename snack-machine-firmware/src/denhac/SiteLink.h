#pragma once

#include <HardwareSerial.h>
#include <DirectIO.h>

enum class SiteLinkStatus {
  UNKNOWN,
  WAITING,
  HANDSHAKE,
  IDLE
};

class SiteLink {
  public:
    static void setup();
    static void loop();
  private:
    static void handleWaiting();
    static void handleHandshake();

    static SiteLinkStatus status;

    static OutputPort<PORT_H, 6, 1> huzzahResetPin;
    static HardwareSerial* linkSerial;
    static uint8_t handshakeCount;
    static uint8_t garbageLoopCount;
};