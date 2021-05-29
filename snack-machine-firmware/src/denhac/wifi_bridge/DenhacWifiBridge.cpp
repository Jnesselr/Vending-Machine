#ifdef VENDING_WIFI_BRIDGE_BOARD

#include "denhac/wifi_bridge/DenhacWifiBridge.h"
#include "denhac/data/MaxPacketSize.h"

#include "CRC32.h"

const char*  server = "www.denhac.org";  // Server URL

const char* root_ca = ROOT_CA;

const uint8_t NUM_PRODUCTS = 64;

HardwareSerial* DenhacWifiBridge::serial = &Serial;

WiFiClientSecure DenhacWifiBridge::client;
// This value is enough to handle 64 products and a variable number of orders
// We might want to implement paging to reduce the amount of memory needed here.
DynamicJsonDocument DenhacWifiBridge::jsonDoc(JSON_ARRAY_SIZE(NUM_PRODUCTS) + NUM_PRODUCTS*JSON_OBJECT_SIZE(8));
RestRequest DenhacWifiBridge::request(&client, &jsonDoc, server);
DebugCallback RestRequest::debug = &DenhacWifiBridge::sendDebug;
char DenhacWifiBridge::urlBuffer[100];

uint32_t DenhacWifiBridge::hashes[NUM_PRODUCTS];
bool DenhacWifiBridge::has_product[NUM_PRODUCTS];

uint8_t DenhacWifiBridge::packetMaxSizeSent = 0;
uint8_t DenhacWifiBridge::packetMaxSizeRead = 0;

void DenhacWifiBridge::setup() {
  pinMode(13, OUTPUT);
  serial->begin(115200);

  memset(hashes, 0, sizeof(uint32_t) * NUM_PRODUCTS);

  DenhacWifiBridge::setupComm();
  
  WiFi.begin(WIFI_SSID, WIFI_PSK);
  sendStatus(BridgeStatus::WIFI_TRYING_TO_CONNECT);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  sendStatus(BridgeStatus::WIFI_CONNECTED);
}

void DenhacWifiBridge::loop() {
  if(serial->available()) {
    handleIncomingRequest();
  }
}

void DenhacWifiBridge::handleIncomingRequest() {
  uint8_t requestType = 0;
  msgpck_read_integer(serial, &requestType, sizeof(requestType));

  if(requestType == 0x03) {
    uint32_t cardNumber = 0;
    msgpck_read_integer(serial, (byte*) &cardNumber, sizeof(cardNumber));

    fetchOrdersByCard(cardNumber);
  } else if(requestType == 0x04) {
    uint32_t orderId = 0;
    msgpck_read_integer(serial, (byte*) &orderId, sizeof(orderId));

    fetchOrderById(orderId);
  } else if(requestType == 0x05) {
    updateOrder();
  } else if(requestType == 0x08) {
    uint32_t orderId = 0;
    msgpck_read_integer(serial, (byte*) &orderId, sizeof(orderId));

    cancelOrderById(orderId);
  } else if(requestType == 0x09) {
    uint32_t cardNumber = 0;
    msgpck_read_integer(serial, (byte*) &cardNumber, sizeof(cardNumber));

    fetchCreditByCard(cardNumber);
  } else if(requestType == 0x0A) {
    uint32_t cardNumber = 0;
    msgpck_read_integer(serial, (byte*) &cardNumber, sizeof(cardNumber));

    int32_t difference = 0;
    msgpck_read_integer(serial, (byte*) &difference, sizeof(difference));

    updateCreditByCard(cardNumber, difference);
  } else if(requestType == 0x0B) {
    fetchProducts();
  }
}

