#include "Running.h"
#include <iostream>

Running::Running(double dist, double duration) : distance(dist), time(duration) {}

double Running::calculateCaloriesBurned() const {
     
    double weight = 70.0;  
    return (0.1 * weight * time); // calories burned formula
}
