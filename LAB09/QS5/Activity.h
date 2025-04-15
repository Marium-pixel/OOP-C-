#ifndef ACTIVITY_H
#define ACTIVITY_H

class Activity {
public:
    virtual double calculateCaloriesBurned() const = 0; // Pure virtual function
    virtual ~Activity() {} // Make the destructor public so it can be called in derived classes
};

#endif
