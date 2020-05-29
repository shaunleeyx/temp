
#include <thread>
#include <chrono>
#include "sensor.h"
#include <iostream>
using namespace std;
sensor::sensor(double input,int dir,int grid[11][11]) {
    if (input > 100 || input < 0) input = 1; 
    for (int r = 0; r <= 10; r++)
    {
        for (int c = 0; c <= 10; c++)
        {
            this->g[r][c] = grid[r][c];
        }
    }
    battery = 100;
    drainRate = input;
    state = true;
    if(dir == 0) orientationState = orientation::Up;
    else if (dir == 1) orientationState = orientation::Down;
    else if (dir == 2) orientationState = orientation::Right;
    else if (dir == 3) orientationState = orientation::Left;
    else orientationState = orientation::Up;
}

//TODO don't forget to remove this function
double sensor::getdrainRate() {
    return drainRate;
}


void sensor::drain() {
    if (battery == 0 || !state) return;
    battery -= drainRate;
    if (battery < 0) battery = 0;
}

bool sensor::isValid(int rCoord,int cCoord) {
    checkBattery();
    if (state) {
        drain();
        if(orientationState == orientation::Up)
        {
            return (g[rCoord -1][cCoord] == 1);
        }
        else if (orientationState == orientation::Down)
        {
            return (g[rCoord +1][cCoord] == 1); 
        }
        else if (orientationState == orientation::Right)
        {
            return (g[rCoord][cCoord + 1] == 1); 
        }
        else if (orientationState == orientation::Left)
        {
            return (g[rCoord][cCoord -1] == 1); 
        } 
        else
        {
            return false;
        }

    }
    return false;
}

void sensor::checkBattery() {
    if (battery <= 10) state = false;
}

void sensor::Recharge() {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    battery = 100;
    state = true;
}

double sensor::getBattery() {
    return battery;
}
/*Implementation invariant:
 * Recharge has a 2 second delay using thread.sleep(2000)
 * getBattery and getState doesn't mutate the data. So its okay functionality for client to have
 * isValid checks the battery every single time its called
 * isValid returns a bool for this version. Will change in future projects.
 * State is off/on of the sensor
 * Sensor is turned off when battery is 10%
 * Battery starts off at 100
 * changed the drainRate of the battery for the sensor instead of internally generated. We pass in the drainRate through the sensor's constructor
 */