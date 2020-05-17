#pragma once

#include "Arduino.h"
#include "config.h"
#include "vendingMachine.h"
#include "msgpck.h"
#include "denhac/Product.h"

#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

typedef enum {
  READY = 0x01,
  WIFI_TRYING_TO_CONNECT = 0x02,
  WIFI_CONNECTED = 0x03,
  FETCHING_PRODUCTS = 0x07,
  CONNECTION_FAILED = 0x09,
  JSON_DECODE_FAILED = 0x0A,
} Status;

class DenhacWifiBridge: public VendingMachine {
  public:
    static void setup();
    static void loop();

  private:
    static void setupComm();
    static void sendStatus(uint8_t status);
    static void fetchProducts();

    static WiFiClientSecure client;
    static HardwareSerial* serial;
    static DynamicJsonDocument jsonDoc;
    static uint32_t hashes[];
    static bool has_product[];

    static unsigned long lastProductUpdateMillis;
    // static unsigned long lastOrderUpdateMillis;
};