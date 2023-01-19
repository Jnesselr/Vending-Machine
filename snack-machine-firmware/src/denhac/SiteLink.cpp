#ifdef VENDING_MAIN_BOARD

#include "denhac/SiteLink.h"
#include "denhac/data/BridgeStatus.h"
#include "denhac/data/MaxPacketSize.h"
#include "msgpck.h"

#include "utils.h"

SiteLinkStateCallback SiteLink::onStateChanged = nullptr;
BridgeStatusCallback SiteLink::statusCallback = nullptr;
ProductUpdatedCallback SiteLink::productUpdatedCallback = nullptr;
ProductRemovedCallback SiteLink::productRemovedCallback = nullptr;

RingBuffer<3, SiteLinkCommand> SiteLink::commandBuffer;

SiteLinkState SiteLink::state = SiteLinkState::UNKNOWN;

OutputPort<PORT_H, 6, 1> SiteLink::huzzahResetPin;
HardwareSerial* SiteLink::linkSerial = &Serial1;
uint8_t SiteLink::handshakeCount = 0;
uint8_t SiteLink::garbageLoopCount = 0;
unsigned long SiteLink::resetTime = 0;
bool SiteLink::safeToSendCommand = false;
bool SiteLink::firstProductFetch = false;
bool SiteLink::hasProduct[64];

HardwareSerial* SiteLinkAck::linkSerial = &Serial1;
uint8_t SiteLinkAck::packetMaxSizeSent = 0;
uint8_t SiteLinkAck::packetMaxSizeRead = 0;

unsigned long SiteLink::lastCommandRunMillis = 0;

void SiteLink::setup() {
  linkSerial->begin(9600);
}

void SiteLink::loop() {
  if(state == SiteLinkState::UNKNOWN) {
    LOOP_START_WAIT_MS(resetTime, 1000);
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

    maybeSendCommand();
  }
}

void SiteLink::reset() {
  huzzahResetPin.write(0xFF);
  resetTime = current_loop_millis;
  updateState(SiteLinkState::UNKNOWN);
  commandBuffer.clear();
  garbageLoopCount = 0;
  lastCommandRunMillis = current_loop_millis;
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
    reset();
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
    SiteLinkAck::ack();
    updateState(SiteLinkState::IDLE);
    CALLBACK(statusCallback, statusCode);
  }
}

void SiteLinkAck::waitForAck() {
  // If we're waiting for ACK, this field gets reset
  packetMaxSizeSent = 0;

  while(true) {
    if(linkSerial->available() == 0) {
      continue;
    }

    if(msgpck_nil_next(linkSerial)) {
      linkSerial->read();
      return;
    } else {
      // If got something that wasn't nil, we need to dispose of it
      linkSerial->read();
    }
  }
}

void SiteLinkAck::packetWritten(uint8_t maxPacketSize) {
  packetMaxSizeSent += maxPacketSize;
}

void SiteLinkAck::waitForAckIfNeededFor(uint8_t maxPacketSize) {
  if(packetMaxSizeSent + maxPacketSize >= 63) {
    waitForAck();
  }
}

void SiteLinkAck::ack() {
  // If we're sending an ACK, this field gets reset
  packetMaxSizeRead = 0;

  msgpck_write_nil(linkSerial);
}

void SiteLinkAck::packetRead(uint8_t maxPacketSize) {
  packetMaxSizeRead += maxPacketSize;
}

void SiteLinkAck::ackIfNeededFor(uint8_t maxPacketSize) {
if(packetMaxSizeRead + maxPacketSize >= 63) {
    ack();
  }
}

