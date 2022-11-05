#include "Brick.h";
#include "Ball.h";
#include "MathProxy.h";

Brick::Brick(unsigned int _x){
    x = _x;
    y = 1;
    active = 0;
}
Brick::Brick(unsigned int _x,unsigned int _y){
    x = _x;
    y = _y ;
    active = 1;
}

void Brick::reset(unsigned int _active, unsigned int _y) {
    active = _active;
    y = _y;
}

int Brick::isTouchingY(Ball* ball) {
    int isTouching = (
        active
        &&
        ball->x == x
        &&
        ((y - 2) == ball->y || (y + 2) == ball->y)
    );
    if (isTouching){
        active = false;
    }
    return isTouching;
}

int Brick::isActive() {
    return active;
}

int Brick::isTouchingX(Ball* ball) {
  int isTouching = (
      active
      &&
      (ball->x == x-1 || ball->x == x+1)
      &&
      (MathProxy::proxyAbs(y - ball->y) <= 2)
  );
  if (isTouching){
      active = false;
  }
  return isTouching;
}

void Brick::hide(Adafruit_HT1632LEDMatrix * matrix) {
    matrix->drawPixel(x, y - 1, 0);
    matrix->drawPixel(x, y - 0, 0);
    matrix->drawPixel(x, y + 1, 0);
}

void Brick::display(Adafruit_HT1632LEDMatrix * matrix) {
    if(!active){
        return;
    }
    matrix->drawPixel(x, y - 1, 1);
    matrix->drawPixel(x, y - 0, 1);
    matrix->drawPixel(x, y + 1, 1);
}
