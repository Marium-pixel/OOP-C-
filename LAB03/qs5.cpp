/*Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that stores information about the current year. The user is allowed to store their tasks to do against each day. Assume only one entry is needed per day.
Create the following methods for your class:  Add a task. Thisfunction accepts three parameters: task details, date and month. It should add a task on the day specified.  Remove a task. Accepts the date and month as a parameter to remove the task from.  Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how you’ll remove a task, and display the updated task list.*/

#include <iostream>
#include <string>
using namespace std;

class Calendar {
private:
    static const int MONTHS = 12;
    static const int DAYS = 31;  
    string tasks[MONTHS][DAYS];  
    int year;

public: 
    Calendar(int y) : year(y) { 
        for (int month = 0; month < MONTHS; ++month) {
            for (int day = 0; day < DAYS; ++day) {
                tasks[month][day] = "";
            }
        }
    }
 
    void addTask(const string& task, int day, int month) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid date! Please enter a valid date (1-31) and month (1-12)." << endl;
            return;
        }
        tasks[month - 1][day - 1] = task;  
        cout << "Task added successfully!" << endl;
    }
 
    void removeTask(int day, int month) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid date! Please enter a valid date (1-31) and month (1-12)." << endl;
            return;
        }
        if (tasks[month - 1][day - 1].empty()) {
            cout << "No task found on this date!" << endl;
        } else {
            tasks[month - 1][day - 1] = "";  
            cout << "Task removed successfully!" << endl;
        }
    }
 
    void showTasks() const {
        cout << "Tasks for the year " << year << ":" << endl;
        for (int month = 0; month < MONTHS; ++month) {
            for (int day = 0; day < DAYS; ++day) {
                if (!tasks[month][day].empty()) {
                    cout << "Month " << (month + 1) << ", Day " << (day + 1) << ": " << tasks[month][day] << endl;
                }
            }
        }
    }
};

int main() { 
    Calendar myCalendar(2023);
 
    myCalendar.addTask("Buy milk", 5, 3);   
    myCalendar.addTask("Eye doctor appointment", 21, 5);  
    myCalendar.addTask("Submit project report analysis", 15, 6);  
    myCalendar.addTask("leave for vacation", 20, 8);   
    myCalendar.addTask(" Family wedding", 25, 9);  
    myCalendar.addTask("Pay end of year taxes", 30, 12);     
 
    cout << "Initial tasks:" << endl;
    myCalendar.showTasks();
 
    int removeDay, removeMonth;
    cout << "\nEnter the date (day and month) to remove a task:" << endl;
    cout << "Day: ";
    cin >> removeDay;
    cout << "Month: ";
    cin >> removeMonth;
 
    myCalendar.removeTask(removeDay, removeMonth);
 
    cout << "\nUpdated tasks:" << endl;
    myCalendar.showTasks();

    return 0;
}
