#include <iostream>

using namespace std;
 
int** allocateMatrix(int rows, int cols);
void fillMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
int sumElements(int** matrix, int rows, int cols);
void rowAndColSums(int** matrix, int rows, int cols, int* rowSums, int* colSums);
void highestRowAndCol(int* rowSums, int* colSums, int rows, int cols, int& highestRow, int& highestCol);
int** transposeMatrix(int** matrix, int rows, int cols);
void freeMatrix(int** matrix, int rows);
unsigned int customRandom();

static unsigned int seed = 1;

int main() {
    int rows, cols;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    if (rows <= 0 || cols <= 0) {
        cout << "Invalid matrix dimensions!" << endl;
        return 1;
    }
    
    int** matrix = allocateMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);
    
    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);
    
    int totalSum = sumElements(matrix, rows, cols);
    cout << "\nSum of all elements: " << totalSum << endl;
    
    int* rowSums = new int[rows];
    int* colSums = new int[cols];
    rowAndColSums(matrix, rows, cols, rowSums, colSums);
    
    cout << "Row sums: ";
    for (int i = 0; i < rows; i++) cout << rowSums[i] << (i < rows - 1 ? ", " : "\n");
    
    cout << "Column sums: ";
    for (int i = 0; i < cols; i++) cout << colSums[i] << (i < cols - 1 ? ", " : "\n");
    
    int highestRow, highestCol;
    highestRowAndCol(rowSums, colSums, rows, cols, highestRow, highestCol);
    cout << "Row with highest sum: Row " << highestRow + 1 << endl;
    cout << "Column with highest sum: Column " << highestCol + 1 << endl;
    
    int** transposed = transposeMatrix(matrix, rows, cols);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);
    
    freeMatrix(matrix, rows);
    freeMatrix(transposed, cols);
    delete[] rowSums;
    delete[] colSums;
    
    return 0;
}

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

unsigned int customRandom() {
    seed = (seed * 1103515245 + 12345) % 2147483648;
    return (seed % 100) + 1;
}

void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = customRandom();
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << "[ ";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int sumElements(int** matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void rowAndColSums(int** matrix, int rows, int cols, int* rowSums, int* colSums) {
    for (int i = 0; i < rows; i++) rowSums[i] = 0;
    for (int i = 0; i < cols; i++) colSums[i] = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSums[i] += matrix[i][j];
            colSums[j] += matrix[i][j];
        }
    }
}

void highestRowAndCol(int* rowSums, int* colSums, int rows, int cols, int& highestRow, int& highestCol) {
    highestRow = 0;
    highestCol = 0;
    for (int i = 1; i < rows; i++) {
        if (rowSums[i] > rowSums[highestRow]) highestRow = i;
    }
    for (int i = 1; i < cols; i++) {
        if (colSums[i] > colSums[highestCol]) highestCol = i;
    }
}

int** transposeMatrix(int** matrix, int rows, int cols) {
    int** transposed = allocateMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
