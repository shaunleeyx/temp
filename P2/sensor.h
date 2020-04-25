//
// Created by Shaun Lee on 2020-04-22.
//

#ifndef P2_SENSOR_H
#define P2_SENSOR_H


class sensor {
public:
    double getdrainRate();
    sensor(double);
    void drain();
    bool isValid();
    void Recharge();
    double getBattery();
private:
    bool state;
    double battery;
    double drainRate;
    void checkBattery();
};


#endif //P2_SENSOR_H
