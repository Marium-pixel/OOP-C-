#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string n, string addr, string phone, string mail) {
        name = n;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }
};

class Student : public Person {
private:
    string coursesEnrolled[5];
    int courseCount;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string mail, double gpa, int year)
        : Person(n, i, addr, phone, mail), GPA(gpa), enrollmentYear(year), courseCount(0) {}

    void enrollCourse(const string& course) {
        if (courseCount < 5) {
            coursesEnrolled[courseCount] = course;
            courseCount++;
        }
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "Courses Enrolled: ";
        for (int i = 0; i < courseCount; i++) {
            cout << coursesEnrolled[i] << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    string coursesTaught[5];
    int courseCount;
    double salary;

public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, double sal)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal), courseCount(0) {}

    void addCourse(const string& course) {
        if (courseCount < 5) {
            coursesTaught[courseCount] = course;
            courseCount++;
        }
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << "Courses Taught: ";
        for (int i = 0; i < courseCount; i++) {
            cout << coursesTaught[i] << " ";
        }
        cout << endl;
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    Professor* instructor;
    Student* enrolledStudents[30];
    int studentCount;

public:
    Course(string id, string name, int credit, Professor* prof)
        : courseId(id), courseName(name), credits(credit), instructor(prof), studentCount(0) {}

    void registerStudent(Student* student) {
        if (studentCount < 30) {
            enrolledStudents[studentCount] = student;
            student->enrollCourse(courseName);
            studentCount++;
        }
    }

    void calculateGrades() {
        cout << "Calculating grades for " << courseName << endl;
    }
};

int main() {
    Student student(" Ali", "S123", "123 Johar", "03337878292", "Ali@gmail.com", 3.5, 2020);
    Professor professor("Dr. Asrar", "P456", "456 Johar St", "0300828282", "Asrarahmer@gmail.com", "Computer Science", 75000);
    Staff staff("Mona", "ST789", "789 Gulshan", "03332118282", "mona@gmail.com", "Administration", "Registrar", 50000);

    student.displayInfo();
    cout << endl;
    professor.displayInfo();
    cout << endl;
    staff.displayInfo();
    cout << endl;

    Course course("CS101", "OOP", 3, &professor);
    course.registerStudent(&student);
    course.calculateGrades();

    return 0;
}
