#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "stringhelper.h"
#include "rectangularvectors.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
class actuator;
class sensor;

//
// Created by Shaun Lee on 2020-04-22.
//

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

class robot
{
protected:
	orientation orientationState = static_cast<orientation>(0);
protected:
	enum class orientation
	{
			Up,
			Down,
			Left,
			Right
	};
protected:
	actuator *nAct;
	actuator *sAct;
	actuator *eAct;
	actuator *wAct;
	int rCoord = 0;
	int cCoord = 0;
	sensor *upSensor;
	sensor *downSensor;
	sensor *rightSensor;
	sensor *leftSensor;

private:
	int count = 0;
	std::wstring filename;
protected:
	std::vector<std::vector<int>> grid;
private:
	static constexpr int SIZE = 11;
	bool state = false;
	/*
	 *Precondition:string and double
	 *Postcondition:filename is str and 2d array copies the file,double sets the drainRate for the battery for the sensor
	 */
public:
	virtual ~robot()
	{
		delete nAct;
		delete sAct;
		delete eAct;
		delete wAct;
		delete upSensor;
		delete downSensor;
		delete rightSensor;
		delete leftSensor;
	}

	robot(const std::wstring &str, double drainRate);

	/*
	 *Precondition: int
	 *Postcondition:returns true or false
	 */
	bool isValid();
	//TODO document this

	int getColumn();

	int getRow();
	/*
	 *Precondition: None
	 *Postcondition: keeps moving robot up 
	 */
	virtual void Move();

	/*
	 *Precondition:None 
	 *Postcondition:moves the robot up once
	 */
	virtual void MoveOne();

	/*
	 *Precondition: state is set to something
	 *Postcondition: returns the state of object
	 */
	bool isPowered();

	/*
	 *Precondition: none
	 *Postcondition:recharges the battery of the sensor to 100
	 */
	//only moves if it has 1

	void Recharge();

};

//
/*Implementation invariant:
 * echos sensor's isvalid
 * echos actuator's moveforward() in move and moveone
 * copies the file to a 2d array and row and column coordinates are the same
 * move semantics uses swap for both = and the default move constructor
 * MoveOne uses sensor and detects for walls make sure the robot doesn't overlap with the wall
 * Move does the same thing but uses a while loop that invokes moveForward from the actuator until theres a wall in front
 * changed the boundaries of the grid to a variable so it removes the hardcoding
 * Made the protected variables like the sensor and actuator accessible to rotatingRobot
 * changed move() and moveone() to only go up because parent robot shouldn't beable to rotate or move sideways
 * every robot has 4 sensors for each direction
 * made a field called filename that encapsulates the string of the filename being passed into the param of constructor via constructor injection
 * throws exception if argument is null for constructor
 * initialized enum for direction in robot
 * changed the way 2darr gets processed from the file b/c c#
 */
