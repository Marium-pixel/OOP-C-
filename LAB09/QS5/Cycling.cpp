#include "Cycling.h"
#include <iostream>

Cycling::Cycling(double spd, double duration) : speed(spd), time(duration) {}

double Cycling::calculateCaloriesBurned() const {
    
    return 8.0 * time * 60;  
}
