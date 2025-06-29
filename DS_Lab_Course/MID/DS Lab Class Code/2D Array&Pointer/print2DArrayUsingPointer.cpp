#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 3;
    int matrix[ROWS][COLS];


    cout << "Enter the elements of the 3x3 matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

cout << "\nThe matrix :" << endl;
int *ptr = &matrix[0][0];

for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
        cout << *ptr++ << "\t";
    }
    cout << endl;
}

    return 0;
}
