#include "TimezoneClock.h"
#include <stdio.h>
#include <Arduino.h>

TimezoneClock::TimezoneClock(const char* tz, const char* server){
  configTzTime(tz, server);
}

unsigned int TimezoneClock::getHour(){
  time_t now;
  tm tm;
  time(&now);
  localtime_r(&now, &tm);
  return tm.tm_hour;
}

void TimezoneClock::getHourMinute(char* buffer){
  time_t now;
  tm tm;
  time(&now);
  localtime_r(&now, &tm);
  sprintf(buffer, "%02d:%02d", tm.tm_hour, tm.tm_min);
}

void TimezoneClock::getHourMinuteSecond(char* buffer){
  time_t now;
  tm tm;
  time(&now);
  localtime_r(&now, &tm);
  sprintf(buffer, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
}
