#include <iostream>
using namespace std;

void insertAtPosition(int arr[], int& size, int capacity, int position, int element) {
    // Check if array has space
    if (size >= capacity) {
        cout << "Array is full. Cannot insert more elements." << endl;
        return;
    }

    // Check if position is valid
    if (position < 0 || position > size) {
        cout << "Invalid position. Position should be between 0 and " << size << endl;
        return;
    }

    // Shift elements to the right to make space
    for (int i = size - 2; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[position] = element;

    // Increase the size
   // size++;
}

int main() {
    const int capacity = 100;  // Maximum array capacity
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

    // Get insertion details from user
    int position, element;
    cout << "\nEnter the position where you want to insert (0 to " << size << "): ";
    cin >> position;
    cout << "Enter the element to insert: ";
    cin >> element;

    // Perform insertion
    insertAtPosition(arr, size, capacity, position, element);

    // Display modified array
    cout << "\nArray after insertion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
