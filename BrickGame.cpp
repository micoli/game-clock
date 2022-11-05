#include "BrickGame.h"


BrickGame::BrickGame(TimezoneClock* _timezoneClock, Adafruit_HT1632LEDMatrix* _matrix){
    matrix = _matrix;
    timezoneClock = _timezoneClock;
    maxWidth = matrix->width();
    maxHeight = matrix->height();
    ball = new Ball();
    bat = new Bat(0, maxHeight);
    int brickIndex = 0;
    for(int x=1;x<=BRICK_COLUMNS;x++){
        for(int y=1;y<=BRICK_ROWS;y++){
            bricks[brickIndex]=new Brick(27+x*3);
            brickIndex++;
        }
    }
    reset();
}

void BrickGame::reset(){
    ball->hide(matrix);
    matrix->clearScreen();
    ticks = 0;
    unsigned int brickIndex = 0;
    unsigned int randomGameIndex = MathProxy::getRandomInt(0,MAX_GAMES-1);

    for(int x=1;x<=BRICK_COLUMNS;x++){
        for(int y=1;y<=BRICK_ROWS;y++){
            unsigned int value = GAMES[randomGameIndex][x-1][y-1];
            unsigned int isActive = value != 0;
            unsigned int brickY = isActive ? value : 0;
            //(27+x*3, y*4-2);
            bricks[brickIndex]->reset(isActive, brickY);
            brickIndex++;
        }
    }
    generateNewBall();    
}

void BrickGame::generateNewBall(){
    ball->init(
        1,
        MathProxy::getRandomInt(1,maxHeight),
        1,
        MathProxy::getRandomInt(1, 2)
    );
}

void BrickGame::displayText(){
    matrix->setFont(&Font3x5FixedNum);
    matrix->setTextSize(1);
    matrix->setTextColor(1);
    matrix->setTextWrap(true);
    char line1Buffer[40];
    timezoneClock->getHourMinute(line1Buffer);
    matrix->setCursor(3*8-13, 6);
    matrix->print(line1Buffer);
    matrix->writeScreen();
    matrix->setFont();
}

void BrickGame::run(){
    ticks = ticks + 1;
    ball->hide(matrix);
    int newPosX = ball->x + ball->speedX;
    int newPosY = ball->y + ball->speedY;
    if (newPosX >= maxWidth) {
        ball->inverseSpeedX();
    }

    if (newPosX < 0) {
        generateNewBall();
    }

    if (bat->isTouching(ball)) {
        ball->inverseSpeedX();
    }

    if (newPosY >= maxHeight  || newPosY < 0) {
        ball->inverseSpeedY();
    }

    int numberActive=0;
    for (int brickIndex=0;brickIndex<BRICK_COLUMNS*BRICK_ROWS;brickIndex++){
        bricks[brickIndex]->hide(matrix);
        if(bricks[brickIndex]->isTouchingX(ball)){
            ball->inverseSpeedX();
        }
        if(bricks[brickIndex]->isTouchingY(ball)){
            ball->inverseSpeedY();
        }
        bricks[brickIndex]->display(matrix);
        numberActive += bricks[brickIndex]->isActive();
    }

    ball->advance();

    bat->hide(matrix);
    bat->alignWithBall(ball);
    bat->display(matrix);

    ball->display(matrix);

    if (numberActive == 0 || ticks >= 3000){
        reset();
        ticks = 0;
    }
    matrix->writeScreen();

    displayText();
}
