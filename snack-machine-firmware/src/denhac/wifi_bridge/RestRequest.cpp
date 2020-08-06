#ifdef VENDING_WIFI_BRIDGE_BOARD

#include "denhac/wifi_bridge/RestRequest.h"

RestRequest::RestRequest(
  WiFiClientSecure *client,
  DynamicJsonDocument *jsonDoc,
  const char * server) {
  this->client = client;
  this->jsonDoc = jsonDoc;
  this->server = server;
  this->response = new RestResponse();
}

//DebugCallback RestRequest::debug = nullptr;
String RestRequest::auth = base64::encode(CONSUMER_KEY + ":" + CONSUMER_SECRET);

RestResponse* RestRequest::GET(const char * url) {
  jsonDoc->clear();
  debug("Making GET request");
  return this->makeRequest("GET", url);
}

RestResponse* RestRequest::POST(const char * url) {
  debug("Making POST request");
  return this->makeRequest("POST", url);
}

RestResponse* RestRequest::DELETE(const char * url) {
  jsonDoc->clear();
  debug("Making DELETE request");
  return this->makeRequest("DELETE", url);
}

RestResponse* RestRequest::makeRequest(const char * method, const char * url) {
  response->reset();

  bool connected = client->connect(server, 443);

  response->connected = connected;

  if(!connected) {
    return response;
  }

  bool hasBody = !jsonDoc->isNull();
  debug(hasBody ? "Has a JSON body!" : "Does not have a JSON body");

  client->print(method);
  client->print(" ");
  client->print(url);
  client->println(" HTTP/1.0");
  client->print("Host: ");
  client->println(server);
  client->print("Authorization: Basic ");
  client->println(auth);
  client->println("Connection: close");
  if(hasBody) {
    size_t contentLength = serializeJson(*jsonDoc, jsonBuffer, 500);
    client->println("Content-Type: application/json");
    client->print("Content-Length: ");
    client->println(contentLength);
    client->println();
    client->print(jsonBuffer);
    debug(String(jsonBuffer));
  } else {
    client->println();
  }

  debug("HTTP Response: ");

  while (client->connected()) {
    String line = client->readStringUntil('\n');
    line.toLowerCase();

    if(line.startsWith("http")) {
      String statusCodeString = "";
      bool started = false;
      bool ended = false;
      for (int i=0; i<line.length(); i++) {
        if(line[i] == ' ') {
          if(!started) {
            started = true;
          } else if(!ended) {
            ended = true;
          }
        } else if(started && !ended) {
          statusCodeString += (char) line[i];
        }
      }

      response->status = statusCodeString.toInt();
    } else if(line.startsWith("content-length:")) {
      String contentLengthString = "";
      bool started = false;
      for (int i=0; i<line.length(); i++) {
        if(line[i] == ':') {
          started = true;
        } else if(started && line[i] != ' ') {
          contentLengthString += (char) line[i];
        }
      }

      response->contentLength = contentLengthString.toInt();
    }

    debug(line);
    if (line == "\r") {
      break;
    }
  }

  DeserializationError err = deserializeJson(*jsonDoc, *client);

  response->validJSON = !err;

  client->stop();

  return response;
}

#endif