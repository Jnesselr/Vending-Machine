#pragma once

class DenhacBindings {
  public:
    static void setup();
  private:
    static void onCardScanned(unsigned long cardCode);
};