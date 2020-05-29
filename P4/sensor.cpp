
#include <thread>
#include <chrono>
#include "sensor.h"

sensor::sensor(double input,int dir,int grid[11][11]) {
    if (input > 100 || input < 0) input = 1; //document this design decision
    g = grid;
    battery = 100;
    drainRate = input;
    state = true;
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

bool sensor::isValid(int digit) {
    checkBattery();
    if (state) {
        drain();
        return (digit == 1);
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