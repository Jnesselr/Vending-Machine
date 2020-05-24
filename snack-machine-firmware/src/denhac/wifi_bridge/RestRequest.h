#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

typedef struct {
  uint8_t status;
  uint8_t validJSON;
  DynamicJsonDocument* json;
} RestResponse;

class RestRequest {
  public:
    RestRequest(WiFiClientSecure &client, DynamicJsonDocument &jsonDoc);
    RestResponse* GET(char * url);
    RestResponse* POST(char * url);
    RestResponse* DELETE(char * url);

  private:
    RestResponse response;
    WiFiClientSecure* client;
    DynamicJsonDocument *jsonDoc;
};