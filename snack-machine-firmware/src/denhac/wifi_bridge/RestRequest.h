#include <ArduinoJson.h>
#include "base64.h"
#include <WiFi.h>
#include <HTTPClient.h>

#include "config.h"

typedef struct {
  bool connected;
  uint16_t status;
  bool validJSON;
  uint32_t contentLength;

  void reset() {
    connected = false;
    status = 0;
    validJSON = false;
    contentLength = 0;
  }
} RestResponse;

typedef void (*DebugCallback)(String msg);

class RestRequest {
  public:
    RestRequest(
      WiFiClientSecure* client,
      DynamicJsonDocument* jsonDoc,
      const char * server);
    RestResponse* GET(const char * url);
    RestResponse* POST(const char * url);
    RestResponse* DELETE(const char * url);

    static DebugCallback debug;

  private:
    RestResponse* makeRequest(const char * method, const char * url);

    RestResponse* response;
    WiFiClientSecure* client;
    DynamicJsonDocument *jsonDoc;
    const char * server;
    char jsonBuffer[500];
    static String auth;
};