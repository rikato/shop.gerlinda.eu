#include "Display.h"
#include "Arduino.h"
#include "Definitions.h"

static const int totalPins = 8;

static const byte pins [totalPins] = {
  dpPin, //dp
  aPin, //a
  bPin, //b
  cPin, //c
  dPin, //d
  ePin, //e
  fPin, //f
  gPin  //g
};

Display::Display(int groundPin){
  this->groundPin = groundPin;
}

void Display::setup(){
  
  for(int i = 0; i < totalPins; i++){
    pinMode(pins[i], OUTPUT);
  }
  
  pinMode(this->groundPin, OUTPUT);
  digitalWrite(this->groundPin, LOW);
}

void Display::value(byte character){
  
  this->bitMap = character;
  byte bitMap = this->bitMap;
  bitMap = ~bitMap;
  
  for (int i = 0; i < totalPins; ++i){
    digitalWrite(pins[i], !bitRead(bitMap, 7 - i));
  }
}

void Display::show(){
  digitalWrite(this->groundPin, LOW);
  delay(5);
}

void Display::hide(){
  digitalWrite(this->groundPin, HIGH);
}