void DenhacWifiBridge::fetchProducts() {
  sendStatus(BridgeStatus::FETCHING_PRODUCTS);

  RestResponse* response = request.GET("/wp-json/wc-vending/v1/products");

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  memset(has_product, false, sizeof(bool) * NUM_PRODUCTS);

  JsonArray array = jsonDoc.as<JsonArray>();
  for(JsonObject obj : array) {
    uint32_t id = obj["id"];
    const char * name_ref = obj["name"];
    uint32_t name_length = strlen(name_ref);
    if(name_length > 46) {
      name_length = 46;
    }
    uint32_t price = obj["price"];
    uint8_t stock_available = obj["stock_available"];
    uint8_t stock_in_machine = obj["stock_in_machine"];
    const char * location_ref = obj["location"];
    uint8_t row = location_ref[0] - 'A';
    uint8_t col = location_ref[1] - '1';

    CRC32 crc;

    crc.update(id);
    crc.update(name_ref, name_length);
    crc.update(price);
    crc.update(stock_available);
    crc.update(stock_in_machine);
    crc.update(row);
    crc.update(col);

    uint32_t crc_value = crc.finalize();
    uint8_t hash_index = row * 8 + col;

    if(hashes[hash_index] != crc_value) {
      msgpck_write_integer(serial, 2);
      msgpck_write_integer(serial, id);
      msgpck_write_string(serial, (char*) name_ref, name_length);
      msgpck_write_integer(serial, price);
      msgpck_write_integer(serial, stock_available);
      msgpck_write_integer(serial, stock_in_machine);
      msgpck_write_integer(serial, row);
      msgpck_write_integer(serial, col);
      waitForAck();

      hashes[hash_index] = crc_value;
    }

    has_product[hash_index] = true;
  }

  for (uint8_t row = 0; row < 8; row++)
  {
    for (uint8_t col = 0; col < 8; col++)
    {
      uint8_t index = row * 8 + col;
      if(! has_product[index] && hashes[index] != 0) {
        hashes[index] = 0;
        msgpck_write_integer(serial, 6);
        msgpck_write_integer(serial, row);
        msgpck_write_integer(serial, col);
        waitForAck();
      }
    }
  }

  sendStatus(BridgeStatus::PRODUCTS_FETCHED);
}

void DenhacWifiBridge::fetchOrdersByCard(uint32_t cardNumber) {
  sendStatus(BridgeStatus::FETCHING_ORDERS_BY_CARD);

  sprintf(urlBuffer, "/wp-json/wc-vending/v1/orders/by_card/%u", cardNumber);
  RestResponse* response = request.GET(urlBuffer);

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  msgpck_write_integer(serial, 3);
  msgpck_write_integer(serial, cardNumber);

  JsonArray orders = jsonDoc.as<JsonArray>();
  msgpck_write_integer(serial, orders.size());

  packetWritten(PACKET_ORDERS_BY_CARD);

  for(JsonObject order : orders) {
    sendOrder(order);
  }

  waitForAck();

  sendStatus(BridgeStatus::ORDERS_FETCHED_BY_CARD);
}

void DenhacWifiBridge::fetchOrderById(uint32_t orderId) {
  sendStatus(BridgeStatus::FETCHING_ORDER_BY_ID);

  sprintf(urlBuffer, "/wp-json/wc-vending/v1/orders/%u", orderId);
  RestResponse* response = request.GET(urlBuffer);

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  msgpck_write_integer(serial, 4);
  JsonObject order = jsonDoc.as<JsonObject>();
  sendOrder(order);
  waitForAck();

  sendStatus(BridgeStatus::ORDER_FETCHED_BY_ID);
}

void DenhacWifiBridge::updateOrder() {
  jsonDoc.clear();

  uint32_t orderId = 0;
  msgpck_read_integer(serial, (byte*) &orderId, sizeof(orderId));
  uint32_t cardId = 0;
  msgpck_read_integer(serial, (byte*) &cardId, sizeof(cardId));
  uint32_t cash = 0;
  msgpck_read_integer(serial, (byte*) &cash, sizeof(cash));
  uint8_t numItems = 0;
  msgpck_read_integer(serial, (byte*) &numItems, sizeof(numItems));

  packetRead(PACKET_ORDER_UPDATE);

  sendDebug("Got order id: ");
  sendDebug(orderId);
  sendDebug("Got card id: ");
  sendDebug(cardId);
  sendDebug("Got cash: ");
  sendDebug(cash);
  sendDebug("Got num items: ");
  sendDebug(numItems);

  if(orderId != 0) {
    jsonDoc["order_id"] = orderId;
  }
  if(cardId != 0) {
    jsonDoc["card"] = cardId;
  }
  if(cash != 0) {
    jsonDoc["cash"] = cash;
  }
  JsonArray items = jsonDoc.createNestedArray("items");
  for(uint8_t t = 0; t < numItems; t++) {

    sendDebug("Value of t is: ");
    sendDebug(t);
    sendDebug(numItems);

    ackIfNeededFor(PACKET_ITEM_UPDATE);

    uint32_t productId = 0;
    msgpck_read_integer(serial, (byte*) &productId, sizeof(productId));
    uint32_t wanted = 0;
    msgpck_read_integer(serial, (byte*) &wanted, sizeof(wanted));
    uint32_t vended = 0;
    msgpck_read_integer(serial, (byte*) &vended, sizeof(vended));

    JsonObject item = items.createNestedObject();
    item["product_id"] = productId;
    item["wanted"] = wanted;
    item["vended"] = vended;

    sendDebug("Product ID is: ");
    sendDebug(productId);
    sendDebug("Wanted is: ");
    sendDebug(wanted);
    sendDebug("Vended is: ");
    sendDebug(vended);
  }

  sendDebug("Out of loop!");

  ack();

  sendStatus(BridgeStatus::UPDATING_ORDER);

  RestResponse* response = request.POST("/wp-json/wc-vending/v1/orders");

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  JsonObject order = jsonDoc.as<JsonObject>();
  msgpck_write_integer(serial, 5);
  sendOrder(order);
  waitForAck();

  sendStatus(BridgeStatus::ORDER_UPDATED);
}

