#include<iostream>
using namespace std;

class Square {
private:
    float sideLength;
    float area;
    static float allareas;

public: 
    Square(float sL) {
        sideLength = sL;
        area = 0.0;
    }
 
    float getsideLength() const {
        return sideLength;
    }
 
    float getarea() const {
        return area;
    }
 
    static float getallareas() {
        return allareas;
    }
 
    void calc_area() {
        area = sideLength * sideLength;
        allareas += area;   
    }
};
 
float Square::allareas = 0.0;

int main() { 
    Square s1(4.0);
    Square s2(12.2);
    Square s3(10.0);
 
    s1.calc_area();
    cout << "Square 1 - Side Length: " << s1.getsideLength() << ", Area: " << s1.getarea() 
         << ", Total Area of All Squares: " << Square::getallareas() << endl;

    s2.calc_area();
    cout << "Square 2 - Side Length: " << s2.getsideLength() << ", Area: " << s2.getarea() 
         << ", Total Area of All Squares: " << Square::getallareas() << endl;

    s3.calc_area();
    cout << "Square 3 - Side Length: " << s3.getsideLength() << ", Area: " << s3.getarea() 
         << ", Total Area of All Squares: " << Square::getallareas() << endl;

    return 0;
}
