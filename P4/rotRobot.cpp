#include "rotRobot.h"

RotatingRobot::RotatingRobot(const std::string str, double drainRate) : robot(str,drainRate)
{

} 

void RotatingRobot::Rotate()
{
	switch (orientationState)
	{
		case orientation::Up:
			orientationState = orientation::Right;
			break;
		case orientation::Right:
			orientationState = orientation::Down;
			break;
		case orientation::Down:
			orientationState = orientation::Left;
			break;
		case orientation::Left:
			orientationState = orientation::Up;
			break;
		default:
			break;
	}
} 

void RotatingRobot::Move()
{
	switch (orientationState)
	{
		case orientation::Up:
			while (upCheck(rCoord,cCoord))
			{
				moveCount++;
				nAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Down:
			while (downCheck(rCoord,cCoord))
			{
				moveCount++;
				sAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Right:
			while (rightCheck(rCoord,cCoord))
			{
				moveCount++;
				eAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Left:
			while (leftCheck(rCoord,cCoord))
			{
				moveCount++;
				wAct->MoveForward(rCoord, cCoord);
			}
			break;
		default:
			break;
	}

}

void RotatingRobot::MoveOne()
{
	moveCount++;
	switch (orientationState)
	{
		case orientation::Up:
			if (upCheck(rCoord,cCoord))
			{
				nAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Down:
			if (downCheck(rCoord,cCoord))
			{
				sAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Right:
			if (rightCheck(rCoord,cCoord))
			{
				eAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Left:
			if (leftCheck(rCoord,cCoord))
			{
				wAct->MoveForward(rCoord, cCoord);
			}
			break;
		default:
			break;
	}

}


/*Implementation invariant:
 * the direction of the robot is set to north by default
 * move moves the robot forward until it hits a wall 
 * move once moves the robot forward once
 * orientation state rotate uses switch case statement for rotating the robot through the state of enums
 * the argument of the constructor passes into the robot constructor
 * default argument for drainRate is random between 1 - 10
 */