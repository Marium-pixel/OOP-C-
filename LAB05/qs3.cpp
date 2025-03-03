#include<iostream>
using namespace std;

class ValidateString {
private:
    string inputString;

public: 
    ValidateString(string s) {
        inputString = s;
    }

    // Constant function to check if the string contains only alphabets
    // The function is constant because we do not modify the object's state
    bool isValid() const {
        for (char c : inputString) {
            // If a character is not an alphabet (either uppercase or lowercase), return false
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;  // All characters are alphabetic, so return true
    }
};

int main() { 
    ValidateString str1("HelloWorld");
    ValidateString str2("lolol123");
    ValidateString str3("jhwhfwh@#$%!");
     
    cout << "Is 'HelloWorld' valid? " << (str1.isValid() ? "Yes" : "No") << endl;
    cout << "Is 'lolol123' valid? " << (str2.isValid() ? "Yes" : "No") << endl;
    cout << "Is 'jhwhfwh@#$%!' valid? " << (str3.isValid() ? "Yes" : "No") << endl;

    return 0;
}
