#ifndef P2_TRANSROBOT_H
#define P2_TRANSROBOT_H

#include "robot.h"
#include <string>
#include <random>

/**
 * Author:Shaun Lee
 * Platform:VSCode
 * Class Overview:This class has all the functionality of robot plus up down left right
 *
 * Class Invariant: 
 * don't go out of bounds in the grid
 * Forward() moves the position of the robot north
 * Back() move the position of the robot south
 * Left() moves the position of the robot left 
 * Right() moves the position of the robot right
 * moves moves the robot forward depending on the direction of the robot
 *
 * Interface Invariant:   
 * robot cannot go through walls
 * rCoord and cCoord cannot go below 0 
 * using the direction function changes the direction of the robot
 * 
 **/
class TranRobot : public robot
{
public:
	TranRobot(const std::string str, double = (rand() % 100) + 1);
	/**
	 *PreCondition: existing 2 ints
	 *PostCondition: changing state of ints
	 **/
	void Forward();
	/**
	 *PreCondition: existing 2 ints
	 *PostCondition: changing state of ints
	 **/
	void Left();
	/**
	 *PreCondition: existing 2 ints
	 *PostCondition: changing state of ints
	 **/
	void Right();
	/**
	 *PreCondition: existing 2 ints
	 *PostCondition: changing state of ints
	 **/
	void Back();

	/**
	 *PreCondition: none
	 *PostCondition: changing state of ints
	 **/
	void Move() override;

	/**
	 *PreCondition: none
	 *PostCondition: changing state of coord
	 **/
	void MoveOne() override;
};



/*Implementation invariant:
 * Constructor argument passes the arguments to the robot
 * moving a direction changes the direction of the robot
 * rCoord and cCoord are changed through references passed in
 * override parent's move() with transrobot()
 * directional functions uses directional actuator with directional sensors
 */
#endif