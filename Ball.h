#ifndef BALL_H
#define BALL_H
#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"

class Ball {
    public: 
        unsigned int x;
        unsigned int y;
        unsigned int speedX;
        unsigned int speedY;

        Ball();
        void init(unsigned int,unsigned int,unsigned int,unsigned int);
        void inverseSpeedX();
        void inverseSpeedY();
        void advance();
        void hide(Adafruit_HT1632LEDMatrix*);
        void display(Adafruit_HT1632LEDMatrix*) ;
};
#endif