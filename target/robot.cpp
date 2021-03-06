﻿#include "robot.h"
#include "actuator.h"
#include "sensor.h"
#include <iostream>

robot::robot(std::string str, double drainRate)
{
	if (str == L"")
	{
		throw std::invalid_argument("invalid file");
	}
	orientationState = orientation::Up;
	filename = str;
	count = 0;
	// upSensor = new sensor(drainRate,0,grid);
	// downSensor = new sensor(drainRate,1,grid);
	// rightSensor = new sensor(drainRate,2,grid);
	// leftSensor = new sensor(drainRate,3,grid);
	nAct = new actuator(0);
	sAct = new actuator(1);
	eAct = new actuator(2);
	wAct = new actuator(3);
	rCoord = 5;
	cCoord = 5;
	state = true;
	std::string text;
	std::ifstream file(str);
	if (file.is_open())
	{
	for(int r = 0; r <= 10; r++)
	{
		for(int c = 0; c <= 10; c++)
		{
		std::string temp;
		file >> temp;
		grid[r][c] = stoi(temp);
		}
	}
	file.close();
	}
}

bool robot::isValid()
{

	return (upSensor->isValid(rCoord,cCoord) && downSensor->isValid(rCoord,cCoord) && rightSensor->isValid(rCoord,cCoord) && leftSensor->isValid(rCoord,cCoord));
}

int robot::getColumn()
{
	return cCoord;
}

int robot::getRow()
{
	return rCoord;
}

void robot::Move()
{
	while (upSensor->isValid(rCoord,cCoord))
	{
		nAct->MoveForward(rCoord, cCoord);
	}
}

void robot::MoveOne()
{
	if (upSensor->isValid(rCoord,cCoord))
	{
		nAct->MoveForward(rCoord, cCoord);
	}
}

bool robot::isPowered()
{
	return state;
}

void robot::Recharge()
{
	upSensor->Recharge();
	downSensor->Recharge();
	rightSensor->Recharge();
	leftSensor->Recharge();
}
