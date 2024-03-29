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

typedef void (*OrderResponseCallback)(const Order& order);
typedef void (*CreditResponseCallback)(uint32_t credit, bool useRFIDForPayment);
typedef void (*CreditUpdateResponseCallback)(uint32_t totalCredit, uint32_t diffCredit);

struct CardRequest {
  uint32_t cardNumber;
};

struct OrderRequest {
  uint32_t orderId;
};

struct CreditUpdateRequest {
  uint32_t cardNumber;
  uint32_t amount;
};

struct UpdateOrderItemRequest {
  uint32_t productId;
  uint8_t wanted;
  uint8_t vended;
};

struct UpdateOrderRequest {
  uint32_t orderId;
  uint32_t cardNumber;
  uint32_t cash;
  uint8_t numItems;
  struct UpdateOrderItemRequest itemUpdates[8];
};

constexpr size_t bufferSize = max(max(max(
  sizeof(CardRequest),
  sizeof(OrderRequest)),
  sizeof(CreditUpdateRequest)),
  sizeof(UpdateOrderRequest)
);

union SiteLinkCommandBuffer {
  struct CardRequest cardRequest;
  struct OrderRequest orderRequest;
  struct CreditUpdateRequest creditUpdateRequest;
  struct UpdateOrderRequest updateOrderRequest;

  // Bytes is included entirely so we can memcpy this structure easily
  uint8_t bytes[bufferSize];
};

enum class SiteLinkCommandType : uint8_t {
  UNKNOWN,
  GET_PRODUCTS,
  GET_ORDERS_BY_CARD,
  GET_ORDER_BY_ID,
  CANCEL_ORDER_BY_ID,
  UPDATE_ORDER,
  GET_CREDIT_BY_CARD,
  UPDATE_CREDIT_BY_CARD,
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
    void runCancelOrderById();
    void runUpdateOrder();
    void runCreditByCard();
    void runUpdateCreditByCard();
};

class SiteLinkAck {
  public:
    static void waitForAck();
    static void packetWritten(uint8_t maxPacketSize);
    static void waitForAckIfNeededFor(uint8_t maxPacketSize);
    static void ack();
    static void packetRead(uint8_t maxPacketSize);
    static void ackIfNeededFor(uint8_t maxPacketSize);
  private:
    static HardwareSerial* linkSerial;
    static uint8_t packetMaxSizeSent;
    static uint8_t packetMaxSizeRead;
};

class SiteLink {
  public:
    static void setup();
    static void loop();

    static void getOrdersByCard(
      uint32_t cardNumber,
      BridgeStatusCallback onStatus,
      OrderResponseCallback onOrder);
    static void getOrderById(
      uint32_t orderId,
      BridgeStatusCallback onStatus,
      OrderResponseCallback onOrder);
    static void cancelOrderById(
      uint32_t orderId,
      BridgeStatusCallback onStatus,
      VoidCallback onOrderCancelled);
    static void updateOrder(
      uint32_t cardNumber,
      uint32_t cash,
      Order &order,
      BridgeStatusCallback onStatus,
      OrderResponseCallback onOrder);
    static void updateOrder(
      UpdateOrderRequest updateOrderRequest,
      BridgeStatusCallback onStatus,
      OrderResponseCallback onOrder);
    static void getCreditByCard(
      uint32_t cardNumber,
      BridgeStatusCallback onStatus,
      CreditResponseCallback onCredit);
    static void updateCreditByCard(
      uint32_t cardNumber,
      uint32_t amount,
      BridgeStatusCallback onStatus,
      CreditUpdateResponseCallback onCreditUpdate);

    // Callbacks
    static SiteLinkStateCallback onStateChanged;
    // Status refers to the status sent from the
    // bridge not the state of the link itself.
    static BridgeStatusCallback statusCallback;
    static ProductUpdatedCallback productUpdatedCallback;
    static ProductRemovedCallback productRemovedCallback;
  private:
    static RingBuffer<3, SiteLinkCommand> commandBuffer;

    static void handleWaiting();
    static void handleHandshake();
    static void handleNormalCommands();
    static void maybeSendCommand();

    static void handleStatus();
    static void handleProductUpdated();
    static void handleOrdersByCard();
    static void handleOrderById();
    static void handleProductRemoved();
    static void handleCreditByCard();
    static void handleCreditUpdateByCard();

    static Order readOrder();
    static Item readItem();

    static void updateState(SiteLinkState state);
    static void reset();

    static SiteLinkState state;

    static OutputPort<PORT_H, 6, 1> huzzahResetPin;
    static HardwareSerial* linkSerial;
    static uint8_t handshakeCount;
    static uint8_t garbageLoopCount;
    static unsigned long resetTime;
    static bool safeToSendCommand;
    static bool firstProductFetch;
    static bool hasProduct[64];
    static unsigned long lastCommandRunMillis;
};