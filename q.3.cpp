 //You are required to write a C++ program that will creates a function named unique that will take arrayas input . the array may contains the duplicates values but you have to process on the array and have toreturn the array which must contains only unique values not duplicates.
#include <iostream>


using namespace std;


int* unique(int* arr, int size, int& newSize) {
    if (size == 0) {
        newSize = 0;
        return nullptr;
    }


    int* temp = new int[size]; // Temporary array to store unique values
    int count = 0;


    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;


        for (int j = 0; j < count; j++) {
            if (arr[i] == temp[j]) {
                isDuplicate = true;
                break;
            }
        }


        if (!isDuplicate) {
            temp[count++] = arr[i];
        }
    }


    int* uniqueArr = new int[count]; // Create an array with exact unique size
    for (int i = 0; i < count; i++) {
        uniqueArr[i] = temp[i];
    }


    delete[] temp; // Free temporary array
    newSize = count;
    return uniqueArr;
}


int main() {
    int size;
   
    cout << "Enter the size of the array: ";
    cin >> size;


    if (size <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }


    int* arr = new int[size]; // Dynamically allocate array


    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }


    int newSize;
    int* uniqueArr = unique(arr, size, newSize);


    cout << "Unique values: ";
    for (int i = 0; i < newSize; i++) {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;


    delete[] arr;      // Free original array
    delete[] uniqueArr; // Free unique array


    return 0;
}





