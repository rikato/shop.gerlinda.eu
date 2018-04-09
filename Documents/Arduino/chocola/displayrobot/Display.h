#ifndef DISPLAY_H
#define DISPLAY_H
#include "Arduino.h"

class Display{
  public:
    Display(int groundPin);
    void setup();
    void value(byte character);
    void show();
    void hide();

  private:
    byte bitMap = 0b11111111;
    int groundPin;
};

#endif