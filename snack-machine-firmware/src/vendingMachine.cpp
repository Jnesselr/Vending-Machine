#include "config.h"
#include "vendingMachine.h"

#ifdef DENHAC_BOARD_CONFIG
#include "denhac/DenhacBoard.h"

void_ptr VendingMachine::setup = DenhacBoard::setup;
void_ptr VendingMachine::loop = DenhacBoard::loop;

#endif

#ifdef GIZMODOJO_BOARD_CONFIG
#include "gizmodojo/GizmoDojoBoard.h"

void_ptr VendingMachine::setup = GizmoDojoBoard::setup;
void_ptr VendingMachine::loop = GizmoDojoBoard::loop;

#endif