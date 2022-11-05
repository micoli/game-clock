#include "ClockDisplay.h"
#include <stdio.h>

ClockDisplay::ClockDisplay(TimezoneClock* _timezoneClock, Adafruit_HT1632LEDMatrix* _matrix,uint8_t pin, uint8_t type){
    timezoneClock = _timezoneClock;
    matrix = _matrix;
    interval = new Interval();
    dht = new DHT(pin, type);
  	dht->begin();
}

void ClockDisplay::run(){
  if(!interval->elapsed(900)){
    return;
  }
  char line1Buffer[40];
  char line2Buffer[40];
  timezoneClock->getHourMinuteSecond(line1Buffer);
  changeBrightness(timezoneClock->getHour());
  sprintf(line2Buffer, "%dc  %d%%", (int) dht->readTemperature(), (int) dht->readHumidity());

	matrix->clearScreen();

	matrix->setTextSize(1);
	matrix->setFont();
	matrix->setTextColor(1);
	matrix->setTextWrap(true);

	matrix->setCursor(0, 0);
	matrix->print(line1Buffer);
  
	matrix->setCursor(0, 8);
	matrix->print(line2Buffer);

	matrix->writeScreen();
	// matrix.print(analogRead(LIGHT_PIN));
}

void ClockDisplay::changeBrightness(int hour){
  if (hour>=7 && hour <22){
      matrix->setBrightness(3);
      return;
  }
  matrix->setBrightness(0);
}