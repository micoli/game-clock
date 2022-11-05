#ifndef BAT_H
#define BAT_H
#include "MathProxy.h"
#include "Ball.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"

class Bat {
    private:
        unsigned int x;
        unsigned int y;
        unsigned int maxHeight;

    public:
        Bat(unsigned int,unsigned int);
        void alignWithBall(Ball*);
        unsigned int isTouching(Ball*);
        void hide(Adafruit_HT1632LEDMatrix*);
        void display(Adafruit_HT1632LEDMatrix*);
};

#endif