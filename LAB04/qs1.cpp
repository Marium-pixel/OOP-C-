 /*You are building a student management system. Create a class `Student` to manage student records.
 Requirements:
1. Attributes:
 `studentID` (int)
 `name` (string)
 `age` (int)
 `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
 `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
 `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods.*/


#include<iostream>
using namespace std;

class Student{
private:
    int studentID;
    string name;
    int age;
    char grade;
public: 
    Student(int studentID, string name, int age, char grade) {
        this->studentID = studentID;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }
 
    Student() {
        grade = 'N';
    }
 
   void promoteStudent() {
        if (grade > 'A' && grade <= 'D') {
            grade--;
            cout << name << " has been promoted to grade " << grade << "\n";
        } else {
            cout << name << " cannot be promoted further.\n";
        }
    }
 
    void isEligibleForScholarship() {
        cout << "Checking for scholarship... ";
        if (grade == 'A') {
            cout << "Eligible" << endl;
        } else {
            cout << "Not Eligible" << endl;
        }
    }
 
    void displayDetails() {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

 int main(){
    Student s1(1011,"Mary",15,'B');
    
    Student s2(1231,"Sus",18,'A');
    
    Student s3(4567,"Kim",16,'C');

     while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Promote a student\n";
        cout << "2. Check scholarship eligibility\n";
        cout << "3. Display all student details\n";
        cout << "4. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 4) break;

        int stuChoice;
        switch (choice) {
            case 1:
                cout << "Enter student number (1 for Mary, 2 for Sus, 3 for Kim): ";
                cin >> stuChoice;
                if (stuChoice == 1) s1.promoteStudent();
                else if (stuChoice == 2) s2.promoteStudent();
                else if (stuChoice == 3) s3.promoteStudent();
                else cout << "Invalid choice!" << endl;
                break;
            case 2:
                cout << "Enter student number (1 for Mary, 2 for Sus, 3 for Kim): ";
                cin >> stuChoice;
                if (stuChoice == 1) s1.isEligibleForScholarship();
                else if (stuChoice == 2) s2.isEligibleForScholarship();
                else if (stuChoice == 3) s3.isEligibleForScholarship();
                else cout << "Invalid choice!" << endl;
                break;
            case 3:
                s1.displayDetails();
                s2.displayDetails();
                s3.displayDetails();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
 }
