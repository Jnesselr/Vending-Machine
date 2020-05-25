#ifdef VENDING_WIFI_BRIDGE_BOARD

#include "denhac/wifi_bridge/DenhacWifiBridge.h"

#include "CRC32.h"

const char*  server = "www.denhac.org";  // Server URL

const char* root_ca = ROOT_CA;

const uint8_t NUM_PRODUCTS = 64;

HardwareSerial* DenhacWifiBridge::serial = &Serial;

WiFiClientSecure DenhacWifiBridge::client;
// This value is enough to handle 64 products and a variable number of orders
// We might want to implement paging to reduce the amount of memory needed here.
DynamicJsonDocument DenhacWifiBridge::jsonDoc(JSON_ARRAY_SIZE(NUM_PRODUCTS) + NUM_PRODUCTS*JSON_OBJECT_SIZE(8));
RestRequest DenhacWifiBridge::request(client, jsonDoc, server);
DebugCallback RestRequest::debug = &DenhacWifiBridge::sendDebug;
char DenhacWifiBridge::urlBuffer[100];

uint32_t DenhacWifiBridge::hashes[NUM_PRODUCTS];
bool DenhacWifiBridge::has_product[NUM_PRODUCTS];

unsigned long DenhacWifiBridge::lastProductUpdateMillis = 0;

void DenhacWifiBridge::setup() {
  serial->begin(115200);

  lastProductUpdateMillis = 0;
  memset(hashes, 0, sizeof(hashes));

  DenhacWifiBridge::setupComm();
  
  WiFi.begin(WIFI_SSID, WIFI_PSK);
  sendStatus(Status::WIFI_TRYING_TO_CONNECT);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  sendStatus(Status::WIFI_CONNECTED);
}

void DenhacWifiBridge::loop() {
  unsigned long currentMillis = millis();

  // Once a minute
  if(lastProductUpdateMillis == 0 ||
      currentMillis - lastProductUpdateMillis > 60 * 1000) {
    fetchProducts();
    lastProductUpdateMillis = currentMillis;
  }

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
  }
}

void DenhacWifiBridge::fetchProducts() {
  sendStatus(Status::FETCHING_PRODUCTS);

  RestResponse* response = request.GET("/wp-json/wc-vending/v1/products");

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  bool anythingSent = false;
  memset(has_product, false, sizeof(has_product));

  JsonArray array = jsonDoc.as<JsonArray>();
  for(JsonObject obj : array) {
    uint32_t id = obj["id"];
    const char * name_ref = obj["name"];
    uint32_t name_length = strlen(name_ref);
    if(name_length > 51) {
      name_length = 51;
    }
    uint32_t price = obj["price"];
    uint8_t stock = obj["stock_quantity"];
    const char * location_ref = obj["location"];
    uint8_t row = location_ref[0] - 'A';
    uint8_t col =location_ref[1] - '0';

    CRC32 crc;

    crc.update(id);
    crc.update(name_ref, name_length);
    crc.update(price);
    crc.update(stock);
    crc.update(row);
    crc.update(col);

    uint32_t crc_value = crc.finalize();
    uint8_t hash_index = row * 8 + col;

    if(hashes[hash_index] != crc_value) {
      msgpck_write_integer(serial, 2);
      msgpck_write_integer(serial, id);
      msgpck_write_string(serial, (char*) name_ref, name_length);
      msgpck_write_integer(serial, price);
      msgpck_write_integer(serial, stock);
      msgpck_write_integer(serial, row);
      msgpck_write_integer(serial, col);

      hashes[hash_index] = crc_value;
      anythingSent = true;
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

        anythingSent = true;
      }
    }
  }

  if(!anythingSent) {
    sendStatus(Status::PRODUCTS_FETCHED);
  }
}

void DenhacWifiBridge::fetchOrdersByCard(uint32_t cardNumber) {
  sendStatus(Status::FETCHING_ORDERS);

  sprintf(urlBuffer, "/wp-json/wc-vending/v1/orders/by_card/%u", cardNumber);
  RestResponse* response = request.GET(urlBuffer);

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  msgpck_write_integer(serial, 3);
  msgpck_write_integer(serial, cardNumber);
  handleCardResponse();
}