void DenhacWifiBridge::cancelOrderById(uint32_t orderId) {
  sendStatus(BridgeStatus::CANCELLING_ORDER);

  sprintf(urlBuffer, "/wp-json/wc-vending/v1/orders/%u", orderId);
  RestResponse* response = request.DELETE(urlBuffer);

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  sendStatus(BridgeStatus::ORDER_CANCELLED);
}

void DenhacWifiBridge::fetchCreditByCard(uint32_t cardNumber) {
  sendStatus(BridgeStatus::FETCHING_CREDIT);

  sprintf(urlBuffer, "/wp-json/wc-vending/v1/credit/%u", cardNumber);
  RestResponse* response = request.GET(urlBuffer);

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  JsonObject order = jsonDoc.as<JsonObject>();
  uint32_t credit = order["credit"];
  bool useRFIDForPayment = order["rfid_payment"];
  msgpck_write_integer(serial, 9);
  msgpck_write_integer(serial, credit);
  msgpck_write_bool(serial, useRFIDForPayment);
  waitForAck();

  sendStatus(BridgeStatus::CREDIT_FETCHED);
}

void DenhacWifiBridge::updateCreditByCard(uint32_t cardNumber, int32_t difference) {
  sendStatus(BridgeStatus::UPDATING_CREDIT);

  jsonDoc.clear();
  jsonDoc["credit"] = difference;

  sprintf(urlBuffer, "/wp-json/wc-vending/v1/credit/%u", cardNumber);
  RestResponse* response = request.POST(urlBuffer);

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  JsonObject order = jsonDoc.as<JsonObject>();
  uint32_t credit = order["credit"];
  int32_t diff = order["diff"];
  msgpck_write_integer(serial, 0x0A);
  msgpck_write_integer(serial, credit);
  msgpck_write_integer(serial, diff);
  waitForAck();

  sendStatus(BridgeStatus::CREDIT_UPDATED);
}

bool DenhacWifiBridge::handleCommonRestIssues(RestResponse * response) {
  if(!response->connected) {
    sendStatus(BridgeStatus::CONNECTION_FAILED);
    return false;
  }

  if(response->status != 200) {
    if(response->status == 404) {
      sendStatus(BridgeStatus::REST_NOT_FOUND);
    } else {
      sendStatus(BridgeStatus::REST_UNKNOWN_FAILURE);
    }
    return false;
  }

  // Empty body will not have valid JSON
  if(!response->validJSON && response->contentLength > 0) {
    sendStatus(BridgeStatus::JSON_DECODE_FAILED);
    return false;
  }

  return true;
}

