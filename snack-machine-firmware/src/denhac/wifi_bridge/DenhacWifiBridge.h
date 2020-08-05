#pragma once

#include "Arduino.h"
#include "config.h"
#include "vendingMachine.h"
#include "msgpck.h"
#include "denhac/wifi_bridge/RestRequest.h"

#include "denhac/data/BridgeStatus.h"
#include "denhac/data/OrderStatus.h"

#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

class DenhacWifiBridge: public VendingMachine {
  public:
    static void setup();
    static void loop();
    static void sendDebug(String msg);

  private:
    static void setupComm();
    static void sendStatus(uint8_t status);
    static void sendOrder(JsonObject &order);
    static void sendItem(JsonObject &item);

    static void sendDebug(uint32_t value);

    static bool handleCommonRestIssues(RestResponse * response); // return true if REST response is valid
    static void handleIncomingRequest();

    static void waitForAck();
    static void packetWritten(uint8_t maxPacketSize);
    static void waitForAckIfNeededFor(uint8_t maxPacketSize);

    static void fetchProducts();
    static void fetchOrdersByCard(uint32_t cardNumber);
    static void fetchOrderById(uint32_t orderId);
    static void updateOrder();
    static void cancelOrderById(uint32_t orderId);
    static void fetchCreditByCard(uint32_t cardNumber);
    static void updateCreditByCard(uint32_t cardNumber, int32_t difference);

    static WiFiClientSecure client;
    static HardwareSerial* serial;
    static DynamicJsonDocument jsonDoc;
    static uint32_t hashes[];
    static bool has_product[];
    static RestRequest request;
    static char urlBuffer[];
    static uint8_t packetMaxSizeSent;
};