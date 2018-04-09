#include "Arduino.h"
#include "Definitions.h"
#include "Motor.h"
#include "Button.h"
#include "Display.h"
#include "Pen.h"
#include "Sensor.h"

Motor *motorLeft = new Motor(motorLeftDirectionPin, motorLeftSpeedPin);
Motor *motorRight = new Motor(motorRightDirectionPin, motorRightSpeedPin);

Button *button = new Button(buttonPin);

Display *display = new Display();

Pen *pen = new Pen();

Sensor *s0 = new Sensor(A0);
Sensor *s1 = new Sensor(A1);
Sensor *s2 = new Sensor(A2);

void setup() {
    Serial.begin(9600);
    Serial.println("Beginning superrobot");
    // display->setVisible(true);
    // button->waitForInput();
    // motorLeft->setSpeed(255);
    // motorRight->setSpeed(255);
    // calibrate();
    // for (char c : text) {
    //     penDown();
    //     display->setVisible(false);
    //     display->increment();
    //     draw(c);
    //     display->setVisible(true);
    //     penUp();
    // }
}

void calibrate() {
    Serial.println("Beginning calibration");
    motorRight->setDirection(true);
    motorRight->setSpeed(motorTurnSpeed);
    motorLeft->setDirection(false);
    motorLeft->setSpeed(motorTurnSpeed);
    int t = millis();
    delay(100);
    while (!s0->checkLine() && !s1->checkLine() && !s2->checkLine()) {
        delay(10);
    }
    t = millis() - t;
    motorLeft->stop();
    motorRight->stop();
    Serial.print("Time: ");
    Serial.println(t);
}

void loop() {
    Serial.print(s0->simpleRead());
    Serial.print(" | ");
    Serial.print(s1->simpleRead());
    Serial.print(" | ");
    Serial.println(s2->simpleRead());
    delay(500);
}

void driveUntilLine(Sensor *s) {
    Serial.println("Resetting position");
    motorRight->setDirection(true);
    motorRight->setSpeed(motorDriveSpeed);
    motorLeft->setDirection(true);
    motorLeft->setSpeed(motorDriveSpeed);
    while (!s->checkLine()) {
        Serial.print(".");
        delay(10);
    }
    Serial.print("Line detected ");
    motorLeft->stop();
    motorRight->stop();
}

void penUp() {
    pen->setDrawing(false);
}

void penDown() {
    pen->setDrawing(true);
}

void draw(char letter){
    //lL = long line
    //sL = short line
    //fD = 45 degrees
    //nD = 90 degrees
    //hD = 180 degrees
   switch(tolower(letter)) {
      case 'a':
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
          drive(sL);
          break;
      case 'c':
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          break;
      case 'n':
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(lL);
          break;
       case 'o':
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(lL);
       break;
       case 'e':
          rotate(nD);
          drive(lL);
          rotate(hD);
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(lL);
          rotate(nD);
       break;
       case 'f':
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
       break;
       case 'p':
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
       break;
       case 'l':
          drive(lL);
          rotate(hD);
          drive(lL);
          rotate(-nD);
          drive(sL);
          rotate(nD);
       break;
       case 't':
          rotate(nD);
          drive(sL);
          rotate(-nD);
          drive(lL);
          rotate(-nD);
          drive(sL);
          rotate(hD);
          drive(lL);
          rotate(nD);
       break;
        case 'i':
          drive(lL);
          rotate(hD);
       break;
       case 'u':
          drive(lL);
          rotate(hD);
          drive(lL);
          rotate(-nD);
          drive(sL);
          rotate(-nD);
          drive(lL);
          rotate(hD);
       break;
       case 'h':
          drive(lL);
          rotate(hD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(hD);
          drive(lL);
       break;
       case 'j':
          rotate(nD);
          drive(sL);
          rotate(-nD);
          drive(lL);
          rotate(hD);
       break;
       case 'm':
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(lL);
       break;
       case 'w':
          drive(lL);
          rotate(hD);
          drive(lL);
          rotate(-nD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(-nD);
          drive(lL);
          rotate(hD);
       break;
       case 'd':
          rotate(nD);
          drive(sL);
          rotate(-fD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(fD);
          drive(sL);
          rotate(nD);
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(fD);
          drive(sL);
          rotate(fD);
          drive(sL);
       break;
       case 'b':
          rotate(nD);
          drive(sL);
          rotate(-fD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(fD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(fD);
          drive(sL);
          rotate(fD);
          drive(sL);
          rotate(fD);
          drive(sL);
       break;
       case 'q':
          penUp();
          drive(sL);
          penDown();
          drive(sL);
          rotate(nD);
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(lL);
          rotate(hD);
          drive(lL);
          rotate(nD);
          drive(sL);
       break;
       case 'x':
          rotate(fD);
          drive(lL);
          penUp();
          rotate(-fD);
          drive(lL);
          rotate(-nD);
          rotate(-fD);
          drive(lL);
          rotate(fD);
       break;
       case 'v':
          penUp();
          drive(lL);
          rotate(nD);
          rotate(fD);
          drive(lL);
          rotate(-fD);
          drive(lL);
          rotate(fD);
          rotate(nD);
       break;
       case 'z':
          penUp();
          drive(lL);
          rotate(nD);
          drive(lL);
          rotate(fD);
          rotate(nD);
          drive(lL);
          rotate(-fD);
          rotate(-nD);
          drive(lL);
          rotate(nD);
       break;
       case 'r':
          drive(lL);
          rotate(fD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          rotate(fD);
          drive(lL);
          rotate(fD);
       break;
       case 's':
          rotate(fD);
          drive(lL);
          rotate(-nD);
          drive(sL);
          rotate(-nD);
          drive(lL);
          rotate(nD);
          drive(sL);
          rotate(nD);
          drive(lL);
          rotate(nD);
       break;
       case 'k':
          drive(sL);
          rotate(nD);
          rotate(fD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(fD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(-nD);
          rotate(-fD);
          drive(sL);
          rotate(fD);
          rotate(nD);
       break;
       case 'g':
          penUp();
          rotate(nD);
          drive(lL);
          rotate(-nD);
          drive(lL);
          rotate(-nD);
          penDown();
          drive(lL);
          rotate(-nD);
          drive(lL);
          rotate(-nD);
          drive(lL);
          rotate(-nD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(nD);
       break;
       case 'y':
          rotate(nD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(nD);
          drive(sL);
          rotate(hD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(-nD);
          drive(sL);
          rotate(hD);
       break;
    }
}

void rotate(int duration) {
    motorRight->setDirection(duration > 0);
    motorRight->setSpeed(motorTurnSpeed);
    motorLeft->setDirection(!(duration > 0));
    motorLeft->setSpeed(motorTurnSpeed);
    wait(duration);
    motorLeft->stop();
    motorRight->stop();
}

bool drive(int distance) {
    motorRight->setDirection(!(distance > 0));
    motorRight->setSpeed(motorDriveSpeed);
    motorLeft->setDirection(!(distance > 0));
    motorLeft->setSpeed(motorDriveSpeed);
    if (wait(distance)) {
        motorLeft->stop();
        motorRight->stop();
        return(true);
    } else {
        motorLeft->stop();
        motorRight->stop();
        return(false);
    }
}

bool wait(int duration) {
    int d = sqrt(duration * duration);
    int destination = millis() + d;
    while (millis() < d) {
        if (s0->checkLine() || s1->checkLine() || s2->checkLine()) {
            return false;
        }
    }
    return true;
}