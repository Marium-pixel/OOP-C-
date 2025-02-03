#include <iostream>
#include <string>

using namespace std;
 
struct Register {
    int courseId;
    string courseName;
};
 
struct Student : public Register {
    int studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
};

int main() {
    const int numStudents = 5;
     
    Student students[numStudents];
 
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter information for student " << i + 1 << ":\n";
 
        cout << "Course ID: ";
        cin >> students[i].courseId;
        cin.ignore();  
        cout << "Course Name: ";
        getline(cin, students[i].courseName); 
        cout << "Student ID: ";
        cin >> students[i].studentId;
        cin.ignore();   
        cout << "First Name: ";
        getline(cin, students[i].firstName); 
        cout << "Last Name: ";
        getline(cin, students[i].lastName); 
        cout << "Cell Number: ";
        getline(cin, students[i].cellNo);  
        cout << "Email: ";
        getline(cin, students[i].email);  

        cout << "\n";   
    }
 
    cout << "Student Registration Information:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << " Information:\n";
        cout << "Course ID: " << students[i].courseId << endl;
        cout << "Course Name: " << students[i].courseName << endl;
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "Name: " << students[i].firstName << " " << students[i].lastName << endl;
        cout << "Cell Number: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;
    }

    return 0;
}

