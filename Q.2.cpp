#include <iostream>
#include <cstring>

using namespace std;
 
int countVowels(const char* str) {
    int vowelCount = 0;
    while (*str) {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
        str++;
    }
    return vowelCount;
}
 
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int n;
  
    cout << "Enter the number of strings: ";
    cin >> n;
 
    char** arr = new char*[n];
 
    cin.ignore();  
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        char buffer[100];
        cin.getline(buffer, 100);
        arr[i] = new char[strlen(buffer) + 1];
        strcpy(arr[i], buffer);
    }
 
    cout << "\nStrings with reversed letters in reverse order:\n";
    for (int i = n - 1; i >= 0; i--) {
        reverseString(arr[i]);  
        cout << *(arr + i) << endl;
    }
 
    int maxVowels = -1;
    char* stringWithMostVowels = nullptr;

    for (int i = 0; i < n; i++) {
        int vowelCount = countVowels(arr[i]);
        if (vowelCount > maxVowels) {
            maxVowels = vowelCount;
            stringWithMostVowels = arr[i];
        }
    }

    cout << "\nString with the most vowels: " << stringWithMostVowels << endl;
 
    int totalLength = 0;
    for (int i = 0; i < n; i++) {
        totalLength += strlen(arr[i]);
    }
    double averageLength = static_cast<double>(totalLength) / n;
    cout << "Average length of strings: " << averageLength << endl;
 
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

