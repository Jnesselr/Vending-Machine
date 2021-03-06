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

#endif