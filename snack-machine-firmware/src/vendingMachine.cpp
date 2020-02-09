#include "config.h"
#include "vendingMachine.h"

#ifdef DENHAC_BOARD_CONFIG
  #ifdef VENDING_MAIN_BOARD
    #include "denhac/DenhacBoard.h"

    void_ptr VendingMachine::setup = DenhacBoard::setup;
    void_ptr VendingMachine::loop = DenhacBoard::loop;
  #endif

  #ifdef VENDING_WIFI_BRIDGE_BOARD
    #include "denhac/wifi_bridge/DenhacWifiBridge.h"

    void_ptr VendingMachine::setup = DenhacWifiBridge::setup;
    void_ptr VendingMachine::loop = DenhacWifiBridge::loop;
  #endif
#endif

#ifdef GIZMODOJO_BOARD_CONFIG
  #include "gizmodojo/GizmoDojoBoard.h"

  void_ptr VendingMachine::setup = GizmoDojoBoard::setup;
  void_ptr VendingMachine::loop = GizmoDojoBoard::loop;
#endif