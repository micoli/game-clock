#include "Ball.h"

Ball::Ball(){
  x = 0;
  y = 0;
};

void Ball::init(
    unsigned int _x,
    unsigned int _y,
    unsigned int _speedX,
    unsigned int _speedY
) {
    x = _x;
    y = _y;
    speedX = _speedX;
    speedY = _speedY;
}

void Ball::inverseSpeedX() {
    speedX = - speedX;
}

void Ball::inverseSpeedY() {
    speedY = - speedY;
}
void Ball::hide(Adafruit_HT1632LEDMatrix * matrix) {
    matrix->drawPixel(x, y, 0);
}

void Ball::display(Adafruit_HT1632LEDMatrix * matrix) {
    matrix->drawPixel(x, y, 1);
}

void Ball::advance() {
  x = x + speedX;
  y = y + speedY;
}

