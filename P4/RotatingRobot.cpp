#include "RotatingRobot.h"

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
			while (upSensor->isValid(rCoord,cCoord))
			{
				nAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Down:
			while (downSensor->isValid(rCoord,cCoord))
			{
				sAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Right:
			while (rightSensor->isValid(rCoord,cCoord))
			{
				eAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Left:
			while (leftSensor->isValid(rCoord,cCoord))
			{
				wAct->MoveForward(rCoord, cCoord);
			}
			break;
		default:
			break;
	}

}

void RotatingRobot::MoveOne()
{
	switch (orientationState)
	{
		case orientation::Up:
			if (upSensor->isValid(rCoord,cCoord))
			{
				nAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Down:
			if (downSensor->isValid(rCoord,cCoord))
			{
				sAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Right:
			if (rightSensor->isValid(rCoord,cCoord))
			{
				eAct->MoveForward(rCoord, cCoord);
			}
			break;
		case orientation::Left:
			if (leftSensor->isValid(rCoord,cCoord))
			{
				wAct->MoveForward(rCoord, cCoord);
			}
			break;
		default:
			break;
	}

}
