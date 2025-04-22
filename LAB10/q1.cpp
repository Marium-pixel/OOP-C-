#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    float gpa;

    Student(int i = 0, string n = "", float g = 0.0f) : id(i), name(n), gpa(g) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }
};

class StudentManager {
private:
    string filename;

public:
    StudentManager(const string& file) : filename(file) {}

    void enterAndSaveStudents(int count) {
        ofstream outFile(filename, ios::out);
        if (!outFile) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        for (int i = 0; i < count; ++i) {
            Student s;
            cout << "Enter details for student " << (i + 1) << ":\n";
            cout << "ID: ";
            cin >> s.id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, s.name);
            cout << "GPA: ";
            cin >> s.gpa;

            outFile << s.id << " " << s.name << " " << s.gpa << endl;
        }

        outFile.close();
    }

    void appendStudent() {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            cerr << "Error opening file for appending." << endl;
            return;
        }

        Student s;
        cout << "\nEnter details for the new student to append:\n";
        cout << "ID: ";
        cin >> s.id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, s.name);
        cout << "GPA: ";
        cin >> s.gpa;

        outFile << s.id << " " << s.name << " " << s.gpa << endl;
        outFile.close();
    }

    void displayAllStudents() const {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        cout << "\nAll Student Records:\n";
        Student s;
        while (inFile >> s.id >> s.name >> s.gpa) {
            s.display();
        }

        inFile.close();
    }
};

int main() {
    StudentManager manager("students.txt");

    manager.enterAndSaveStudents(5);
    manager.appendStudent();
    manager.displayAllStudents();

    return 0;
}
