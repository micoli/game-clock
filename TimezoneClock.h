#ifndef TIMEZONE_CLOCK_H
#define TIMEZONE_CLOCK_H

#include <time.h>

class TimezoneClock
{
	public:
    TimezoneClock(const char*, const char*);
    unsigned int getHour();
    void getHourMinute(char*);
    void getHourMinuteSecond(char*);

};

#endif
