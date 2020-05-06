/**
 * Author:Shaun Lee
 * Platform:CLion
 * Class Overview:This class is a helps the robot to move
 *
 * Class Invariant:
 * Constructor takes in a number which then declares the direction of where the actuator moves 0 = north,1 = south, 2 = east, 3 = west
 * column and row var is the size of the maze
 * isPoweredUp returns the state of the actuator(on/off)
 *
 * Interface Invariant:
 * column and row var has to always be 11
 * state of actuator is always true
 **/

#ifndef P2_ACTUATOR_H
#define P2_ACTUATOR_H

#include <string>

class actuator {
private:
    static const int column = 11;
    static const int row = 11;
    bool state;
    int Direction;
public:
    /*
      *Precondition:row and column int from robot
      *Postcondition: changes the value for row and column
      */
    void MoveForward(int &, int &);

    /*
     *Precondition:state is intialized
     *Postcondition:returns state
     */
    bool isPoweredUp();

    /*
     *Precondition: int from 0 to 4
     *Postcondition: changes int direction of actuator
     */
    actuator(int dir);
};


#endif //P2_ACTUATOR_H

