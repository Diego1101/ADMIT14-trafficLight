#include "Timer.h"

void Timer::startNow(){
    starttime = millis();
    active = true;
}
bool Timer::isExpired(){
    return (millis() >= (starttime + duration) && active);
}
bool Timer::isActive(){
    return active;
}
Timer::Timer(){
    starttime = 0;
    duration = 0;
    active = false;
}
Timer::Timer(unsigned long int startDuration){
    starttime = 0;
    duration = startDuration;
    active = false;
}
void Timer::setDuration(unsigned long int td){
    duration = td;
}
void Timer::deactivate(){
    active = false;
}