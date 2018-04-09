#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int dirPin, int speedPin) {
    this->directionPin = dirPin;
    this->speedPin = speedPin;
    pinMode(dirPin, OUTPUT);
    pinMode(speedPin, OUTPUT);
}

void Motor::setDirection(bool b) {
    if (b) {
        digitalWrite(this->directionPin, LOW);
    } else {
        digitalWrite(this->directionPin, HIGH);
    }
}

void Motor::setSpeed(int i) {
    analogWrite(this->speedPin, i);
}

void Motor::stop() {
    digitalWrite(this->directionPin, LOW);
    digitalWrite(this->speedPin, LOW);
}