#include <iostream>
#include "Running.h"
#include "Cycling.h"

using namespace std;

int main() {
    // Create Running and Cycling objects
    Running runningActivity(5.0, 30.0);  // 5 km in 30 minutes
    Cycling cyclingActivity(20.0, 1.0);  // 20 km/h for 1 hour

    // Display calories burned for each activity
    cout << "Calories burned during running: " << runningActivity.calculateCaloriesBurned() << " kcal" << endl;
    cout << "Calories burned during cycling: " << cyclingActivity.calculateCaloriesBurned() << " kcal" << endl;

    return 0;
}
// command to run g++ -o fitnessapp main.cpp Cycling.cpp Running.cpp,./fitnessapp
