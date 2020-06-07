#ifndef P2_ROTATINGROBOT_H
#define P2_ROTATINGROBOT_H
#include "robot.h"
#include <string>
#include <random>

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
 * operator > compare if rotatingrobot obj is greater than another rotatingrobot obj's movecount
 * operator < compare if rotatingrobot obj is less than another rotatingrobot obj's movecount
 * operator != compare if rotatingrobot obj is not equal to another rotatingrobot obj's movecount
 * operator == compare if rotatingrobot obj is equal to another rotatingrobot obj's movecount
 * 
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
	RotatingRobot(const std::string str, double = (rand() % 10) + 1);
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


#endif// P2_ROTATINGROBOT_H