#include "sensor.h"

sensor::sensor(double input, int dir, std::vector<std::vector<int>> &grid)
{
	this->grid = grid;
	switch (dir)
	{
		case 0:
			orientationState = orientation::Up;
			break;
		case 1:
			orientationState = orientation::Down;
			break;
		case 2:
			orientationState = orientation::Right;
			break;
		case 3:
			orientationState = orientation::Left;
			break;
		default:
			orientationState = orientation::Up;
			break;
	}
	if (input > 100 || input < 0)
	{
		input = 1;
	}
	battery = 100;
	drainRate = input;
	state = true;
}

void sensor::drain()
{
	if (battery == 0 || !state)
	{
		return;
	}
	battery -= drainRate;
	if (battery < 0)
	{
		battery = 0;
	}
}

bool sensor::isValid(int rCoord, int cCoord)
{
	checkBattery();
	if (state)
	{
		drain();
		if (orientationState == orientation::Up)
		{
			return (grid[rCoord - 1][cCoord] == 1);
		}
		else if (orientationState == orientation::Down)
		{
			return (grid[rCoord + 1][cCoord] == 1);
		}
		else if (orientationState == orientation::Right)
		{
			return (grid[rCoord][cCoord + 1] == 1);
		}
		else if (orientationState == orientation::Left)
		{
			return (grid[rCoord][cCoord - 1] == 1);
		}
		else
		{
			return false;
		}

	}
	return false;
}

void sensor::Recharge()
{
	delay(200);
	battery = 100;
	state = true;
}

double sensor::getBattery()
{
	return battery;
}

void sensor::checkBattery()
{
	if (battery <= 10)
	{
		state = false;
	}
}
