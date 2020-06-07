//
// Created by Shaun Lee on 2020-04-22.
//

#include "robot.h"
#include <iostream>
#include <string>
#include <random>
robot::robot(std::string str, double drainRate)
{
    moveCount = 0;
    orientationState = orientation::Up;
    filename = str; 
    nAct = new actuator(0);
    sAct = new actuator(1);
    eAct = new actuator(2);
    wAct = new actuator(3); 
    rCoord = 5;
    cCoord = 5;
    state = true;
    std::string text;
    std::ifstream file(filename);
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
	for(int i = 0; i < SIZE; i++)
	{
		upSensorArr[i] = new sensor(0,grid,drainRate);
		downSensorArr[i] = new sensor(1,grid,drainRate);
		rightSensorArr[i] = new sensor(2,grid,drainRate);
		leftSensorArr[i] = new sensor(3,grid,drainRate);
	}
} 

int robot::getRow()
{
    return rCoord;
}

int robot::getColumn()
{
    return cCoord;
}


void robot::Move()
{
    while(upCheck(rCoord,cCoord)){
        nAct->MoveForward(rCoord,cCoord); 
        moveCount++;
    }
}

void robot::MoveOne()
{
    moveCount++;
    if(upCheck(rCoord,cCoord)) nAct->MoveForward(rCoord,cCoord);
}

bool robot::isPowered()
{
    return state;
}

bool robot::isValid(int num)
{
    return (upCheck(rCoord,cCoord) && downCheck(rCoord,cCoord) && rightCheck(rCoord,cCoord) && leftCheck(rCoord,cCoord));
}

void robot::Charge()
{
	if(!upCheck(rCoord,cCoord)&&!downCheck(rCoord,cCoord)&&!leftCheck(rCoord,cCoord)&&!rightCheck(rCoord,cCoord)){
		for(int i = 0; i < SIZE; i++)
		{ 
			upSensorArr[i]->Recharge();
			downSensorArr[i]->Recharge();
			rightSensorArr[i]->Recharge();
			leftSensorArr[i]->Recharge();
		}
	}
}

robot::~robot()
{
}

bool robot::upCheck(int rCoord,int cCoord)
{
	int count = 0;
	for(int i = 0;i < SIZE; i++)
	{
		if(upSensorArr[i]->getBattery() > 80 && upSensorArr[i]->isValid(rCoord,cCoord))
		{
			count++;
		}
	}
	return (count >= 2);
}

bool robot::downCheck(int rCoord,int cCoord)
{
	int count = 0;
	for(int i = 0;i < SIZE; i++)
	{
		if(downSensorArr[i]->getBattery() > 80 && downSensorArr[i]->isValid(rCoord,cCoord))
		{
			count++;
		}
	}
	return (count >= 2);
}

bool robot::leftCheck(int rCoord,int cCoord)
{
	int count = 0;
	for(int i = 0;i < SIZE; i++)
	{
		if(leftSensorArr[i]->getBattery() > 80 && leftSensorArr[i]->isValid(rCoord,cCoord))
		{
			count++;
		}
	}
	return (count >= 2);
}

bool robot::rightCheck(int rCoord,int cCoord)
{
	int count = 0;
	for(int i = 0;i < SIZE; i++)
	{
		if(rightSensorArr[i]->getBattery() > 80 && rightSensorArr[i]->isValid(rCoord,cCoord))
		{
			count++;
		}
	}
	return (count >= 2);
}

int robot::getMoveCount()
{
    return moveCount;
}

