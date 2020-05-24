#include "denhac/wifi_bridge/RestRequest.h"

RestRequest::RestRequest(
  WiFiClientSecure &client,
  DynamicJsonDocument &jsonDoc,
  const char * server) {
  this->client = &client;
  this->jsonDoc = &jsonDoc;
  this->server = server;
  this->response = new RestResponse();
}

RestResponse* RestRequest::GET(const char * url) {
  return this->makeRequest("GET", url);
}

RestResponse* RestRequest::POST(const char * url) {
  return this->makeRequest("POST", url);
}

RestResponse* RestRequest::DELETE(const char * url) {
  return this->makeRequest("DELETE", url);
}

RestResponse* RestRequest::makeRequest(const char * method, const char * url) {
  response->reset();

  bool connected = client->connect(server, 443);

  response->connected = connected;

  if(!connected) {
    return response;
  }

  client->print(method);
  client->print(" ");
  client->print(url);
  client->println(" HTTP/1.0");
  client->print("Host: ");
  client->println(server);
  client->println("Connection: close");
  client->println();

  String httpLine = client->readStringUntil('\n');
  String statusCodeString = "";
  bool started = false;
  bool ended = false;
  for (int i=0; i<httpLine.length(); i++) {
    if(httpLine[i] == ' ') {
      if(!started) {
        started = true;
      } else if(!ended) {
        ended = true;
      }
    } else if(started && !ended) {
      statusCodeString += (char) httpLine[i];
    }
  }

  response->status = statusCodeString.toInt();

  while (client->connected()) {
    String line = client->readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  DeserializationError err = deserializeJson(*jsonDoc, *client);

  if(err) {
    response->validJSON = false;
  } else {
    response->validJSON = true;
    response->json = jsonDoc;
  }

  client->stop();

  return response;
}

