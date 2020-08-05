#ifdef VENDING_MAIN_BOARD

#include "denhac/SiteLink.h"
#include "denhac/data/BridgeStatus.h"
#include "msgpck.h"

#include "utils.h"

SiteLinkStateCallback SiteLink::onStateChanged = nullptr;
BridgeStatusCallback SiteLink::statusCallback = nullptr;
ProductUpdatedCallback SiteLink::productUpdatedCallback = nullptr;
ProductRemovedCallback SiteLink::productRemovedCallback = nullptr;

SiteLinkCommand emptySiteLinkCommand;
RingBuffer<8, SiteLinkCommand> SiteLink::commandBuffer(emptySiteLinkCommand);

SiteLinkState SiteLink::state = SiteLinkState::UNKNOWN;

OutputPort<PORT_H, 6, 1> SiteLink::huzzahResetPin;
HardwareSerial* SiteLink::linkSerial = &Serial1;
uint8_t SiteLink::handshakeCount = 0;
uint8_t SiteLink::garbageLoopCount = 0;
bool SiteLink::fetchingProducts = false;
bool SiteLink::firstProductFetch = false;
bool SiteLink::hasProduct[64];

void SiteLink::setup() {
  linkSerial->begin(9600);
}

void SiteLink::loop() {
  if(state == SiteLinkState::UNKNOWN) {
    // We might have just powered on or forced a reset
    // Bring the reset pin low to be safe
    huzzahResetPin.write(0x0);

    updateState(SiteLinkState::WAITING);
  } else if(state == SiteLinkState::WAITING) {
    handleWaiting();
  } else if(state == SiteLinkState::HANDSHAKE) {
    handleHandshake();
    firstProductFetch = true;
    memset(hasProduct, false, sizeof(bool) * 64);
  } else {
    handleNormalCommands();
  }
}

void SiteLink::handleWaiting() {
  // Don't read more than X bytes in one go
  int bytesToRead = min(linkSerial->available(), 100);

  while(bytesToRead > 0) {
    if(msgpck_nil_next(linkSerial)) {
      handshakeCount++;

      // Only respond at exactly 5 because we may read more in
      // this loop alone
      if(handshakeCount == 5) {
        msgpck_write_nil(linkSerial); // Initiate the handshake
        updateState(SiteLinkState::HANDSHAKE);
      }
    } else {
      handshakeCount = 0;
    }

    linkSerial->read();
    bytesToRead--;
  }

  // We do this regardless of whether we read bytes
  // This code doesn't run if the status isn't WAITING
  // It's only used to determine if the HUZZAH needs a reset
  garbageLoopCount++;

  if(garbageLoopCount > 20) {
    huzzahResetPin.write(0xFF);
    updateState(SiteLinkState::UNKNOWN);
    garbageLoopCount = 0;
  }
}

void SiteLink::handleHandshake() {
  if(linkSerial->available() == 0) {
    return;
  }

  // We might still have some NILs in the buffer to dispose of
  while(msgpck_nil_next(linkSerial)) {
    linkSerial->read();
  }

  // Try to read the READY status message
  uint8_t typeCode = 0;
  msgpck_read_integer(linkSerial, (byte*) &typeCode, sizeof(typeCode));
  uint8_t statusCode = 0;
  msgpck_read_integer(linkSerial, (byte*) &statusCode, sizeof(statusCode));
  if(typeCode == 0x01 && statusCode == BridgeStatus::READY) {
    ack();
    Serial.println("We did it!");
    updateState(SiteLinkState::IDLE);
    CALLBACK(statusCallback, statusCode);
  }
  Serial.flush();
}

void SiteLink::ack() {
  msgpck_write_nil(linkSerial);
}

void SiteLink::handleNormalCommands() {
  if(linkSerial->available() == 0) {
    return;
  }

  Serial.print("Available: ");
  Serial.println(linkSerial->available());

  uint8_t typeCode = 0;
  msgpck_read_integer(linkSerial, (byte*) &typeCode, sizeof(typeCode));
  Serial.print("Type: ");
  Serial.println(typeCode);

  switch (typeCode)
  {
  case 1:
    handleStatus();
    break;
  case 2:
    handleProductUpdated();
    break;
  case 3:
    handleOrdersByCard();
    break;
  case 4:
    handleOrdersById();
    break;
  case 6:
    handleProductRemoved();
    break;
  case 9:
    handleCreditByCard();
    break;
  default:
    Serial.println("Unknown type code!");
    Serial.println(typeCode, HEX);
    while(true) {}
    break;
  }
}

