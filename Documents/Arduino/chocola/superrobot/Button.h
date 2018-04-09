#ifndef BUTTON_H
#define BUTTON_H

class Button {
    public:
        Button(int pin);
        void update();
        bool isPressed();
        void waitForInput();
    private:
        int pin;
        bool state;
        bool lastState;
};

#endif