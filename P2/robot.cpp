//
// Created by Shaun Lee on 2020-04-22.
//

#include "robot.h"
#include <iostream>
#include <string>
robot::robot(std::string str, double drainRate)
{
    sObj = new sensor(drainRate);
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

void robot::printCoord()
{
    std::cout << "amkldfmklamdsfklamdsklf" << std::endl;
   std::cout << rCoord << std::endl;
   std:: cout << cCoord << std::endl;
}

void robot::Move(int Dir)
{
    int sensed;
    switch(Dir){
        case 0:
            sensed = grid[rCoord-1][cCoord];
            while(sObj->isValid(sensed)){
                nAct->MoveForward(rCoord,cCoord);
                sensed = grid[rCoord-1][cCoord];
            }
            break;
        case 1:
            sensed = grid[rCoord+1][cCoord];
            while(sObj->isValid(sensed)){
                sAct->MoveForward(rCoord,cCoord);
                sensed = grid[rCoord+1][cCoord];
            }
            break;
        case 2:
            sensed = grid[rCoord][cCoord+1];
            while(sObj->isValid(sensed)){
                eAct->MoveForward(rCoord,cCoord);
                sensed = grid[rCoord][cCoord+1];
            }
            break;
        case 3:
            sensed = grid[rCoord][cCoord-1];
            while(sObj->isValid(sensed)){
                wAct->MoveForward(rCoord,cCoord);
                sensed = grid[rCoord][cCoord-1];
            }
            break;
        default:
            return;
    }
}

void robot::MoveOne(int Dir)
{
    int sensed;
    switch(Dir){
        case 0:
            sensed = grid[rCoord-1][cCoord];
            std::cout << sObj->isValid(sensed) << std::endl;
            if(sObj->isValid(sensed)) nAct->MoveForward(rCoord,cCoord);
            break;
        case 1:
            sensed = grid[rCoord+1][cCoord];
            std::cout << sObj->isValid(sensed) << std::endl;
            if(sObj->isValid(sensed)) sAct->MoveForward(rCoord,cCoord);
            break;
        case 2:
            sensed = grid[rCoord][cCoord+1];
            std::cout << sObj->isValid(sensed) << std::endl;
            if(sObj->isValid(sensed)) eAct->MoveForward(rCoord,cCoord);
            break;
        case 3:
            sensed = grid[rCoord][cCoord-1];
            std::cout << sObj->isValid(sensed) << std::endl;
            if(sObj->isValid(sensed)) wAct->MoveForward(rCoord,cCoord);
            break;
        default:
            break;
    }
}

bool robot::isPowered()
{
    return state;
}

bool robot::isValid(int num)
{
    return sObj->isValid(num);
}
//only moves if it has 1

void robot::Recharge()
{
    sObj->Recharge();
}
//Document this


robot::~robot()
{
}

robot::robot(const robot &obj)
{
    rCoord = obj.rCoord;
    cCoord = obj.cCoord;
    state = obj.state;
    sObj = obj.sObj;
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
    sObj = obj.sObj;
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
    swap(sObj, obj.sObj);
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
    swap(sObj, obj.sObj);
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