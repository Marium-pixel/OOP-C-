/* write a class that represents a car, and useaggregation and
composition to combine different components like engine, wheels, headlights and steering to create the
car object.

Hint: create the individual classes firstbeforeperforming the composition. Remember
thatfor aggregation, you will need pointers! You’ll be needing constructors and setters to
set these values in case of aggregation. Same hint applies to other questions.*/

#include <iostream>
using namespace std;

class Engine { //composition
private:
    int horsepower;
public:
    Engine(int hp) { this->horsepower = hp; }

    void display() {
        cout << "Total horsepower: " << horsepower << " HP\n";
    }
};

class Wheels { //composition
private:
    int wheelsize;
public:
    Wheels(int wsize) { this->wheelsize = wsize; }

    void display() {
        cout << "Wheel size: " << wheelsize << " inches\n";
    }
};

class Headlights { //composition
private:
    string type;
public:
    Headlights(string t) { this->type = t; }

    void display() {
        cout << "Type of Headlight: " << type << endl;
    }
};

class Steering { //aggregation
private:
    string type;
public:
    Steering(string t) { this->type = t; }

    void display() {
        cout << "Type of Steering: " << type << endl;
    }
};

class Car {
private:
    Engine engine;
    Wheels wheels;
    Headlights headlights;
    Steering* steering;

public:
    Car(int hp, int wheelsize, string headlightType, Steering* steer)
        : engine(hp), wheels(wheelsize), headlights(headlightType), steering(steer) {}

    void display() {
        cout << "Car Details:\n";
        engine.display();
        wheels.display();
        headlights.display();
        steering->display();
        cout << "-----------------------\n";
    }
};

int main() {
    Steering* sportySteering = new Steering("Sporty");

    Car car1(200, 18, "LED", sportySteering);
    car1.display();

    Car car2(150, 16, "Halogen", sportySteering);
    car2.display();

    delete sportySteering;

    return 0;
}