void DenhacWifiBridge::fetchOrderById(uint32_t orderId) {
  sendStatus(Status::FETCHING_ORDERS);

  sprintf(urlBuffer, "/wp-json/wc-vending/v1/orders/%u", orderId);
  RestResponse* response = request.GET(urlBuffer);

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  msgpck_write_integer(serial, 4);
  JsonObject order = jsonDoc.as<JsonObject>();
  sendOrder(order);
}

void DenhacWifiBridge::updateOrder() {
  sendStatus(Status::UPDATING_ORDER);
  jsonDoc.clear();

  uint32_t orderId = 0;
  msgpck_read_integer(serial, (byte*) &orderId, sizeof(orderId));
  uint32_t cardId = 0;
  msgpck_read_integer(serial, (byte*) &cardId, sizeof(cardId));
  uint8_t numItems = 0;
  msgpck_read_integer(serial, (byte*) &numItems, sizeof(numItems));
  sendDebug("Got order id: ");
  sendDebug(orderId);
  sendDebug("Got card id: ");
  sendDebug(cardId);
  sendDebug("Got num items: ");
  sendDebug(numItems);

  if(orderId != 0) {
    jsonDoc["order_id"] = orderId;
  }
  if(cardId != 0) {
    jsonDoc["card"] = cardId;
  }
  JsonArray items = jsonDoc.createNestedArray("items");
  for(uint8_t t = 0; t < numItems; t++) {

    sendDebug("Value of t is: ");
    sendDebug(t);
    sendDebug(numItems);
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

  RestResponse* response = request.POST("/wp-json/wc-vending/v1/orders");

  bool isValidRest = handleCommonRestIssues(response);

  if(!isValidRest) {
    return;
  }

  JsonObject order = jsonDoc.as<JsonObject>();
  msgpck_write_integer(serial, 5);
  sendOrder(order);
}

bool DenhacWifiBridge::handleCommonRestIssues(RestResponse * response) {
  if(!response->connected) {
    sendStatus(Status::CONNECTION_FAILED);
    return false;
  }

  if(response->status != 200) {
    if(response->status == 404) {
      sendStatus(Status::REST_NOT_FOUND);
    } else {
      sendStatus(Status::REST_UNKNOWN_FAILURE);
    }
    return false;
  }

  if(!response->validJSON) {
    sendStatus(Status::JSON_DECODE_FAILED);
    return false;
  }

  return true;
}

void DenhacWifiBridge::handleCardResponse() {
  JsonArray orders = jsonDoc.as<JsonArray>();

  msgpck_write_integer(serial, orders.size());
  for(JsonObject order : orders) {
    sendOrder(order);
  }
}

void DenhacWifiBridge::sendOrder(JsonObject &order) {
  msgpck_write_integer(serial, (uint32_t) order["id"]);
  msgpck_write_integer(serial, 0); // TODO Make match actual order status
  msgpck_write_integer(serial, (uint32_t) order["paid"]);
  msgpck_write_integer(serial, (uint32_t) order["total"]);

  JsonArray items = order["items"];
  msgpck_write_integer(serial, items.size());
  for(JsonObject item : items) {
    sendItem(item);
  }
}

void DenhacWifiBridge::sendItem(JsonObject &item) {
  msgpck_write_integer(serial, (uint32_t) item["item_id"]);
  msgpck_write_integer(serial, (uint32_t) item["product_id"]);
  msgpck_write_integer(serial, (uint8_t) item["quantity"]);
  msgpck_write_integer(serial, (uint8_t) item["vended"]);
}

void DenhacWifiBridge::setupComm() {
  while(true) {
    msgpck_write_nil(serial);
    delay(100);
    if(msgpck_nil_next(serial)) {
      sendStatus(Status::READY);
      return;
    } else {
      // If got something that wasn't null, we need to dispose of it
      if(serial->available()) {
        serial->read();
      }
    }
  }
}

void DenhacWifiBridge::sendStatus(uint8_t status) {
  msgpck_write_integer(serial, 0x01);
  msgpck_write_integer(serial, status);
}

void DenhacWifiBridge::sendDebug(String msg) {
  msgpck_write_integer(serial, 0x07);
  msgpck_write_string(serial, msg);
}

void DenhacWifiBridge::sendDebug(uint32_t value) {
  msgpck_write_integer(serial, 0x07);
  msgpck_write_integer(serial, value);
}

#endif