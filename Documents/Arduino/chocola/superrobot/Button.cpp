#include "Arduino.h"
#include "Button.h"

Button::Button(int pin) {
    pinMode(pin, INPUT);
    this->lastState = false;
    this->pin = pin;
    this->update();
}

bool Button::isPressed() {
    return (this->lastState == true && this->state == false);
}


void Button::update() {
    this->lastState = this->state;
    this->state = digitalRead(this->pin);
}

void Button::waitForInput() {
    Serial.println("Waiting for input");
    while (!this->isPressed()) {
        this->update();
    }
    Serial.println("State advanced");
}