robot::robot(const robot &obj)
{
    for(int i = 0; i < SIZE; i++)
    { 
	upSensorArr[i] = obj.upSensorArr[i];
	downSensorArr[i] = obj.downSensorArr[i];
	leftSensorArr[i] = obj.leftSensorArr[i];
	rightSensorArr[i] = obj.rightSensorArr[i];
    }
    rCoord = obj.rCoord;
    cCoord = obj.cCoord;
    state = obj.state;
    nAct = obj.nAct;
    sAct = obj.sAct;
    wAct = obj.wAct;
    eAct = obj.eAct;
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= 10; j++)
        {
            grid[i][j] = obj.grid[i][j];
        }
    }
}
robot &robot::operator=(const robot &obj){
    if (this == &obj)
    {
        return *this;
    }
    for(int i = 0; i < SIZE; i++)
    { 
	upSensorArr[i] = obj.upSensorArr[i];
	downSensorArr[i] = obj.downSensorArr[i];
	leftSensorArr[i] = obj.leftSensorArr[i];
	rightSensorArr[i] = obj.rightSensorArr[i];
    }
    rCoord = obj.rCoord;
    cCoord = obj.cCoord;
    state = obj.state;
    nAct = obj.nAct;
    sAct = obj.sAct;
    wAct = obj.wAct;
    eAct = obj.eAct;
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= 10; j++)
        {
            grid[i][j] = obj.grid[i][j];
        }
    }
    return *this;
}

robot::robot(robot &&obj)
{
    for(int i = 0; i < SIZE; i++)
    { 
	swap(upSensorArr[i],obj.upSensorArr[i]);
	swap(downSensorArr[i],obj.downSensorArr[i]);
	swap(leftSensorArr[i],obj.leftSensorArr[i]);
	swap(rightSensorArr[i],obj.rightSensorArr[i]);
    }   
    swap(rCoord,obj.rCoord);
    swap(cCoord,obj.cCoord);
    swap(state,obj.state);
    swap(nAct,obj.nAct);
    swap(sAct,obj.sAct);
    swap(wAct,obj.wAct);
    swap(eAct,obj.eAct);
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= 10; j++)
        {
            swap(grid[i][j],obj.grid[i][j]);
        }
    }
}

robot &robot::operator=(robot &&obj)
{
    for(int i = 0; i < SIZE; i++)
    { 
	swap(upSensorArr[i],obj.upSensorArr[i]);
	swap(downSensorArr[i],obj.downSensorArr[i]);
	swap(leftSensorArr[i],obj.leftSensorArr[i]);
	swap(rightSensorArr[i],obj.rightSensorArr[i]);
    }   
    swap(rCoord,obj.rCoord);
    swap(cCoord,obj.cCoord);
    swap(state,obj.state);
    swap(nAct,obj.nAct);
    swap(sAct,obj.sAct);
    swap(wAct,obj.wAct);
    swap(eAct,obj.eAct);
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= 10; j++)
        {
            swap(grid[i][j],obj.grid[i][j]);
        }
    }
    return *this;
}

template <typename T>
void robot::swap(T &lhs, T &rhs) {
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}
//pre : none
//post : none

bool robot::operator==(robot &obj) 
{
    return moveCount == obj.moveCount;
}

//pre : none
//post : none
bool robot::operator!=(robot &obj) 
{
    return moveCount != obj.moveCount;
}

//pre : none
//post : none
bool robot::operator>(robot &obj) 
{
    return moveCount > obj.moveCount;
}

//pre : none
//post : none
bool robot::operator<(robot &obj) 
{
    return moveCount < obj.moveCount;
}

//pre : none
//post : none
bool robot::operator>=(robot &obj) 
{
    return moveCount >= obj.moveCount;
}

//pre : none
//post : none
bool robot::operator<=(robot &obj) 
{
    return moveCount <= obj.moveCount;
}

/*Implementation invariant:
 * echos sensor's isvalid
 * echos actuator's moveforward() in move and moveone
 * copies the file to a 2d array and row and column coordinates are the same
 * move semantics uses swap for both = and the default move constructor
 * MoveOne uses sensor and detects for walls make sure the robot doesn't overlap with the wall
 * Move does the same thing but uses a while loop that invokes moveForward from the actuator until theres a wall in front
 * gave constructor a default argument for drainRate it ranges from 1 - 10
 * default argument for drainRate is random between 1 - 10
 * implemented movecount that counts how many times the robot moved
 * implemented overload operators that does the normal comparison with the count values in each robot obj
 * I didn't implement other operators because it didn't make sense for me to have arithmetic operators 
 */