//
// Created by Shaun Lee on 2020-04-22.
//

#include "robot.h"
#include <iostream>
#include <string>
robot::robot(std::string str, double drainRate)
{
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
    upSensor = new sensor(drainRate,0,grid);
    downSensor = new sensor(drainRate,1,grid);
    rightSensor = new sensor(drainRate,2,grid);
    leftSensor = new sensor(drainRate,3,grid);
} 

int robot::getRow()
{
    return rCoord;
}

int robot::getColumn()
{
    return cCoord;
}


void robot::Move(int Dir)
{
    while(upSensor->isValid(rCoord,cCoord)) nAct->MoveForward(rCoord,cCoord); 
}

void robot::MoveOne(int Dir)
{
    if(upSensor->isValid(rCoord,cCoord)) nAct->MoveForward(rCoord,cCoord);
}

bool robot::isPowered()
{
    return state;
}

bool robot::isValid(int num)
{
    return (upSensor->isValid(rCoord,cCoord) && downSensor->isValid(rCoord,cCoord) && rightSensor->isValid(rCoord,cCoord) && leftSensor->isValid(rCoord,cCoord));
}

//only moves if it has 1
//TODO
void robot::Recharge()
{
    upSensor->Recharge();
    downSensor->Recharge();
    leftSensor->Recharge();
    rightSensor->Recharge();
}
//TODO

robot::~robot()
{
}

robot::robot(const robot &obj)
{
    rCoord = obj.rCoord;
    cCoord = obj.cCoord;
    state = obj.state;
    upSensor = obj.upSensor;
    downSensor = obj.downSensor;
    rightSensor = obj.rightSensor;
    leftSensor = obj.leftSensor;
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
    rCoord = obj.rCoord;
    cCoord = obj.cCoord;
    state = obj.state;
    upSensor = obj.upSensor;
    downSensor = obj.downSensor;
    rightSensor = obj.rightSensor;
    leftSensor = obj.leftSensor;
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
    swap(upSensor, obj.upSensor);
    swap(downSensor, obj.downSensor);
    swap(rightSensor, obj.rightSensor);
    swap(leftSensor, obj.leftSensor);
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
    swap(upSensor, obj.upSensor);
    swap(downSensor, obj.downSensor);
    swap(rightSensor, obj.rightSensor);
    swap(leftSensor, obj.leftSensor);
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

/*Implementation invariant:
 * echos sensor's isvalid
 * echos actuator's moveforward() in move and moveone
 * copies the file to a 2d array and row and column coordinates are the same
 * move semantics uses swap for both = and the default move constructor
 * MoveOne uses sensor and detects for walls make sure the robot doesn't overlap with the wall
 * Move does the same thing but uses a while loop that invokes moveForward from the actuator until theres a wall in front
 */