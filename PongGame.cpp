#include "PongGame.h"
#include "Font3x5FixedNum.h"

PongGame::PongGame(TimezoneClock* _timezoneClock, Adafruit_HT1632LEDMatrix* _matrix){
    matrix = _matrix;
    timezoneClock = _timezoneClock;
    maxWidth = matrix->width();
    maxHeight = matrix->height();
    ball = new Ball();
    leftBat = new Bat(0, maxHeight);
    rightBat = new Bat(maxWidth - 1, maxHeight);
    reset();
}

void PongGame::generateNewBall(){
    ball->init(
        MathProxy::proxyRound(maxWidth / 2),
        MathProxy::proxyRound(maxHeight / 2),
        MathProxy::getRandomWay() * MathProxy::getRandomInt(1, 3),
        MathProxy::getRandomWay() * MathProxy::getRandomInt(1, 2)
    );
}

void PongGame::reset(){
    leftPoints=0;
    rightPoints=0;
    generateNewBall();    
}

void PongGame::displayText(){
    matrix->setFont(&Font3x5FixedNum);
    matrix->setTextSize(1);
    matrix->setTextColor(1);
    matrix->setTextWrap(true);
    char line1Buffer[40];
    timezoneClock->getHourMinute(line1Buffer);
    matrix->setCursor(3*8-8, 6);
    matrix->print(line1Buffer);
    matrix->writeScreen();
    matrix->setFont();
}

void PongGame::run(){
    ball->hide(matrix);
    leftBat->hide(matrix);
    rightBat->hide(matrix);
    int newPosX = ball->x + ball->speedX;
    int newPosY = ball->y + ball->speedY;
    if (newPosX >= maxWidth && MathProxy::getRandomInt(1,3)==2) {
        leftPoints = leftPoints + 1;
        generateNewBall();
        return;
    }
    if (newPosX < 0 && MathProxy::getRandomInt(1,3)==2) {
        rightPoints = rightPoints + 1;
        generateNewBall();
        return;
    }

    if (leftBat->isTouching(ball) || rightBat->isTouching(ball)) {
        ball->inverseSpeedX();
    }

    if (newPosY >= maxHeight  || newPosY < 0) {
        ball->inverseSpeedY();
    }

    ball->advance();

    if (ball->speedX < 0) {
        leftBat->alignWithBall(ball);
    } else {
        rightBat->alignWithBall(ball);
    }

    ball->display(matrix);
    leftBat->display(matrix);
    rightBat->display(matrix);

    displayText();
}
