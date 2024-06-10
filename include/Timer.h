#pragma once

#include "main.h"

class Timer {
    private:
        unsigned long int starttime;
        unsigned long int duration;
        bool active;
    public:
        Timer();
        Timer(unsigned long int);
        void setDuration(unsigned long int td);
        void startNow();
        bool isExpired(); //timer can only expire when active!
        bool isActive();
        void deactivate();
        unsigned long int remainingTime();
};
