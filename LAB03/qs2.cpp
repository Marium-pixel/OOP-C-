// Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of these to 0. A member function called payingCar() increments the car total and adds 0.50 to the cash total. Another function,called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a member function called display() displays the two totals. Make appropriate member functions const.
//Include a program to test this class. This program should allow the user to push one key to count a paying car, and another to count a nonpaying car. Pushing the Esc key should cause the program to print out the total cars and total cash and then exit.
//Note: _getch() (from <conio.h>) reads a key press instantly without requiring Enter.
#include <iostream>
#include <conio.h>  // For getch() to capture key presses (Windows-specific)

using namespace std;

class tollBooth {
private:
    unsigned int carCount;    
    double cashTotal;        

public:
    // Constructor  
    tollBooth() : carCount(0), cashTotal(0.0) {}
 
    void payingCar() {
        carCount++;
        cashTotal += 0.50;   
    }
 
    void nopayCar() {
        carCount++;
         
    }
 
    void display() const {
        cout << "Total Cars: " << carCount << endl;
        cout << "Total Cash: $" << cashTotal << endl;
    }
};

int main() {
    tollBooth booth;   
    char key;

    cout << "Press 'P' for a paying car, 'N' for a non-paying car, 'Esc' to quit and show totals." << endl;

    while (true) {
        key = _getch();   

        if (key == 27) {  // 27 is the ASCII value for the 'Esc' key
            booth.display();   
            break;   
        } else if (key == 'P' || key == 'p') {
            booth.payingCar();   
        } else if (key == 'N' || key == 'n') {
            booth.nopayCar();  //  
        }
    }

    return 0;
}
