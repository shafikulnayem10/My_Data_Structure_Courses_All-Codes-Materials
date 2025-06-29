#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printQueue(queue<int> q) {
    cout << "[ ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "]" << endl;
}

void reverseFirstK(queue<int>& q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) return;

    stack<int> s;

    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }


    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }


    int remaining = q.size() - k;
    for (int i = 0; i < remaining; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {15, 25, 30, 45, 50, 70, 75, 80, 95, 100};
    int k = 4;


    for (int num : arr) {
        q.push(num);
    }


    cout << "Input Queue : ";
    printQueue(q);


    reverseFirstK(q, k);


    cout << "Output Queue: ";
    printQueue(q);

    return 0;
}


