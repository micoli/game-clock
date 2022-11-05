#ifndef CLOCK_DISPLAY_H
#define CLOCK_DISPLAY_H

#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"
#include "DHT.h"
#include "Interval.h"
#include "TimezoneClock.h"
#include <time.h>

class ClockDisplay
{
  private:
    Interval* interval;
    DHT* dht;
    TimezoneClock* timezoneClock;
    Adafruit_HT1632LEDMatrix* matrix;
    void changeBrightness(int);

	public:
    ClockDisplay(TimezoneClock*, Adafruit_HT1632LEDMatrix*, uint8_t, uint8_t);
		void run();
};

#endif
