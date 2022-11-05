#ifndef BRICK_GAME_H
#define BRICK_GAME_H
#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"
#include "Ball.h"
#include "Bat.h"
#include "Brick.h"
#include "TimezoneClock.h"
#include "MathProxy.h"
#include "Font3x5FixedNum.h"

#define BRICK_COLUMNS 6
#define BRICK_ROWS 4
#define MAX_GAMES 7

class BrickGame
{
	private:
        unsigned int maxWidth;
        unsigned int maxHeight;
        int ticks;
        Ball* ball;
        Bat* bat;
        TimezoneClock* timezoneClock;
        Brick* bricks[BRICK_COLUMNS*BRICK_ROWS];
        Adafruit_HT1632LEDMatrix* matrix;
        void displayText();
        void generateNewBall();

	public:
		BrickGame(TimezoneClock*, Adafruit_HT1632LEDMatrix*);
		void reset();
		void run();
};

static unsigned int GAMES[MAX_GAMES][BRICK_COLUMNS][BRICK_ROWS] = {
    //basic
    {
        { 2, 6, 10, 14},
        { 2, 6, 10, 14},
        { 2, 6, 10, 14},
        { 2, 6, 10, 14},
        { 2, 6, 10, 14},
        { 2, 6, 10, 14},
    },
    //OneOfTwo
    {
        { 0, 6,  0, 14},
        { 2, 0, 10,  0},
        { 0, 6,  0, 14},
        { 2, 0, 10,  0},
        { 0, 6,  0, 14},
        { 2, 0, 10,  0},
    },
    //diamond
    {
        { 0, 6, 10,  0},
        { 2, 5, 11, 14},
        { 0, 6, 10,  0},
        { 2, 5, 11, 14},
        { 2, 0,  0, 14},
        { 0, 6, 10,  0},
    },
    //circle
    {
        { 0, 6, 10,  0},
        { 3, 0,  0, 13},
        { 2, 0,  0, 14},
        { 2, 0,  0, 14},
        { 3, 0,  0, 13},
        { 0, 6, 10,  0},
    },
    //zeroCircle
    {
        { 0, 6, 10,  0},
        { 3, 0,  0, 13},
        { 2, 0,  9, 14},
        { 2, 7,  0, 14},
        { 3, 0,  0, 13},
        { 0, 6, 10,  0},
    },
    //fullCircle
    {
        { 0, 6, 10,  0},
        { 3, 6, 10, 13},
        { 2, 7,  9, 14},
        { 2, 7,  9, 14},
        { 3, 6, 10, 13},
        { 0, 6, 10,  0},
    },
    //smiley
    {
        { 0, 6, 10,  0},
        { 3, 0,  0, 13},
        { 2, 7,  0, 14},
        { 2, 7,  0, 14},
        { 3, 0,  0, 13},
        { 0, 6, 10,  0},
    },
};

#endif
