//
// Created by Shaun Lee on 2020-04-22.
//

#ifndef P2_ROBOT_H
#define P2_ROBOT_H
#include <string>
#include <fstream>
#include "sensor.h"
#include "actuator.h"
class robot {
public:
    robot(std::string str,double);
    bool isValid(int);
    void Move(int Dir);
    void MoveOne(int Dir);
    bool isPowered();
    void Recharge();
    void printCoord();
    ~robot();
    robot(const robot &obj);
    robot(robot &&obj);
    robot &operator=(const robot &obj);
    robot &operator=(robot &&obj);
    template <typename T>
    void swap(T &lhs, T &rhs);

private:
    sensor* sObj;
    int rCoord;
    int cCoord;
    int grid[11][11];
    bool state;
    actuator* nAct;
    actuator* sAct;
    actuator* wAct;
    actuator* eAct;
};


#endif //P2_ROBOT_H
