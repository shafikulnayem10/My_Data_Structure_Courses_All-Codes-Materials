#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Copy elements of first array
    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    // Copy elements of second array
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {

    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int mergedSize = size1 + size2;
    int merged[mergedSize];


    // Merge arrays
    mergeArrays(arr1, size1, arr2, size2, merged);

    // Print merged array
    cout << "Merged Array: ";
    for (int i = 0; i < mergedSize; i++) {
        cout << merged[i] << " ";
    }

    return 0;
}
