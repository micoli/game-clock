#include "Ball.h"
#include "Bat.h"
#include "MathProxy.h"

Bat::Bat(unsigned int _x,unsigned int _maxHeight){
    x = _x;
    y = MathProxy::proxyFloor(_maxHeight / 2) ;
    maxHeight = _maxHeight;
}

void Bat::alignWithBall(Ball* ball) {
    y = ball->y;
    if (y < 1) {
        y = 1;
        return;
    }
    if (y >= (maxHeight - 1 - 1)) {
        y = (maxHeight - 1 - 1);
    }
}

unsigned int Bat::isTouching(Ball* ball) {
    return (
        MathProxy::proxyAbs(ball->x - x) <= 1
        && (y - 1) <= ball->y
        && ball->y <= (y + 1)
    );
}

void Bat::hide(Adafruit_HT1632LEDMatrix * matrix) {
    matrix->drawPixel(x, y - 1, 0);
    matrix->drawPixel(x, y - 0, 0);
    matrix->drawPixel(x, y + 1, 0);
}

void Bat::display(Adafruit_HT1632LEDMatrix * matrix) {
    matrix->drawPixel(x, y - 1, 1);
    matrix->drawPixel(x, y - 0, 1);
    matrix->drawPixel(x, y + 1, 1);
}