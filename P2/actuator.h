//
// Created by Shaun Lee on 2020-04-22.
//

#ifndef P2_ACTUATOR_H
#define P2_ACTUATOR_H
#include <string>

class actuator {
private:

    static const int column = 11;
    static const int row = 11;
    bool state;
    int Direction;
public:
    void MoveForward(int&,int&);
    bool isPoweredUp();
    actuator(int dir);
};


#endif //P2_ACTUATOR_H
