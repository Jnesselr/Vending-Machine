#ifdef VENDING_WIFI_BRIDGE_BOARD

#include "denhac/wifi_bridge/DenhacWifiBridge.h"

const char* root_ca = 
"-----BEGIN PUBLIC KEY-----"
"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA36/pl1AIg1e0zGJl9pCC"
"7MfTLGswylvs2cN9x0DBGBSL4Ogzdkkq4z8hSZOsTg6vPkjLZe780yEPZdIq2TKP"
"jOX3d7ASe7WVwImjqbrtcy56DAYyg6J+ihQwzRGg4So4uXkKMf1QvYBl37dRY4PI"
"4ohh6kthgexSa7mi4ksaKJ9Io54M2gmOPhcuHt0g31vGKoqrLr1wrcULGiWQdHLF"
"e2qrNNYwif/laBN7VAvI1q7sWpySHj1ks4zG37/JQXDsFnLVJuw4VTlD0Pz9GFxA"
"8Zfr1ZqbjR262iW5xtjfwRUCOqvabvE+LvVcCJw81oNp5BCbGSq2KVfj5T2bn/AC"
"XQIDAQAB"
"-----END PUBLIC KEY-----";

#define SERIAL Serial
HTTPClient http;

void DenhacWifiBridge::setup() {
  SERIAL.begin(115200);
  delay(1000);
  
  WiFi.begin(WIFI_SSID, WIFI_PSK);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
}

void DenhacWifiBridge::loop() {
  // TODO Auth
  http.begin("https://denhac.org/wp-json/wc-vending/v1/products", root_ca); //Specify the URL and certificate

  int httpCode = http.GET();

  // TODO Come up with an actual comms protocol
  SERIAL.println(httpCode);
  if (httpCode > 0) { //Check for the returning code
   String payload = http.getString();
   SERIAL.println(payload);
  }

  http.end(); //Free the resources

  // TODO Handle this better than what we're doing here, so the Arduino can actually do send/receive stuff.
  delay(5 * 60 * 1000);
}

#endif