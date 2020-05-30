#include "TranRobot.h"

TranRobot::TranRobot(const std::string str, double drainRate) : robot(str,drainRate)
{

}

void TranRobot::Forward()
{
	if (upSensor->isValid(rCoord,cCoord))
	{
		nAct->MoveForward(rCoord, cCoord);
	}
	orientationState = orientation::Up;
}

void TranRobot::Left()
{
	if (leftSensor->isValid(rCoord,cCoord))
	{
		wAct->MoveForward(rCoord, cCoord);
	}
	orientationState = orientation::Left;
}

void TranRobot::Right()
{
	if (rightSensor->isValid(rCoord,cCoord))
	{
		eAct->MoveForward(rCoord, cCoord);
	}
	orientationState = orientation::Right;
}

void TranRobot::Back()
{
	if (downSensor->isValid(rCoord,cCoord))
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

void TranRobot::MoveOne()
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