void DenhacWifiBridge::sendOrder(JsonObject &order) {
  waitForAckIfNeededFor(PACKET_ORDER_HEADER);

  msgpck_write_integer(serial, (uint32_t) order["id"]);

  JsonVariant orderStatus = order["status"];
  uint8_t statusCode;
  if(orderStatus == "pending") {
    statusCode = static_cast<uint8_t>(OrderStatus::PENDING);
  } else if(orderStatus == "processing") {
    statusCode = static_cast<uint8_t>(OrderStatus::PROCESSING);
  } else if(orderStatus == "on-hold") {
    statusCode = static_cast<uint8_t>(OrderStatus::ON_HOLD);
  } else if(orderStatus == "completed") {
    statusCode = static_cast<uint8_t>(OrderStatus::COMPLETED);
  } else if(orderStatus == "cancelled") {
    statusCode = static_cast<uint8_t>(OrderStatus::CANCELLED);
  } else if(orderStatus == "refunded") {
    statusCode = static_cast<uint8_t>(OrderStatus::REFUNDED);
  } else if(orderStatus == "failed") {
    statusCode = static_cast<uint8_t>(OrderStatus::FAILED);
  } else {
    statusCode = static_cast<uint8_t>(OrderStatus::UNKNOWN);
  }
  msgpck_write_integer(serial, statusCode);
  msgpck_write_integer(serial, (uint32_t) order["paid"]);
  msgpck_write_integer(serial, (uint32_t) order["total"]);

  JsonArray items = order["items"];
  msgpck_write_integer(serial, items.size());

  packetWritten(PACKET_ORDER_HEADER);

  for(JsonObject item : items) {
    sendItem(item);
  }
}

void DenhacWifiBridge::sendItem(JsonObject &item) {
  waitForAckIfNeededFor(PACKET_ITEM);

  msgpck_write_integer(serial, (uint32_t) item["item_id"]);
  msgpck_write_integer(serial, (uint32_t) item["product_id"]);
  msgpck_write_integer(serial, (uint8_t) item["quantity"]);
  msgpck_write_integer(serial, (uint8_t) item["vended"]);

  packetWritten(PACKET_ITEM);
}

void DenhacWifiBridge::setupComm() {
  while(true) {
    msgpck_write_nil(serial);
    delay(100);

    if(serial->available() == 0) {
      continue;
    }

    if(msgpck_nil_next(serial)) {
      // Clear out anything sent to us
      while(serial->available()) {
        serial->read();
      }

      sendStatus(BridgeStatus::READY);
      return;
    } else {
      // If got something that wasn't nil, we need to dispose of it
      serial->read();
    }
  }
}

void DenhacWifiBridge::sendStatus(uint8_t status) {
  msgpck_write_integer(serial, 0x01);
  msgpck_write_integer(serial, status);
  waitForAck();
}

void DenhacWifiBridge::sendDebug(String msg) {
  #ifdef DEBUG_MODE
  msgpck_write_integer(serial, 0x07);
  msgpck_write_string(serial, msg);
  // Debug doesn't wait for ACK because it's only used in testing
  // and we don't want to mess up other commands
  #endif
}

void DenhacWifiBridge::sendDebug(uint32_t value) {
  #ifdef DEBUG_MODE
  msgpck_write_integer(serial, 0x07);
  msgpck_write_integer(serial, value);
  // Debug doesn't wait for ACK because it's only used in testing
  // and we don't want to mess up other commands
  #endif
}

/**
 * To prevent overflowing the receiving buffer on the host side,
 * we wait for an ACK each time after sending a packet.
 */
void DenhacWifiBridge::waitForAck() {
  // If we're waiting for ACK, this field gets reset
  packetMaxSizeSent = 0;

  digitalWrite(13, HIGH);
  while(true) {
    if(serial->available() == 0) {
      continue;
    }

    if(msgpck_nil_next(serial)) {
      serial->read();
      digitalWrite(13, LOW);
      return;
    } else {
      // If got something that wasn't nil, we need to dispose of it
      serial->read();
    }
  }
}

void DenhacWifiBridge::packetWritten(uint8_t maxPacketSize) {
  packetMaxSizeSent += maxPacketSize;
}

void DenhacWifiBridge::waitForAckIfNeededFor(uint8_t maxPacketSize) {
  if(packetMaxSizeSent + maxPacketSize >= 63) {
    waitForAck();
  }
}

void DenhacWifiBridge::ack() {
  // If we're sending an ACK, this field gets reset
  packetMaxSizeRead = 0;

  msgpck_write_nil(serial);
}

void DenhacWifiBridge::packetRead(uint8_t maxPacketSize) {
  packetMaxSizeRead += maxPacketSize;
}

void DenhacWifiBridge::ackIfNeededFor(uint8_t maxPacketSize) {
if(packetMaxSizeRead + maxPacketSize >= 63) {
    ack();
  }
}


#endif