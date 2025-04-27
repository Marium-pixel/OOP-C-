#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SearchAndReplace {
private:
    string filename;

public:
    SearchAndReplace(const string& fname) : filename(fname) {}

    void createFile() {
        ofstream outFile(filename, ios::out);
        if (outFile) {
            outFile << "AI is the future. AI will transform the world. Embrace AI now.";
            outFile.close();
        } else {
            cerr << "Error creating file!" << endl;
        }
    }

    void searchAndReplace() {
        string searchWord, replacementWord;
        cout << "Enter search word: ";
        cin >> searchWord;
        cout << "Enter replacement word: ";
        cin >> replacementWord;

        if (replacementWord.length() > searchWord.length()) {
            cout << "Replacement word is longer than search word. Aborting." << endl;
            return;
        }

        fstream file(filename, ios::in | ios::out);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }

        string word;
        streampos pos;
        char ch;
        while (file.get(ch)) {
            if (ch == searchWord[0]) {
                pos = file.tellg();
                pos--;
                string temp;
                temp += ch;
                for (size_t i = 1; i < searchWord.length(); i++) {
                    if (file.get(ch))
                        temp += ch;
                    else
                        break;
                }
                if (temp == searchWord) {
                    file.seekp(pos);
                    file << replacementWord;
                    for (size_t i = replacementWord.length(); i < searchWord.length(); i++) {
                        file << ' ';
                    }
                    file.seekg(pos + streamoff(searchWord.length()));
                } else {
                    file.seekg(pos + streamoff(1));
                }
            }
        }
        file.close();
    }

    void displayFile() {
        ifstream inFile(filename);
        if (inFile) {
            string line;
            getline(inFile, line);
            cout << "Updated file content: " << line << endl;
            inFile.close();
        } else {
            cerr << "Error reading file!" << endl;
        }
    }
};

int main() {
    SearchAndReplace tool("data.txt");

    tool.createFile();
    tool.searchAndReplace();
    tool.displayFile();

    return 0;
}
