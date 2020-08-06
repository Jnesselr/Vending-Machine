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
typedef void (*OrderResponseCallback)(const Order& order);
typedef void (*CreditResponseCallback)(uint32_t credit);

struct CardRequest {
  uint32_t cardNumber;
};

struct OrderRequest {
  uint32_t orderId;
};

union SiteLinkCommandBuffer {
  struct CardRequest cardRequest;
  struct OrderRequest orderRequest;
  uint8_t bytes[max(sizeof(CardRequest), sizeof(OrderRequest))];
};

enum class SiteLinkCommandType : uint8_t {
  UNKNOWN,
  GET_PRODUCTS,
  GET_ORDERS_BY_CARD,
  GET_ORDER_BY_ID,
  GET_CREDIT_BY_CARD,
};

class SiteLinkCommand {
  public:
    SiteLinkCommand();
    SiteLinkCommand(const SiteLinkCommand&);
    void operator = (const SiteLinkCommand&);

    void run();

    HardwareSerial* linkSerial;
    SiteLinkCommandType type;
    BridgeStatusCallback errorCallback;
    VoidCallback commandCallback;
    SiteLinkCommandBuffer buffer;
  private:
    void runGetProducts();
    void runOrdersByCard();
    void runOrderById();
    void runCreditByCard();
};

class SiteLink {
  public:
    static void setup();
    static void loop();

    static void getOrdersByCard(
      uint32_t cardNumber,
      BridgeStatusCallback onStatus,
      OrdersResponseCallback onOrders);
    static void getOrderById(
      uint32_t id,
      BridgeStatusCallback onStatus,
      OrderResponseCallback onOrder);
    static void getCreditByCard(
      uint32_t cardNumber,
      BridgeStatusCallback onStatus,
      CreditResponseCallback onCredit);

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
    static void maybeSendCommand();

    static void waitForAck();
    static void packetWritten(uint8_t maxPacketSize);
    static void waitForAckIfNeededFor(uint8_t maxPacketSize);
    static void ack();
    static void packetRead(uint8_t maxPacketSize);
    static void ackIfNeededFor(uint8_t maxPacketSize);

    static void handleStatus();
    static void handleProductUpdated();
    static void handleAfterFirstProductFetched();
    static void handleOrdersByCard();
    static void handleOrdersById();
    static void handleProductRemoved();
    static void handleCreditByCard();

    static Order readOrder();
    static Item readItem();

    static void updateState(SiteLinkState state);

    static SiteLinkState state;

    static OutputPort<PORT_H, 6, 1> huzzahResetPin;
    static HardwareSerial* linkSerial;
    static uint8_t handshakeCount;
    static uint8_t garbageLoopCount;
    static bool safeToSendCommand;
    static bool firstProductFetch;
    static bool hasProduct[64];
    static uint8_t packetMaxSizeSent;
    static uint8_t packetMaxSizeRead;
    static unsigned long lastCommandRunMillis;
};