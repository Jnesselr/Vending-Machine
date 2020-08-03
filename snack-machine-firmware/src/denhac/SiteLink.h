#pragma once

#include <HardwareSerial.h>
#include <DirectIO.h>

#include "mdb/RingBuffer.h"
#include "denhac/data/Order.h"
#include "denhac/data/Product.h"

#include "utils.h"

enum class SiteLinkState {
  UNKNOWN,
  WAITING,
  HANDSHAKE,
  IDLE,
};

typedef void (*SiteLinkStateCallback)(SiteLinkState oldState, SiteLinkState newState);
typedef void (*BridgeStatusCallback)(uint8_t statusCode);
typedef void (*ProductUpdatedCallback)(const Product& product);
typedef void (*ProductRemovedCallback)(uint8_t row, uint8_t col);

typedef void (*OrdersResponseCallback)(Order orders[], uint8_t numOrders);

class SiteLinkCommand {
  public:
    SiteLinkCommand();
    SiteLinkCommand(BridgeStatusCallback onError);
    SiteLinkCommand(BridgeStatusCallback onError, OrdersResponseCallback onOrders);

    BridgeStatusCallback errorCallback;
    VoidCallback commandCallback;
};

class SiteLink {
  public:
    static void setup();
    static void loop();

    static void getOrdersByCard(
      uint32_t cardNumber,
      BridgeStatusCallback onStatus,
      OrdersResponseCallback onOrders);


    // Callbacks
    static SiteLinkStateCallback onStateChanged;
    // Status refers to the status sent from the
    // bridge not the state of the link itself.
    static BridgeStatusCallback statusCallback;
    static ProductUpdatedCallback productUpdatedCallback;
    static ProductRemovedCallback productRemovedCallback;
  private:
    static RingBuffer<8, SiteLinkCommand> commandBuffer;

    static void handleWaiting();
    static void handleHandshake();
    static void handleNormalCommands();

    static void ack();

    static void handleStatus();
    static void handleProductUpdated();
    static void handleAfterFirstProductFetched();
    static void handleOrdersByCard();
    static void handleProductRemoved();

    static Order readOrder();
    static Item readItem();

    static void updateState(SiteLinkState state);

    static SiteLinkState state;

    static OutputPort<PORT_H, 6, 1> huzzahResetPin;
    static HardwareSerial* linkSerial;
    static uint8_t handshakeCount;
    static uint8_t garbageLoopCount;
    static bool fetchingProducts;
    static bool firstProductFetch;
    static bool hasProduct[64];
};