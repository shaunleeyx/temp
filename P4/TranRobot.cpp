#include "tranRobot.h"

TranRobot::TranRobot(const std::string str, double drainRate) : robot(str,drainRate)
{

}


void TranRobot::Forward()
{
	moveCount++;
	if (upCheck(rCoord,cCoord))
	{
		for(int i = 0; i < SIZE; i++)
		{
		nAct->MoveForward(rCoord, cCoord); 
		}
	}
	orientationState = orientation::Up;
}

void TranRobot::Left()
{
	moveCount++;
	if (leftCheck(rCoord,cCoord))
	{
		wAct->MoveForward(rCoord, cCoord);
	}
	orientationState = orientation::Left;
}

void TranRobot::Right()
{
	moveCount++;
	if (rightCheck(rCoord,cCoord))
	{
		eAct->MoveForward(rCoord, cCoord);
	}
	orientationState = orientation::Right;
}

void TranRobot::Back()
{
	moveCount++;
	if (downCheck(rCoord,cCoord))
	{
		sAct->MoveForward(rCoord, cCoord);
	}
	orientationState = orientation::Down;
}

void TranRobot::Move()
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

void TranRobot::MoveOne()
{
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
 * Constructor argument passes the arguments to the robot
 * moving a direction changes the direction of the robot
 * rCoord and cCoord are changed through references passed in
 * override parent's move() with transrobot()
 * directional functions uses directional actuator with directional sensors
 * add bool function that checks if at least 2 sensors have 80% battery and returns a bool from each direction
 * default argument for drainRate is random between 1 - 10
 */