#include <iostream>
using namespace std;

void selectionSortAsc(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) < *(arr + minIdx)) {
                minIdx = j;
            }
        }
        int temp = *(arr + i);
        *(arr + i) = *(arr + minIdx);
        *(arr + minIdx) = temp;
    }
}

void selectionSortDesc(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) > *(arr + maxIdx)) {
                maxIdx = j;
            }
        }
        int temp = *(arr + i);
        *(arr + i) = *(arr + maxIdx);
        *(arr + maxIdx) = temp;
    }
}

void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {23, 70, 40, 42, 65, 99, 101, 20, 19, 84, 79};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSortAsc(arr, n);
    cout << "Array in Ascending Order: ";
    printArr(arr, n);

    selectionSortDesc(arr, n);
    cout << "Array in Descending Order: ";
    printArr(arr, n);

    return 0;
}
