#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

int main() {
    stack<int> s;
    int n, x, minVal = INT_MAX;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter stack elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.push(x);
        if (x < minVal) minVal = x;
    }

    cout << "Minimum Element: " << minVal << endl;
    return 0;
}

