//
// Created by Shaun Lee on 2020-04-22.
//

#include "actuator.h"
actuator::actuator(int dir)
{
Direction = dir; //dir: 0 = north, 1 = south, 2 = east, 3 = west
state = true;
}

void actuator::MoveForward(int& rCoord,int& cCoord)
{
    switch(Direction){
        case 0:
            rCoord-=1;
            break;
            //South
        case 1:
            rCoord+=1;
            break;
            //East
        case 2:
            cCoord+=1;
            break;
            //West
        case 3:
            cCoord-=1;
            break;
        default:
            break;
    }
}
bool actuator::isPoweredUp(){
    return state;
}
/*Implementation invariant:
 * MoveForward changes the row coordinate and the column coordinate from the robot through reference
 * Direction of actuator is assigned throguh the constructor of actuator's argument
 * actuator is always true no matter what
 * isPoweredUp returns the state of the object for actuator
 */