void SiteLink::handleNormalCommands() {
  if(linkSerial->available() == 0) {
    return;
  }

  uint8_t typeCode = 0;
  msgpck_read_integer(linkSerial, (byte*) &typeCode, sizeof(typeCode));

  SiteLinkAck::packetRead(COMMAND_BYTES);

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
  case 5:
    handleOrderById();
    break;
  case 6:
    handleProductRemoved();
    break;
  case 9:
    handleCreditByCard();
    break;
  case 0xA:
    handleCreditUpdateByCard();
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
  SiteLinkAck::ack();
  Serial.print("Code is: ");
  Serial.println(statusCode, HEX);
  Serial.flush();

  switch (statusCode)
  {
  case BridgeStatus::PRODUCTS_FETCHED:
    safeToSendCommand = true;
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
    // If it's not safe to send a command, we probably already sent one
    if(!safeToSendCommand && !commandBuffer.isEmpty()) {
        safeToSendCommand = true;
        SiteLinkCommand command = commandBuffer.pop();
        CALLBACK(command.errorCallback, statusCode)
    }

    break;

  case BridgeStatus::ORDER_CANCELLED:
    // We should only get this command in response to a request for cancellation
    safeToSendCommand = true;
    if(!commandBuffer.isEmpty()) {
      SiteLinkCommand command = commandBuffer.pop();
      CALLBACK(command.commandCallback)
    }
    break;
  case BridgeStatus::WIFI_CONNECTED:
  case BridgeStatus::ORDERS_FETCHED_BY_CARD:
  case BridgeStatus::ORDER_FETCHED_BY_ID:
  case BridgeStatus::ORDER_UPDATED:
  case BridgeStatus::CREDIT_FETCHED:
  case BridgeStatus::CREDIT_UPDATED:
    safeToSendCommand = true;
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
  SiteLinkAck::ack();

  hasProduct[8 * product.row + product.col] = true;

  CALLBACK(productUpdatedCallback, product)
}

void SiteLink::handleOrdersByCard() {
  uint32_t cardNumber = 0;
  msgpck_read_integer(linkSerial, (byte*) &cardNumber, sizeof(cardNumber));

  uint8_t numOrders = 0;
  msgpck_read_integer(linkSerial, (byte*) &numOrders, sizeof(numOrders));

  SiteLinkAck::packetRead(PACKET_ORDERS_BY_CARD);

  Order order;
  if(numOrders > 0) {
    order = readOrder();
  }
  SiteLinkAck::ack();

  SiteLinkCommand command = commandBuffer.pop();
  OrderResponseCallback callback = (OrderResponseCallback) command.commandCallback;

  CALLBACK(callback, order)
}

void SiteLink::handleOrderById() {
  Order order = readOrder();
  SiteLinkAck::ack();

  SiteLinkCommand command = commandBuffer.pop();
  OrderResponseCallback callback = (OrderResponseCallback) command.commandCallback;

  CALLBACK(callback, order)
}

Order SiteLink::readOrder() {
  uint32_t orderId = 0;
  uint8_t status = 0;
  uint32_t paid = 0;
  uint32_t total = 0;

  SiteLinkAck::ackIfNeededFor(PACKET_ORDER_HEADER);

  msgpck_read_integer(linkSerial, (byte*) &orderId, sizeof(orderId));
  msgpck_read_integer(linkSerial, (byte*) &status, sizeof(status));
  msgpck_read_integer(linkSerial, (byte*) &paid, sizeof(paid));
  msgpck_read_integer(linkSerial, (byte*) &total, sizeof(total));

  OrderStatus orderStatus = static_cast<OrderStatus>(status);
  Order order(orderId, orderStatus, paid, total);

  uint8_t numItems = 0;
  msgpck_read_integer(linkSerial, (byte*) &numItems, sizeof(numItems));

  SiteLinkAck::packetRead(PACKET_ORDER_HEADER);

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

  SiteLinkAck::ackIfNeededFor(PACKET_ITEM);

  msgpck_read_integer(linkSerial, (byte*) &itemId, sizeof(itemId));
  msgpck_read_integer(linkSerial, (byte*) &productId, sizeof(productId));
  msgpck_read_integer(linkSerial, (byte*) &quantity, sizeof(quantity));
  msgpck_read_integer(linkSerial, (byte*) &vended, sizeof(vended));

  SiteLinkAck::packetRead(PACKET_ITEM);

  Item item(itemId, productId, quantity, vended);

  return item;
}

void SiteLink::handleProductRemoved() {
  uint8_t row = 0;
  uint8_t col = 0;

  msgpck_read_integer(linkSerial, (byte*) &row, sizeof(row));
  msgpck_read_integer(linkSerial, (byte*) &col, sizeof(col));
  SiteLinkAck::ack();

  CALLBACK(productRemovedCallback, row, col)
}

void SiteLink::handleCreditByCard() {
  uint32_t credit = 0;
  bool useRFIDForPayment = false;

  msgpck_read_integer(linkSerial, (byte*) &credit, sizeof(credit));
  msgpck_read_bool(linkSerial, &useRFIDForPayment);
  SiteLinkAck::ack();

  SiteLinkCommand command = commandBuffer.pop();
  CreditResponseCallback callback = (CreditResponseCallback) command.commandCallback;

  CALLBACK(callback, credit, useRFIDForPayment)
}

void SiteLink::handleCreditUpdateByCard() {
  uint32_t totalCredit = 0;
  uint32_t diffCredit = 0;

  msgpck_read_integer(linkSerial, (byte*) &totalCredit, sizeof(totalCredit));
  msgpck_read_integer(linkSerial, (byte*) &diffCredit, sizeof(diffCredit));
  SiteLinkAck::ack();

  SiteLinkCommand command = commandBuffer.pop();
  CreditUpdateResponseCallback callback = (CreditUpdateResponseCallback) command.commandCallback;

  CALLBACK(callback, totalCredit, diffCredit)
}

void SiteLink::maybeSendCommand() {
  if(!safeToSendCommand) {
    // If it's been a minute since it was safe to run a command,
    // We should just assume we need to run a reset
    LOOP_WAIT_MS(lastCommandRunMillis, 60000)

    reset();
    return;
  }

  SiteLinkCommand command;

  if(commandBuffer.isEmpty()) {
    // If the buffer is empty and it's been a minute since
    // the last command, go ahead and fetch products
    LOOP_START_WAIT_MS(lastCommandRunMillis, 60000)

    command.type = SiteLinkCommandType::GET_PRODUCTS;
    command.linkSerial = linkSerial;
  } else {
    command = commandBuffer.peek();
  }

  command.run();
  safeToSendCommand = false;
  lastCommandRunMillis = current_loop_millis;
}

void SiteLink::getOrdersByCard(
  uint32_t cardNumber,
  BridgeStatusCallback onStatus,
  OrderResponseCallback onOrders) {
    SiteLinkCommand command;
    command.linkSerial = linkSerial;
    command.type = SiteLinkCommandType::GET_ORDERS_BY_CARD;
    command.errorCallback = onStatus;
    command.commandCallback = (VoidCallback) onOrders;
    command.buffer.cardRequest.cardNumber = cardNumber;

    commandBuffer.push(command);
  }

void SiteLink::getOrderById(
  uint32_t orderId,
  BridgeStatusCallback onStatus,
  OrderResponseCallback onOrder) {
    SiteLinkCommand command;
    command.linkSerial = linkSerial;
    command.type = SiteLinkCommandType::GET_ORDER_BY_ID;
    command.errorCallback = onStatus;
    command.commandCallback = (VoidCallback) onOrder;
    command.buffer.orderRequest.orderId = orderId;

    commandBuffer.push(command);
  }

void SiteLink::cancelOrderById(
  uint32_t orderId,
  BridgeStatusCallback onStatus,
  VoidCallback onOrderCancelled) {
    SiteLinkCommand command;
    command.linkSerial = linkSerial;
    command.type = SiteLinkCommandType::CANCEL_ORDER_BY_ID;
    command.errorCallback = onStatus;
    command.commandCallback = onOrderCancelled;
    command.buffer.orderRequest.orderId = orderId;

    commandBuffer.push(command);
  }

void SiteLink::updateOrder(
  uint32_t cardNumber,
  uint32_t cash,
  Order &order,
  BridgeStatusCallback onStatus,
  OrderResponseCallback onOrder) {
    UpdateOrderRequest updateOrderRequest;
    updateOrderRequest.cardNumber = cardNumber;
    updateOrderRequest.cash = cash;
    updateOrderRequest.orderId = order.orderId;
    updateOrderRequest.numItems = order.getNumItems();
    for (uint8_t i = 0; i < updateOrderRequest.numItems; i++)
    {
      Item item = order.getItem(i);
      updateOrderRequest.itemUpdates[i].productId = item.productId;
      updateOrderRequest.itemUpdates[i].wanted = item.quantity;
      updateOrderRequest.itemUpdates[i].vended = item.vended;
    }

    updateOrder(updateOrderRequest, onStatus, onOrder);
  }

void SiteLink::updateOrder(
  UpdateOrderRequest updateOrderRequest,
  BridgeStatusCallback onStatus,
  OrderResponseCallback onOrder) {
    SiteLinkCommand command;
    command.linkSerial = linkSerial;
    command.type = SiteLinkCommandType::UPDATE_ORDER;
    command.errorCallback = onStatus;
    command.commandCallback = (VoidCallback) onOrder;
    command.buffer.updateOrderRequest.orderId = updateOrderRequest.orderId;
    command.buffer.updateOrderRequest.cardNumber = updateOrderRequest.cardNumber;
    command.buffer.updateOrderRequest.cash = updateOrderRequest.cash;
    command.buffer.updateOrderRequest.numItems = updateOrderRequest.numItems;
    for (uint8_t i = 0; i < updateOrderRequest.numItems; i++)
    {
      command.buffer.updateOrderRequest.itemUpdates[i].productId = updateOrderRequest.itemUpdates[i].productId;
      command.buffer.updateOrderRequest.itemUpdates[i].wanted = updateOrderRequest.itemUpdates[i].wanted;
      command.buffer.updateOrderRequest.itemUpdates[i].vended = updateOrderRequest.itemUpdates[i].vended;
    }

    commandBuffer.push(command);
  }

void SiteLink::getCreditByCard(
  uint32_t cardNumber,
  BridgeStatusCallback onStatus,
  CreditResponseCallback onCredit) {
    SiteLinkCommand command;
    command.linkSerial = linkSerial;
    command.type = SiteLinkCommandType::GET_CREDIT_BY_CARD;
    command.errorCallback = onStatus;
    command.commandCallback = (VoidCallback) onCredit;
    command.buffer.cardRequest.cardNumber = cardNumber;

    commandBuffer.push(command);
  }

void SiteLink::updateCreditByCard(
  uint32_t cardNumber,
  uint32_t amount,
  BridgeStatusCallback onStatus,
  CreditUpdateResponseCallback onCreditUpdate) {
    SiteLinkCommand command;
    command.linkSerial = linkSerial;
    command.type = SiteLinkCommandType::UPDATE_CREDIT_BY_CARD;
    command.errorCallback = onStatus;
    command.commandCallback = (VoidCallback) onCreditUpdate;
    command.buffer.creditUpdateRequest.cardNumber = cardNumber;
    command.buffer.creditUpdateRequest.amount = amount;

    commandBuffer.push(command);
  }

void SiteLink::updateState(SiteLinkState siteLinkState) {
  Serial.print("Link state: ");
  Serial.println((int)siteLinkState);
  Serial.flush();
  SiteLinkState oldState = SiteLink::state;
  SiteLink::state = siteLinkState;

  CALLBACK(onStateChanged, oldState, siteLinkState);
}

SiteLinkCommand::SiteLinkCommand() {
  this->linkSerial = nullptr;
  this->type = SiteLinkCommandType::UNKNOWN;
  this->errorCallback = nullptr;
  this->commandCallback = nullptr;
}

SiteLinkCommand::SiteLinkCommand(const SiteLinkCommand& command) {
  this->linkSerial = command.linkSerial;
  this->type = command.type;
  this->errorCallback = command.errorCallback;
  this->commandCallback = command.commandCallback;
}

void SiteLinkCommand::operator=(const SiteLinkCommand& command) {
  this->linkSerial = command.linkSerial;
  this->type = command.type;
  this->errorCallback = command.errorCallback;
  this->commandCallback = command.commandCallback;
}

void SiteLinkCommand::run() {
  switch(type) {
    case SiteLinkCommandType::GET_PRODUCTS:
      runGetProducts();
      break;
    case SiteLinkCommandType::GET_ORDERS_BY_CARD:
      runOrdersByCard();
      break;
    case SiteLinkCommandType::GET_ORDER_BY_ID:
      runOrderById();
      break;
    case SiteLinkCommandType::CANCEL_ORDER_BY_ID:
      runCancelOrderById();
      break;
    case SiteLinkCommandType::UPDATE_ORDER:
      runUpdateOrder();
      break;
    case SiteLinkCommandType::GET_CREDIT_BY_CARD:
      runCreditByCard();
      break;
    case SiteLinkCommandType::UPDATE_CREDIT_BY_CARD:
      runUpdateCreditByCard();
      break;
    case SiteLinkCommandType::UNKNOWN:
      return;
  }
}

void SiteLinkCommand::runGetProducts() {
  msgpck_write_integer(linkSerial, 0x0B);
}

void SiteLinkCommand::runOrdersByCard() {
  msgpck_write_integer(linkSerial, 0x03);
  msgpck_write_integer(linkSerial, buffer.cardRequest.cardNumber);
}

void SiteLinkCommand::runOrderById() {
  msgpck_write_integer(linkSerial, 0x04);
  msgpck_write_integer(linkSerial, buffer.orderRequest.orderId);
}

void SiteLinkCommand::runCancelOrderById() {
  msgpck_write_integer(linkSerial, 0x08);
  msgpck_write_integer(linkSerial, buffer.orderRequest.orderId);
}

void SiteLinkCommand::runUpdateOrder() {
  msgpck_write_integer(linkSerial, 0x05);
  msgpck_write_integer(linkSerial, buffer.updateOrderRequest.orderId);
  msgpck_write_integer(linkSerial, buffer.updateOrderRequest.cardNumber);
  msgpck_write_integer(linkSerial, buffer.updateOrderRequest.cash);
  msgpck_write_integer(linkSerial, buffer.updateOrderRequest.numItems);

  SiteLinkAck::packetWritten(PACKET_ORDER_UPDATE);

  for (uint8_t i = 0; i < buffer.updateOrderRequest.numItems; i++)
  {
    SiteLinkAck::waitForAckIfNeededFor(PACKET_ITEM_UPDATE);

    msgpck_write_integer(linkSerial, buffer.updateOrderRequest.itemUpdates[i].productId);
    msgpck_write_integer(linkSerial, buffer.updateOrderRequest.itemUpdates[i].wanted);
    msgpck_write_integer(linkSerial, buffer.updateOrderRequest.itemUpdates[i].vended);

    SiteLinkAck::packetWritten(PACKET_ITEM_UPDATE);
  }

  SiteLinkAck::waitForAck();
}

void SiteLinkCommand::runCreditByCard() {
  msgpck_write_integer(linkSerial, 0x09);
  msgpck_write_integer(linkSerial, buffer.cardRequest.cardNumber);
}

void SiteLinkCommand::runUpdateCreditByCard() {
  msgpck_write_integer(linkSerial, 0x0A);
  msgpck_write_integer(linkSerial, buffer.creditUpdateRequest.cardNumber);
  msgpck_write_integer(linkSerial, buffer.creditUpdateRequest.amount);
}

#endif
