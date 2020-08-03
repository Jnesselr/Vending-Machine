#ifdef VENDING_MAIN_BOARD

#include "denhac/ui/MainWindow/Callbacks.h"

template<uint8_t row>
MainWindow* RowCallback<row>::mainWindow = nullptr;

template<uint8_t row>
void RowCallback<row>::tapped() {
  mainWindow->rowTapped(row);
}

template class RowCallback<0>;
template class RowCallback<1>;
template class RowCallback<2>;
template class RowCallback<3>;
template class RowCallback<4>;
template class RowCallback<5>;
template class RowCallback<6>;
template class RowCallback<7>;

template<uint8_t col>
MainWindow* ColCallback<col>::mainWindow = nullptr;

template<uint8_t col>
void ColCallback<col>::tapped() {
  mainWindow->colTapped(col);
}

template class ColCallback<0>;
template class ColCallback<1>;
template class ColCallback<2>;
template class ColCallback<3>;
template class ColCallback<4>;
template class ColCallback<5>;
template class ColCallback<6>;
template class ColCallback<7>;

template<StaticCallbackType type, typename... Args>
MainWindow* StaticCallback<type, Args...>::mainWindow = nullptr;

template<>
void StaticCallback<StaticCallbackType::BACK>::callback() {
  mainWindow->back();
}

template<>
void StaticCallback<StaticCallbackType::CANCEL_ORDER>::callback() {
  mainWindow->cancelOrder();
}

template<>
void StaticCallback<StaticCallbackType::MONEY_AVAILABLE, uint32_t>::callback(uint32_t amount) {
  mainWindow->moneyAvailable(amount);
}

template<>
void StaticCallback<StaticCallbackType::ADD_ITEM>::callback() {
  mainWindow->addItemScreen();
}

template<>
void StaticCallback<StaticCallbackType::CUSTOMER_LOOKUP_STARTED>::callback() {
  mainWindow->customerLookupStarted();
}

// template<>
// void StaticCallback<StaticCallbackType::SESSION_RESET>::callback() {
//   mainWindow->sessionReset();
// }

template<>
void StaticCallback<StaticCallbackType::ORDERS_RETRIEVED>::callback() {
  mainWindow->ordersRetrieved();
}

template<>
void StaticCallback<StaticCallbackType::MEMBERSHIP_BUTTON_TAPPED>::callback() {
  mainWindow->membershipButtonTapped();
}

template<>
void StaticCallback<StaticCallbackType::CURRENT_ORDER_UPDATED>::callback() {
  mainWindow->currentOrderUpdated();
}

#endif