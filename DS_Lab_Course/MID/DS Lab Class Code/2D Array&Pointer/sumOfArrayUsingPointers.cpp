#include <iostream>
using namespace std;


const int MAX_SIZE = 100;

int main() {
    int arr[MAX_SIZE];
    int size;


    cout << "Enter the size of the array (max " << MAX_SIZE << "): ";
    cin >> size;


    if (size <= 0 || size > MAX_SIZE) {
        cout << "Invalid array size. Please enter a value between 1 and " << MAX_SIZE << "." << endl;
        return 1;
    }


    cout << "Enter " << size << " integer elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int sum = 0;
   int *ptr = arr;
    for (int i = 0; i < size; i++) {
    sum += *ptr++;
}


    cout << "The sum of array elements is: " << sum << endl;

    return 0;
}
