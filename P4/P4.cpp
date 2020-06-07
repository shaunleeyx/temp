/*
 * Author:Shaun Lee
 * Driver Overview: Tests out the functionality of robot class and the overload operators
 */
#include <iostream>
#include "sensor.h"
#include "robot.h"
#include "rotRobot.h"
#include "tranRobot.h"
#include <string>
#include <queue>
#include <memory>
#include <ctime>
#include <variant>
#include <algorithm> 
using namespace std;
const int SIZE = 5;
void testRobot(robot* obj);
void testRotate(RotatingRobot* obj);
void testTran(TranRobot* obj);
void testOperators();
void testHeterogenous();
string file = "/Users/shaunlee/documents/GitHub/temp/P2/grid.txt";
 
int main() {
    srand(time(0)); 
    robot* robotArr[SIZE];
    RotatingRobot* rotateArr[SIZE];
    TranRobot* TranArr[SIZE];
    for(int i = 0; i < SIZE;i++)
    {
       robotArr[i] = new robot(file);
       cout << "robot " << i << "\n";
       testRobot(robotArr[i]);
    } 
    for(int i = 0; i < SIZE;i++)
    {
       cout << "rotaterobot " << i << "\n";
       rotateArr[i] = new RotatingRobot(file);
       testRotate(rotateArr[i]);
    } 
    for(int i = 0; i < SIZE;i++)
    {
       cout << "tranrobot " << i << "\n";
       TranArr[i] = new TranRobot(file);
       testTran(TranArr[i]);
    } 
    testHeterogenous();
    testOperators(); 
}

void testTran(TranRobot* obj)
{
    obj->Forward();
    cout << "\tforward()" << obj->getRow() << " " << obj->getColumn() << endl;
    obj->Back();
    cout << "\tBack()" << obj->getRow() << " " << obj->getColumn() << endl;
    obj->Left();
    cout << "\tLeft()" << obj->getRow() << " " << obj->getColumn() << endl;
    obj->Right();
    cout << "\tRight()" << obj->getRow() << " " << obj->getColumn() << endl; 
    cout << "\tmovecount is " << obj->getMoveCount() << endl;
}

void testRotate(RotatingRobot* obj)
{
    obj->Move();
    cout << "\tused moveone()" << obj->getRow() << " " << obj->getColumn() << endl;
    obj->Rotate();
    cout << "\tused rotate()" << endl;
    obj->Rotate();
    cout << "\tused rotate()" << endl;
    obj->Rotate();
    cout << "\tused rotate()" << endl;
    obj->Move();
    cout << "\tused moveone()" << obj->getRow() << " " << obj->getColumn() << endl; 
    cout << "\tmovecount is " << obj->getMoveCount() << endl;
     cout << endl;

}

void testRobot(robot* obj)
{
     obj->MoveOne();
     cout << "\tused moveone()" << obj->getRow() << " " << obj->getColumn() << endl;
     obj->Move();
     cout << "\tused move()" << obj->getRow() << " " << obj->getColumn() << endl;
     obj->MoveOne();
     cout << "\tused moveone()" << obj->getRow() << " " << obj->getColumn() << endl;
     obj->Move();
     cout << "\tused move()" << obj->getRow() << " " << obj->getColumn() << endl;
    cout << "\tmovecount is " << obj->getMoveCount() << endl;
     cout << endl; } 

void testHeterogenous()
{
    cout << "\ntesting Heterogenous" << endl;
    const int SIZE = 5;
    vector<robot> container;
    for(int i = 0; i < SIZE; i++)
    { 
        cout << "pushing robot objects" << endl;
        container.push_back(robot(file));
    }
    for(int i = 0; i < SIZE; i++) 
    {
        cout << "pushing rotatingbot objects" << endl;
        container.push_back(RotatingRobot(file));
    } 
    for(int i = 0; i < SIZE; i++) 
    {
        cout << "pushing tranbot objects" << endl;
        container.push_back(TranRobot(file));
    }
    cout << endl; 
}
void testOperators()
{
    robot robot1(file);
    robot robot2(file);
    RotatingRobot rotate1(file);
    RotatingRobot rotate2(file);
    TranRobot tran1(file);
    TranRobot tran2(file);
    cout << "the comparison operators compare the move count of each object" << endl;
    cout << "robot1 == robot2:" << (robot1 == robot2) << endl;
    robot1.MoveOne();
    cout<< "robot1 kused moveone();" << endl;
    cout << "robot1 == robot2:" << (robot1 == robot2) << endl;
    cout << "robot1 != robot2:" << (robot1 != robot2) << endl;
    cout << "robot1 > robot2:" << (robot1 > robot2) << endl;
    cout << "robot1 < robot2:" << (robot1 < robot2) << "\n" <<endl;

    cout << "rotate1 == rotate2:" << (rotate1 == rotate2) << endl;
    rotate1.MoveOne();
    cout<< "rotate1 used moveone();" << endl;
    cout << "rotate1 == rotate2:" << (rotate1 == rotate2) << endl;
    cout << "rotate1 != rotate2:" << (rotate1 != rotate2) << endl;
    cout << "rotate1 > rotate2:" << (rotate1 > rotate2) << endl;
    cout << "rotate1 < rotate2:" << (rotate1 < rotate2) << "\n" << endl;


    cout << "tran1 == tran2:" << (tran1 == tran2) << endl;
    tran1.MoveOne();
    cout<< "tran1 used moveone();" << endl;
    cout << "tran1 == tran2:" << (tran1 == tran2) << endl;
    cout << "tran1 != tran2:" << (tran1 != tran2) << endl;
    cout << "tran1 > tran2:" << (tran1 > tran2) << endl;
    cout << "tran1 < tran2:" << (tran1 < tran2) << "\n" << endl;
}

