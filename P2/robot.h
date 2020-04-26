//
// Created by Shaun Lee on 2020-04-22.
//

#ifndef P2_ROBOT_H
#define P2_ROBOT_H
#include <string>
#include <fstream>

class robot {
public:
    robot(std::string str);
    int isValid();
    void Move();
    void MoveOne();
private:
    int row;
    int column;
    int grid[11][11];
    bool state;
};


#endif //P2_ROBOT_H
