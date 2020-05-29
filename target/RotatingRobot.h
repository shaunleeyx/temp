#pragma once

#include "robot.h"
#include <string>
#include "rectangularvectors.h"

/**
 * Author:Shaun Lee
 * Platform:VSCode
 * Class Overview: rotating robot derives from robot which has all the functionality of robot plus new move and moveonce and a rotation function
 *
 * Class Invariant:  
 * uses the orientationstate from robot
 * move() moves the robot forward depending on the direction of the robot until sensors hit the wall
 * moveone() moves the robot forward by one depending on the direction 
 * rotate() rotates the robot clockwise north,east,south,west
 *  
 *
 * Interface Invariant:   
 * the robot starts facing up by default and then rotating clockwise just like a clock
 * orientationstate has to be set on a valid state
 * orientation default direction is set to north
 **/
class RotatingRobot : public robot
{


public:
	RotatingRobot(const std::wstring &str, double drainRate);
	/**
	 *PreCondition: existing orientationstate set to a direction
	 *PostCondition: rotates the orientationstate up,right,down,left
	 **/
	void Rotate();
	/**
	 *PreCondition: none
	 *PostCondition: moves the robot to the direction its facing
	 **/
	void Move() override;

	/**
	 *PreCondition: none
	 *PostCondition: moves the robot in the direction once
	 **/

	void MoveOne() override;

};
/*Implementation invariant:
 * the direction of the robot is set to north by default
 * move moves the robot forward until it hits a wall 
 * move once moves the robot forward once
 * orientation state rotate uses switch case statement for rotating the robot through the state of enums
 * the argument of the constructor passes into the robot constructor
 */
