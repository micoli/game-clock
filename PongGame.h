#ifndef PONG_GAME_H
#define PONG_GAME_H
#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"
#include "Ball.h"
#include "Bat.h"
#include "TimezoneClock.h"
#include "MathProxy.h"

class PongGame
{
	private:
        unsigned int maxWidth;
        unsigned int maxHeight;
        TimezoneClock* timezoneClock;
        Ball* ball;
        Bat* leftBat;
        Bat* rightBat;
        unsigned int leftPoints;
        unsigned int rightPoints;
        Adafruit_HT1632LEDMatrix* matrix;
	public:
		PongGame(TimezoneClock*, Adafruit_HT1632LEDMatrix*);
    void generateNewBall();
		void reset();
		void displayText();
		void run();
};
#endif
