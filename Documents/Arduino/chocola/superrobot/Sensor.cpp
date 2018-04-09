#include "Arduino.h"
#include "Sensor.h"
#include "Definitions.h"

Sensor::Sensor(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
    this->treshold = sensorTreshold;
}

int Sensor::simpleRead() {
    int s = analogRead(pin);
    delay(1);
    s += analogRead(pin);
    delay(1);
    s += analogRead(pin);
    delay(1);
    s /= 3;
    return(s);
}

bool Sensor::checkLine() {
    return (this->simpleRead() > this->treshold);
}