#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
    public:
        Sensor(int pin);
        int simpleRead();
        bool checkLine();
        void calc();
        void setBlack(int i);
        void setWhite(int i);
        int white;
        int black;
        int treshold;

    private:
        int pin;
};

#endif