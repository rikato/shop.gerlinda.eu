#include "Display.h"
#include "Arduino.h"
#include "Definitions.h"
#include "Pen.h"

static const byte character[11] = {
    0b01111110, //0
    0b00110000, //1
    0b01101101, //2
    0b01111001, //3
    0b00110011, //4
    0b01011011, //5
    0b01011111, //6
    0b01110000, //7
    0b01111111, //8
    0b01111011, //9
    0b00001110, //L
};

//Instances of Displays
Display *wordNumberDisplay = new Display(wordNumberDisplayGroundPin);
Display *letterDisplay = new Display(letterDisplayGroundPin);

int i = 0;

bool pen = false;

void setup() {
    Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A5, OUTPUT);

pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);

  wordNumberDisplay->setup();
  letterDisplay->setup();
}

void loop() {
    digitalWrite(4, digitalRead(3));
    if (digitalRead(12)) {
      wordNumberDisplay->hide();
      letterDisplay->value(character[10]);
      letterDisplay->show();
      
      letterDisplay->hide();
      wordNumberDisplay->value(character[i]);
      wordNumberDisplay->show();
    } else {
        wordNumberDisplay->hide();
    }
    if (digitalRead(13)) {
        i++;
        delay(500);
    }
}