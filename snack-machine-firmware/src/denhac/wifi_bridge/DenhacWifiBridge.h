#pragma once

#include "Arduino.h"
#include "config.h"
#include "vendingMachine.h"
#include "msgpck.h"
#include "denhac/Product.h"
#include "denhac/wifi_bridge/RestRequest.h"

#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

typedef enum {
  READY = 0x01,
  WIFI_TRYING_TO_CONNECT = 0x02,
  WIFI_CONNECTED = 0x03,
  FETCHING_PRODUCTS = 0x07,
  FETCHING_ORDERS = 0x08,
  CONNECTION_FAILED = 0x09,
  JSON_DECODE_FAILED = 0x0A,
  REST_UNKNOWN_FAILURE = 0x0B,
  REST_NOT_FOUND = 0x0C,
  PRODUCTS_FETCHED = 0x0D,
  UPDATING_ORDER = 0x0E,
  CANCELLING_ORDER = 0x0F,
  ORDER_CANCELLED = 0x10,
} Status;

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
    static void handleCardResponse();

    static void fetchProducts();
    static void fetchOrdersByCard(uint32_t cardNumber);
    static void fetchOrderById(uint32_t orderId);
    static void updateOrder();
    static void cancelOrderById(uint32_t orderId);

    static WiFiClientSecure client;
    static HardwareSerial* serial;
    static DynamicJsonDocument jsonDoc;
    static uint32_t hashes[];
    static bool has_product[];
    static RestRequest request;
    static char urlBuffer[];

    static unsigned long lastProductUpdateMillis;
};