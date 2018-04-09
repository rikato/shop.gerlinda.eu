#ifndef MOTOR_H
#define MOTOR_H

class Motor{
  public:
    Motor(int dirPin, int speedPin);
    void move(int duration);
    void stop();
    void setSpeed(int i);
    void setDirection(bool b);
    int directionPin;
    int speedPin;
};

#endif