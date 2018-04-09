#ifndef PEN_H
#define PEN_H

#include "Arduino.h"
#include "Definitions.h"

class Pen {
    public:
        Pen();
        void toggle();
    private:
        bool direction;
};

#endif