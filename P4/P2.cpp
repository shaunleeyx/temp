/*
 * Author:Shaun Lee
 * Driver Overview: Tests out the functionality of robot class
 */
#include <iostream>
#include "sensor.h"
#include "robot.h"
#include <string>
#include <queue>
#include <memory>
#include <ctime>
void testCopy();
using namespace std;
const int SIZE = 5;
string file = "/Users/shaunlee/documents/GitHub/temp/P2/grid.txt";
const int defaultDrain = 1;
void testSharedPtr(shared_ptr<robot> obj);
void generateSharedPtr();
void testMove();
int RNG();
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
    srand(time(0));
    generateSharedPtr();
    testCopy();
    testMove();
}

void generateSharedPtr()
{
    cout << "using shared ptr" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        shared_ptr<robot>r = make_shared<robot>(file,defaultDrain);
        testSharedPtr(r);
    }
}

void testSharedPtr(shared_ptr<robot> obj)
{
    cout << "Origin of robot" << endl;
    cout << "Row " << obj->getRow() << " Column " << obj->getColumn() << endl;
    int random;
    for(int i = 0; i < SIZE; i++)
    {
        random = RNG();
        cout << "using move() on " << random << " 0 = up, 1 = down, 2 = right, 3 = left " << endl;
        obj->Move(random);
        cout << "Robot Coordinate:" << "Row " << obj->getRow() << " Column " << obj->getColumn() << endl;
    }
    cout << endl;
    for(int i = 0 ; i < SIZE; i++)
    {
        random = RNG();
        cout << "using moveOne() on " << random << " 0 = up, 1 = down, 2 = right, 3 = left " << endl;
        obj->MoveOne(random);
        cout << "Robot Coordinate:" << "Row " << obj->getRow() << " Column " << obj->getColumn() << endl;
    }
    cout << endl;
    cout << endl;
}

void testCopy()
{
    cout << "testing copying" << endl;
    robot a(file,defaultDrain);
    cout << "intialized obj a. used move(0) on obj a (north)" << endl;
    a.Move(0);
    double diffDrain = 2.0;
    robot b(file,diffDrain);
    cout << "copy constructor" << endl;
    robot c(a);
    cout << "copying a to obj c now printing obj c's coordinate" << endl;
    cout << "Robot Coordinate:" << "Row " << c.getRow() << " Column " << c.getColumn() << endl;
    cout << "operator overloading copying" << endl;
    cout << "assignment operator copying a to b";
    b = a;
    cout << "printing's b coordinates" << endl;
    cout << "Robot Coordinate:" << "Row " << b.getRow() << " Column " << b.getColumn() << endl;
}
void testMove()
{
    queue<shared_ptr<robot>> q;
    shared_ptr<robot>r = make_shared<robot>(file,defaultDrain);
    cout << "putting smart pointer in container" << endl;
    q.push(move(r));
    cout << "popping smart pointer from container" << endl;
    q.pop();
}

int RNG(){
    return (rand()%3)+0;
}

