//You are required to write a c++ function swap_string that shifts the last n characters of a string to thefront n times. It will take str and int as parameters. And will return the new string after shifting.Note: You have to work with pointers
#include <iostream>
#include <cstring>


using namespace std;


char* swap_string(char* str, int n) {
    int len = strlen(str);
   
    if (n <= 0 || n >= len) {
        return str;  
    }


    char* newStr = new char[len + 1];  
     
    for (int i = 0; i < n; i++) {
        newStr[i] = str[len - n + i];
    }
 
    for (int i = 0; i < len - n; i++) {
        newStr[n + i] = str[i];
    }


    newStr[len] = '\0';


    return newStr;
}


int main() {
    char str[100];
    int n;


    cout << "Enter a string: ";
    cin.getline(str, 100);


    cout << "Enter the number of shifts: ";
    cin >> n;


    char* shiftedStr = swap_string(str, n);


    cout << "Shifted String: " << shiftedStr << endl;


    delete[] shiftedStr;  


    return 0;
}

