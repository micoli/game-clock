#ifndef BRICK_H
#define BRICK_H
#include <esp32-hal.h>
#include "Ball.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"

class Brick
{
    private:
        unsigned int x;
        unsigned int y;
        unsigned int active;

    public:
        Brick(unsigned int);
        Brick(unsigned int, unsigned int);
        void reset(unsigned int, unsigned int);
        int isActive();
        int isTouchingX(Ball*);
        int isTouchingY(Ball*);
        void hide(Adafruit_HT1632LEDMatrix*);
        void display(Adafruit_HT1632LEDMatrix*);
};

#endif