void SiteLink::handleStatus() {
  Serial.println("Status code!");
  uint8_t statusCode = 0;
  msgpck_read_integer(linkSerial, (byte*) &statusCode, sizeof(statusCode));
  ack();
  Serial.print("Code is: ");
  Serial.println(statusCode, HEX);
  Serial.flush();

  switch (statusCode)
  {
  case BridgeStatus::FETCHING_PRODUCTS:
    fetchingProducts = true;
    break;
  case BridgeStatus::PRODUCTS_FETCHED:
    fetchingProducts = false;
    if(firstProductFetch) {
      firstProductFetch = false;
      for (uint8_t row = 0; row < 8; row++)
      {
        for (uint8_t col = 0; col < 8; col++)
        {
          if(! hasProduct[8 * row + col]) {
            CALLBACK(productRemovedCallback, row, col)
          }
        }
      }
    }
    break;
  case BridgeStatus::CONNECTION_FAILED:
  case BridgeStatus::REST_NOT_FOUND:
  case BridgeStatus::REST_UNKNOWN_FAILURE:
  case BridgeStatus::JSON_DECODE_FAILED:
    if(!fetchingProducts) {
        SiteLinkCommand command = commandBuffer.pop();
        CALLBACK(command.errorCallback, statusCode)
    }

    break;
  }

  CALLBACK(statusCallback, statusCode);
}

void SiteLink::handleProductUpdated() {
  Product product;

  msgpck_read_integer(linkSerial, (byte*) &product.id, sizeof(product.id));
  msgpck_read_string(linkSerial, product.name, sizeof(product.name));
  msgpck_read_integer(linkSerial, (byte*) &product.price, sizeof(product.price));
  msgpck_read_integer(linkSerial, (byte*) &product.stockAvailable, sizeof(product.stockAvailable));
  msgpck_read_integer(linkSerial, (byte*) &product.stockInMachine, sizeof(product.stockInMachine));
  msgpck_read_integer(linkSerial, (byte*) &product.row, sizeof(product.row));
  msgpck_read_integer(linkSerial, (byte*) &product.col, sizeof(product.col));
  ack();

  hasProduct[8 * product.row + product.col] = true;

  CALLBACK(productUpdatedCallback, product)
}

void SiteLink::handleOrdersByCard() {
  uint32_t cardNumber = 0;
  msgpck_read_integer(linkSerial, (byte*) &cardNumber, sizeof(cardNumber));

  uint8_t numOrders = 0;
  msgpck_read_integer(linkSerial, (byte*) &numOrders, sizeof(numOrders));

  Order orders[8];
  for (uint8_t i = 0; i < numOrders; i++)
  {
    orders[i] = readOrder();
  }
  ack();

  // TODO Should we assume order is correct here
  SiteLinkCommand command = commandBuffer.pop();
  OrdersResponseCallback callback = (OrdersResponseCallback) command.commandCallback;

  CALLBACK(callback, orders, numOrders)
}

void SiteLink::handleOrdersById() {
  Order order = readOrder();
  ack();

  // TODO Should we assume order is correct here
  SiteLinkCommand command = commandBuffer.pop();
  OrderResponseCallback callback = (OrderResponseCallback) command.commandCallback;

  CALLBACK(callback, order)
}

Order SiteLink::readOrder() {
  uint32_t orderId = 0;
  uint8_t status = 0;
  uint32_t paid = 0;
  uint32_t total = 0;

  msgpck_read_integer(linkSerial, (byte*) &orderId, sizeof(orderId));
  msgpck_read_integer(linkSerial, (byte*) &status, sizeof(status));
  msgpck_read_integer(linkSerial, (byte*) &paid, sizeof(paid));
  msgpck_read_integer(linkSerial, (byte*) &total, sizeof(total));

  Serial.print("Order ID: ");
  Serial.println(orderId);
  Serial.print("Status: ");
  Serial.println(status);
  Serial.print("Paid: ");
  Serial.println(paid);
  Serial.print("Total: ");
  Serial.println(total);

  OrderStatus orderStatus = static_cast<OrderStatus>(status);
  Order order(orderId, orderStatus, paid, total);

  uint8_t numItems = 0;
  msgpck_read_integer(linkSerial, (byte*) &numItems, sizeof(numItems));

  Serial.print("Num Items: ");
  Serial.println(numItems);

  for (uint8_t i = 0; i < numItems; i++)
  {
    Item item = readItem();
    order.add(item);
  }

  return order;
}

