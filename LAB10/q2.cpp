#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Resume {
private:
    string name;
    string email;
    int yearsOfExperience;
    string summary;
    string filename;

public:
    Resume(const string& file) : filename(file) {}

    void inputData() {
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your email: ";
        getline(cin, email);
        cout << "Enter your years of experience: ";
        cin >> yearsOfExperience;
        cin.ignore();
        cout << "Enter your professional summary: ";
        getline(cin, summary);
    }

    void writeToFile() {
        ofstream outFile(filename, ios::trunc);
        if (!outFile) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        outFile << "Name: " << name << endl;
        outFile << "Email: " << email << endl;
        outFile << "Years of Experience: " << yearsOfExperience << endl;
        outFile << "Summary: " << summary << endl;

        outFile.close();
    }

    void displayFromFile() const {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        cout << "\n--- Resume Content ---\n";
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();
    }
};

int main() {
    Resume resume("resume.txt");

    resume.inputData();
    resume.writeToFile();
    resume.displayFromFile();

    return 0;
}
