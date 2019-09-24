#include "MDB.h"

MDB* MDB::getInstance() {
  static MDB instance;
  return &instance;
}

void MDB::setup() {
  
}