Item SiteLink::readItem() {
  uint32_t itemId = 0;
  uint32_t productId = 0;
  uint8_t quantity = 0;
  uint8_t vended = 0;

  msgpck_read_integer(linkSerial, (byte*) &itemId, sizeof(itemId));
  msgpck_read_integer(linkSerial, (byte*) &productId, sizeof(productId));
  msgpck_read_integer(linkSerial, (byte*) &quantity, sizeof(quantity));
  msgpck_read_integer(linkSerial, (byte*) &vended, sizeof(vended));

  Serial.print("Item ID: ");
  Serial.println(itemId);
  Serial.print("Product ID: ");
  Serial.println(productId);
  Serial.print("Quantity: ");
  Serial.println(quantity);
  Serial.print("Vended: ");
  Serial.println(vended);

  Item item(itemId, productId, quantity, vended);

  return item;
}

void SiteLink::handleProductRemoved() {
  uint8_t row = 0;
  uint8_t col = 0;

  msgpck_read_integer(linkSerial, (byte*) &row, sizeof(row));
  msgpck_read_integer(linkSerial, (byte*) &col, sizeof(col));
  ack();

  CALLBACK(productRemovedCallback, row, col)
}

void SiteLink::handleCreditByCard() {
  uint32_t credit = 0;

  msgpck_read_integer(linkSerial, (byte*) &credit, sizeof(credit));
  ack();

  // TODO Should we assume order is correct here
  SiteLinkCommand command = commandBuffer.pop();
  CreditResponseCallback callback = (CreditResponseCallback) command.commandCallback;

  CALLBACK(callback, credit)
}

void SiteLink::getOrdersByCard(
  uint32_t cardNumber,
  BridgeStatusCallback onStatus,
  OrdersResponseCallback onOrders) {
    msgpck_write_integer(linkSerial, 0x03);
    msgpck_write_integer(linkSerial, cardNumber);

    SiteLinkCommand command(onStatus, onOrders);
    commandBuffer.push(command);
  }

void SiteLink::getOrderById(
  uint32_t id,
  BridgeStatusCallback onStatus,
  OrderResponseCallback onOrder) {
    msgpck_write_integer(linkSerial, 0x04);
    msgpck_write_integer(linkSerial, id);

    SiteLinkCommand command(onStatus, onOrder);
    commandBuffer.push(command);
  }

void SiteLink::getCreditByCard(
  uint32_t cardNumber,
  BridgeStatusCallback onStatus,
  CreditResponseCallback onCredit) {
    msgpck_write_integer(linkSerial, 0x09);
    msgpck_write_integer(linkSerial, cardNumber);

    SiteLinkCommand command(onStatus, onCredit);
    commandBuffer.push(command);
  }

void SiteLink::updateState(SiteLinkState siteLinkState) {
  SiteLinkState oldState = SiteLink::state;
  SiteLink::state = siteLinkState;

  CALLBACK(onStateChanged, oldState, siteLinkState);
}

SiteLinkCommand::SiteLinkCommand() {
  this->errorCallback = nullptr;
  this->commandCallback = nullptr;
}

SiteLinkCommand::SiteLinkCommand(BridgeStatusCallback onError) {
  this->errorCallback = onError;
  this->commandCallback = nullptr;
}

SiteLinkCommand::SiteLinkCommand(BridgeStatusCallback onError, OrdersResponseCallback onOrders) {
  this->errorCallback = onError;
  this->commandCallback = (VoidCallback) onOrders;
}

SiteLinkCommand::SiteLinkCommand(BridgeStatusCallback onError, OrderResponseCallback onOrders) {
  this->errorCallback = onError;
  this->commandCallback = (VoidCallback) onOrders;
}

SiteLinkCommand::SiteLinkCommand(BridgeStatusCallback onError, CreditResponseCallback onCredit) {
  this->errorCallback = onError;
  this->commandCallback = (VoidCallback) onCredit;
}

#endif