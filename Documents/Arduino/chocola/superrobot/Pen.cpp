#include "Arduino.h"
#include "Pen.h"
#include "Definitions.h"

Pen::Pen() {
    pinMode(penPin, OUTPUT);
}

void Pen::setDrawing(bool b) {
    digitalWrite(penPin, b);
}