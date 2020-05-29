#pragma once

//
// Created by Shaun Lee on 2020-04-22.
//

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

class actuator
{
private:
	static constexpr int column = 11;
	static constexpr int row = 11;
	bool state = false;
	int Direction = 0;
	/*
	  *Precondition:row and column int from robot
	  *Postcondition: changes the value for row and column
	  */
public:
	void MoveForward(int &rCoord, int &cCoord);

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
/*Implementation invariant:
 * MoveForward changes the row coordinate and the column coordinate from the robot through reference
 * Direction of actuator is assigned throguh the constructor of actuator's argument
 * actuator is always true no matter what
 * isPoweredUp returns the state of the object for actuator
 */

#endif //P2_ACTUATOR_H