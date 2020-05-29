/**
 * Author:Shaun Lee
 * Platform:CLion
 * Class Overview:This class is for a sensor that sense something that hasn't been implmented probably in p2. For now it
 *                just works if the battery is above a certain threhold
 *
 * Class Invariant:  battery cannot be negative. If the battery is below 0 it will default to 0.
 *                   the number variables are all doubles so don't overflow beyond what a double can hold
 *                   isValid has nothing passed in param so its hard to mutate it
 *                   min is the lowest drain rate it can be
 *                   max is the highest number that the drain rate can be
 *                   drain rate is randomly generated between min and max
 *
 * Interface Invariant:     implemented a get call for the client. Because I think it is necessary for the client to know what battery is the sensor at. just like this laptop I'm using
 *                          State is essentially if the sensor is on or off. On is true and off is false.
 *                          getState is a public functionality for the client to know whether the sensor is off or on
 *                          battery starts off at 100% when the sensor is created
 *                          drain() will not work if the sensor is turned off
 **/


#ifndef P2_SENSOR_H
#define P2_SENSOR_H


class sensor {
private:
    static const int SIZE = 11;
    enum orientation 
    {
        Up,
        Down,
        Left,
        Right
    };
    orientation orientationState;
    int g[11][11];
    bool state;
    double battery;
    double drainRate;
    /*
    *Precondition:none
    *Postcondition:changes the state of state if battery is at 10% or below
    */
    void checkBattery();

public:
    double getdrainRate();
    sensor(double,int,int[11][11]);
    /*
    *Precondition: initialized class
    *Postcondition: decreases the battery based on the drainRate.
    */
    void drain();
    /*
    *Precondition:None
    *Postcondition: returns true or false based on the battery
     */

    bool isValid(int rCoord,int cCoord);

    /*
       *Precondition:none
       *Postcondition: changes the state to true and battery to 100
       */
    void Recharge();
    double getBattery();
    
};



#endif //P2_SENSOR_H