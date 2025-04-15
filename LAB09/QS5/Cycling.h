#ifndef CYCLING_H
#define CYCLING_H

#include "Activity.h"

class Cycling : public Activity {
private:
    double speed; // in km/h
    double time;  // in hours

public:
    Cycling(double spd, double duration);
    double calculateCaloriesBurned() const override; // Implement the calculation for cycling
};

#endif
