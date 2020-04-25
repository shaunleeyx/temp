//
// Created by Shaun Lee on 2020-04-22.
//

#ifndef P2_ACTUATOR_H
#define P2_ACTUATOR_H


class actuator {
public:
    void MoveForward();
    void isPoweredUp();
private:
    bool state;
    enum Direction {up,down,left,right};
};


#endif //P2_ACTUATOR_H
