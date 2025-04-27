#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FilePointerDemo {
private:
    string filename;

public:
    FilePointerDemo(const string& fname) : filename(fname) {}

    void writeToFile() {
        ofstream outFile(filename, ios::out);
        if (outFile) {
            outFile << "C++ is a powerful programming language.";
            outFile.close();
        } else {
            cerr << "Error opening file for writing!" << endl;
        }
    }

    void readWriteFile() {
        fstream file(filename, ios::in | ios::out);
        if (!file) {
            cerr << "Error opening file for read/write!" << endl;
            return;
        }

        cout << "Initial get pointer position: " << file.tellg() << endl;
        cout << "Initial put pointer position: " << file.tellp() << endl;

        file.seekg(6);
        string word;
        file >> word;
        cout << "Word read from position 6: " << word << endl;

        file.seekp(6);
        file << "dynamic";

        cout << "New get pointer position: " << file.tellg() << endl;
        cout << "New put pointer position: " << file.tellp() << endl;

        file.close();
    }

    void displayUpdatedContent() {
        ifstream inFile(filename);
        if (inFile) {
            string line;
            getline(inFile, line);
            cout << "Updated file content: " << line << endl;
            inFile.close();
        } else {
            cerr << "Error opening file to display content!" << endl;
        }
    }
};

int main() {
    FilePointerDemo demo("info.txt");

    demo.writeToFile();
    demo.readWriteFile();
    demo.displayUpdatedContent();

    return 0;
}
