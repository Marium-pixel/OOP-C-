 #include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
 
    float *array = new float[n];
 
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
 
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }  
    float avg = sum / n;
 
    float closest = array[0];
    float min_diff = 0;
     
    float diff = array[0] - avg;
    if (diff < 0) {
        min_diff = -diff;   
    } else {
        min_diff = diff;
    }
 
    for (int i = 1; i < n; i++) {
        diff = array[i] - avg;
        float current_diff;
        if (diff < 0) {
            current_diff = -diff;   
        } else {
            current_diff = diff;
        }

        if (current_diff < min_diff) {
            min_diff = current_diff;
            closest = array[i];
        }
    }
 
    cout << "The average is: " << avg << endl;
    cout << "The number closest to the average is: " << closest << endl;
 
    delete[] array;

    return 0;
}

