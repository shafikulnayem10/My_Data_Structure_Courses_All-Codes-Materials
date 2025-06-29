#include <iostream>
using namespace std;

void deleteFromPosition(int arr[], int& size, int position) {
    // Check if array is empty
    if (size <= 0) {
        cout << "Array is empty. Nothing to delete." << endl;
        return;
    }

    // Check if position is valid
    if (position < 0 || position >= size) {
        cout << "Invalid position. Position should be between 0 and " << size-1 << endl;
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < size ; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size
    //size--;
}

int main() {
    const int capacity = 100;
    int arr[capacity];
    int size;

    // Get array size from user
    cout << "Enter the number of elements in array (max " << capacity << "): ";
    cin >> size;

    // Validate size input
    if (size <= 0 || size > capacity) {
        cout << "Invalid size. Size should be between 1 and " << capacity << endl;
        return 1;
    }

    // Get array elements from user
    cout << "Enter " << size << " elements separated by spaces: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Display original array
    cout << "\nOriginal array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Get deletion position from user
    int position;
    cout << "\nEnter the position to delete (0 to " << size-1 << "): ";
    cin >> position;

    // Perform deletion
    deleteFromPosition(arr, size, position);

    // Display modified array
    cout << "\nArray after deletion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
