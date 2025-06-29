#include <iostream>
using namespace std;

// Max heapify
void MaxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

// Min heapify
void MinHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        MinHeapify(arr, n, smallest);
    }
}

// Max Heap Sort (Descending order)
void MaxHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0); // Reduce heap size
    }
}

// Min Heap Sort (Ascending order)
void MinHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        MinHeapify(arr, i, 0); // Reduce heap size
    }
}

int main() {
    int arr[] = {4, 6, 10, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Make a copy before sorting
    int arrCopy1[100], arrCopy2[100];
    for (int i = 0; i < n; i++) {
        arrCopy1[i] = arr[i];
        arrCopy2[i] = arr[i];
    }

    MinHeapSort(arrCopy1, n);
    cout << "Sorted Min Heap (Largest to smallest): ";
    for (int i = 0; i < n; i++) {
        cout << arrCopy1[i] << " ";
    }
    cout << endl;

    MaxHeapSort(arrCopy2, n);
    cout << "Sorted Max Heap (Smallest to Largest): ";
    for (int i = 0; i < n; i++) {
        cout << arrCopy2[i] << " ";
    }
    cout << endl;
}
