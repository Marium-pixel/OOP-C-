#ifndef RUNNING_H
#define RUNNING_H

#include "Activity.h"

class Running : public Activity {
private:
    double distance; // in kilometers
    double time;     // in minutes

public:
    Running(double dist, double duration);
    double calculateCaloriesBurned() const override; // Implement the calculation for running
};

#endif
