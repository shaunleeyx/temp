/*
 * Author:Shaun Lee
 * Driver Overview: Tests out the functionality of robot class
 */
#include <iostream>
#include "sensor.h"
#include "robot.h"
#include "RotatingRobot.h"
#include "TranRobot.h"
#include <string>
#include <queue>
#include <memory>
#include <ctime>
using namespace std;
string file = "/Users/shaunlee/documents/GitHub/temp/P2/grid.txt"; 
int main() {
    srand(time(0));
    robot r(file);
    RotatingRobot a(file);
    TranRobot b(file);
}
