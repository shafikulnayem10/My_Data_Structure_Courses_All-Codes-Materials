#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int D[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> D[i];
    }

    for (int k = 0; k < n - 1; k++) {
        int s = 0;
        while (s < n - k - 1) {
            if (D[s] > D[s + 1]) {
                // Swap elements
                int temp = D[s];
                D[s] = D[s + 1];
                D[s + 1] = temp;
            }
            s++;
        }
    }

    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << D[i] << " ";
    }
    cout << endl;

    return 0;
}

