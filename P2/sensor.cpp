//
// Created by Shaun Lee on 2020-04-22.
//
#include <thread>
#include <chrono>
#include "sensor.h"

sensor::sensor(double input)
{
    if (input > 100 || input < 0) input = 1; //document this design decision
    battery = 100;
    drainRate = input;
    state = true;
}

//TODO don't forget to remove this function
double sensor::getdrainRate()
{
    return drainRate;
}

void sensor::drain()
{
    if (battery == 0 || !state) return;
    battery -= drainRate;
    if(battery < 0) battery = 0;
}

bool sensor::isValid()
{
    checkBattery();
    if(state)
    {
        drain();
        return true;
    }
    return false;
}

void sensor::checkBattery()
{
    if(battery <= 10) state = false;
}

void sensor::Recharge()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    battery = 100;
    state = true;
}

double sensor::getBattery()
{
    return battery;
}
