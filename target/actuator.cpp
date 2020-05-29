#include "actuator.h"

void actuator::MoveForward(int &rCoord, int &cCoord)
{
	switch (Direction)
	{
		case 0:
			rCoord -= 1;
			break;
			//South
		case 1:
			rCoord += 1;
			break;
			//East
		case 2:
			cCoord += 1;
			break;
			//West
		case 3:
			cCoord -= 1;
			break;
		default:
			break;
	}
}

bool actuator::isPoweredUp()
{
	return state;
}

actuator::actuator(int dir)
{
Direction = dir; //dir: 0 = north, 1 = south, 2 = east, 3 = west
state = true;
}
