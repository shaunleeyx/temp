/**
 * Author:Shaun Lee
 * Platform:CLion
 * Class Overview:This class is the robot that can move around the maze
 *
 * Class Invariant:
 *                     for first arg in move() inputting a 0 = north, 1 = south, 2 = right, 3 = left
 *                     Robot is always turned on
 *                     rCoord and cCoord is the row,column coordinates for the robot's position
 *                     able to be copied
 *                     isPowered returns the state of object (on/off)
 *                     getRow and getColumn returns the coordinates for rCoord and cCoord
 *                     size of the maze has to be always 11x11
 *                     robot cannot get outside the maze
 *
 * Interface Invariant:
 *                     robot has 4 actuator for each direction
 *                     takes in a file through 1st argument in param
 *                     2nd argument is drainRate for the battery for the Sensor
 *                     if drainRate < 0 it will default to 1 if higher than 100 it will default to 1
 *                     Recharge recharges the battery for the sensor
 *                     inputting more than 4 will make hte function do nothing
 **/

#ifndef P2_ROBOT_H
#define P2_ROBOT_H
#include <string>
#include <fstream>
#include "sensor.h"
#include "actuator.h"
class robot {
public:
    /*
     *Precondition:string and double
     *Postcondition:filename is str and 2d array copies the file,double sets the drainRate for the battery for the sensor
     */
    robot(std::string str,double);
    /*
     *Precondition: int
     *Postcondition:returns true or false
     */
    bool isValid(int);
    /*
     *Precondition:int from 0 to 4
     *Postcondition: moves the robot in direction depending on dir until a wall is in front
     */
    void Move(int Dir);
    /*
     *Precondition: int from 0 to 4
     *Postcondition:moves the robot once
     */
    void MoveOne(int Dir);
    /*
     *Precondition: state is set to something
     *Postcondition: returns the state of object
     */
    bool isPowered();
    /*
     *Precondition: none
     *Postcondition:recharges the battery of the sensor to 100
     */
    void Recharge();
    ~robot();
    /*
     *Precondition: existing robot
     *Postcondition: copies the object robots
     */
    robot(const robot &obj);
    /*
     *Precondition: existing robot
     *Postcondition:transfer ownership of the robot
     */
    robot(robot &&obj);
    /*
     *Precondition: existing robot
     *Postcondition:copis the object robot
     */
    robot &operator=(const robot &obj);
    /*
     *Precondition:existing robot
     *Postcondition:transfers ownership of robot
     */
    robot &operator=(robot &&obj);
    template <typename T>
    void swap(T &lhs, T &rhs);
    int getRow();
    int getColumn();

private:
    enum orientation 
    {
        Up,
        Down,
        Left,
        Right
    };
    orientation orientationState;
    sensor* upSensor;
    sensor* downSensor;
    sensor* rightSensor;
    sensor* leftSensor;
    int rCoord;
    int cCoord;
    static const int SIZE = 11;
    int grid[SIZE][SIZE];
    bool state;
    actuator* nAct;
    actuator* sAct;
    actuator* wAct;
    actuator* eAct;
    std::string filename;

};


#endif //P2_ROBOT_H
