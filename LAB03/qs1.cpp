//Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor should initialize this data to 0, and another should initialize it to fixed values. Another member function should display it, in 11:59:59 format. The final member function should add two objects of type time passed as arguments.
//A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized. Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should display the value of this third variable. Make appropriate member functions const.



#include<iostream>
using namespace std;

class Time{
    int hours;
    int minutes;
    int seconds;
    public:
    Time(int h,int m,int s){
        this->hours=h;
        this->minutes=m;
        this->seconds=s;
    }
    Time(){
        hours=0;
        minutes=0;
        seconds=0;
    }
    
    void display()const {
         cout << (hours < 10 ? "0" : "") << hours << ":"
              << (minutes < 10 ? "0" : "") << minutes << ":"
              << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    Time add(const Time& other) const {
        //converting to seconds
        int total_seconds = (hours * 3600 +minutes*60 + seconds) + (other.hours * 3600 + other.minutes*60 + other.seconds);
    //convert seconds back to std time
    int newH=(total_seconds/3600)%24;
    int newm=(total_seconds/3600)%60;
    int news=(total_seconds%60);

    return Time(newH,newm,news);
    
    }
};

int main(){ 
    const Time t1(11,59,59);
    const Time t2(1, 30, 15);

    Time t3;
    t3=t1.add(t2);

    cout<<"Time 1: ";
    t1.display();
    cout<<"Time 2:";
    t2.display();
    cout<<"Time 3:";
    t3.display();

    return 0;
}
