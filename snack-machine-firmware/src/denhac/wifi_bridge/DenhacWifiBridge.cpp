#ifdef VENDING_WIFI_BRIDGE_BOARD

#include "denhac/wifi_bridge/DenhacWifiBridge.h"

#include "CRC32.h"

const char*  server = "denhac.org";  // Server URL

const char* root_ca = ROOT_CA;

const uint8_t NUM_PRODUCTS = 64;

WiFiClientSecure DenhacWifiBridge::client;
HardwareSerial* DenhacWifiBridge::serial = &Serial;
// This value is enough to handle 64 products and a variable number of orders
// We might want to implement paging to reduce the amount of memory needed here.
DynamicJsonDocument DenhacWifiBridge::jsonDoc(JSON_ARRAY_SIZE(NUM_PRODUCTS) + NUM_PRODUCTS*JSON_OBJECT_SIZE(8));
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
}

void DenhacWifiBridge::fetchProducts() {
  sendStatus(Status::FETCHING_PRODUCTS);
  if (!client.connect(server, 443)) {
    sendStatus(Status::CONNECTION_FAILED);
  } else {
    // Make a HTTP request:
    client.println("GET /wp-json/wc-vending/v1/products HTTP/1.0");
    client.println("Host: www.denhac.org");
    client.println("Connection: close");
    client.println();

    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        break;
      }
    }
    // if there are incoming bytes available
    // from the server, read them and print them:
    DeserializationError err = deserializeJson(jsonDoc, client);

    if(err) {
      sendStatus(Status::JSON_DECODE_FAILED);
    } else {
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
          }
        }
      }
    }

    client.stop();
  }
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

#endif