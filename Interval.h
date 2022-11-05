#ifndef INTERVAL_H
#define INTERVAL_H
#include <esp32-hal.h>

class Interval
{
  private:
    unsigned long previousMillis = 0;

	public:
        Interval();
        void reset();
        bool elapsed(unsigned long millis);
};

#endif
