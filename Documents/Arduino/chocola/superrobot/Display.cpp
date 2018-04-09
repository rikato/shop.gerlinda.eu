#include "Arduino.h"
#include "Display.h"
#include "Definitions.h"

Display::Display() {
    pinMode(displayPowerPin, OUTPUT);
    pinMode(displayIncrementPin, OUTPUT);

}

void Display::setVisible(bool b) {
    digitalWrite(displayPowerPin, b);
}

void Display::increment() {
    digitalWrite(displayIncrementPin, HIGH);
    delay(500);
    digitalWrite(displayIncrementPin, LOW);
}