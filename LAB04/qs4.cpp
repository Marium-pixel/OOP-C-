 /*You are building a car rental system. Create a class `Car` to manage cars available for rent.
 Requirements:
1. Attributes:
 `carID` (int)
 `model` (string)
 `year` (int)
 `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `rentCar()`: Marks the car as rented.
 `returnCar()`: Marks the car as available.
 `isVintage()`: Returns `true` if the car's year is before 2000.
5. Create a few `Car` objects and test the methods.
*/

#include <iostream>
using namespace std;

class Car {
private:
    int carID;
    string model;
    int year;
    bool isRented;


public:
    Car() {
        isRented = false;
    }

    // Parameterized constructor
    Car(int id, string m, int y) {
        carID = id;
        model = m;
        year = y;
        isRented = false;
    }

    void rentCar(){
        if(!isRented){
            isRented=true;
          cout << "Car " << model << " has been rented.\n";
        } else {
            cout << "Car " << model << " is already rented.\n";
        }
    }

    void returnCar(){
        if(isRented){
            isRented=false;
            cout<<"Car"<<model<<"has been retyrned";
        } else {
            cout<<"car"<<model<<"has nopt been rented";
        }
    }

    bool isVintage() {
        return year < 2000;
    }


      
    void displayDetails() {
        cout << "Car ID: " << carID << ", Model: " << model << ", Year: " << year;
        cout << ", Status: " << (isRented ? "Rented" : "Available") << "\n";
    }

};

int main() {
    Car  c1(101,"Honda",2013);
    Car c2(102,"Mustang",1999);
    Car c3(103,"Lamborghini",2010);
    
    c1.displayDetails();
    c2.displayDetails();
    c3.displayDetails();

    cout << "\nRenting car 101...\n";
    c1.rentCar();
    c1.displayDetails();

    cout << "\nReturning car 101...\n";
    c1.returnCar();
    c1.displayDetails();

    cout << "\nChecking if cars are vintage:\n";
    cout << "Car 101 is " << (c1.isVintage() ? "Vintage" : "Not Vintage") << "\n";
    cout << "Car 102 is " << (c2.isVintage() ? "Vintage" : "Not Vintage") << "\n";
    cout << "Car 103 is " << (c3.isVintage() ? "Vintage" : "Not Vintage") << "\n";
    return 0;
}
