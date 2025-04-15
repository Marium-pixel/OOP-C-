#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string model;
    double rate;

public:
    Vehicle(const string& modelName, double dailyRate)
        : model(modelName), rate(dailyRate) {}

    virtual double getDailyRate() const = 0;
    virtual void displayDetails() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(const string& modelName, double dailyRate)
        : Vehicle(modelName, dailyRate) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Car Model: " << model << ", Daily Rate: $" << getDailyRate() << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(const string& modelName, double dailyRate)
        : Vehicle(modelName, dailyRate) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Bike Model: " << model << ", Daily Rate: $" << getDailyRate() << endl;
    }
};

class Scooter : public Vehicle {
public:
    Scooter(const string& modelName, double dailyRate)
        : Vehicle(modelName, dailyRate) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Scooter Model: " << model << ", Daily Rate: $" << getDailyRate() << endl;
    }
};

int main() {
    const int vehicleCount = 3;
    Vehicle* vehicles[vehicleCount];

    vehicles[0] = new Car("Toyota Corolla", 45.99);   
    vehicles[1] = new Bike("mercedez benz", 19.99);    
    vehicles[2] = new Scooter("bike 2 seater", 24.50);   

    cout << "Available Vehicles for Rent:\n";
    for (int i = 0; i < vehicleCount; ++i) {
        vehicles[i]->displayDetails();
    }

    for (int i = 0; i < vehicleCount; ++i) {
        delete vehicles[i];
    }

    return 0;
}
