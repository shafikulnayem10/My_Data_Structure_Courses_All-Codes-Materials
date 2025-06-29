/*#include <iostream>
using namespace std;

// Bubble Sort for Task 1
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Binary Search for Task 1
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

// Print array for Task 1
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Task 1: Student Roll Numbers (Bubble Sort + Binary Search)
    int rollNumbers[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(rollNumbers) / sizeof(rollNumbers[0]);
    int targetRoll = 5;

    cout << "Task 1 - Student Roll Numbers:" << endl;
    cout << "Original list: ";
    printArray(rollNumbers, n);

    bubbleSort(rollNumbers, n);
    cout << "After bubble sort: ";
    printArray(rollNumbers, n);

    int result = binarySearch(rollNumbers, n, targetRoll);
    if (result != -1) {
        cout << "Roll number " << targetRoll << " found at index " << result << endl;
    } else {
        cout << "Roll number " << targetRoll << " not found" << endl;
    }

    return 0;
}


*/


/*
#include <iostream>
using namespace std;

// Insertion Sort for Task 2
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Binary Search for Task 2
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

// Print array for Task 2
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Task 2: Equipment Serial Numbers (Insertion Sort + Binary Search)
    int serialNumbers[] = {1045, 1021, 1056, 1012, 1033};
    int n = sizeof(serialNumbers) / sizeof(serialNumbers[0]);
    int targetSerial = 1033;

    cout << "Task 2 - Equipment Serial Numbers:" << endl;
    cout << "Original list: ";
    printArray(serialNumbers, n);

    insertionSort(serialNumbers, n);
    cout << "After insertion sort: ";
    printArray(serialNumbers, n);

    int result = binarySearch(serialNumbers, n, targetSerial);
    if (result != -1) {
        cout << "Serial number " << targetSerial << " found at index " << result << endl;
    } else {
        cout << "Serial number " << targetSerial << " not found" << endl;
    }

    return 0;
}
*/
/*
// binary search

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
*/

/*
//linear search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i; // Found at index i
    }
    return -1; // Not found
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    int result = linearSearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

*/

/*

//selection sort

#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
*/

/*

//bubble sort

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    // Outer loop for all passes
    for (int i = 0; i < size - 1; i++) {
        // Inner loop for pair-wise comparisons
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the elements are in the wrong order
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    bubbleSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
*/

/*


//insertion sort
*/
#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];      // Current element to be inserted
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Insert the key at correct position
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    insertionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
