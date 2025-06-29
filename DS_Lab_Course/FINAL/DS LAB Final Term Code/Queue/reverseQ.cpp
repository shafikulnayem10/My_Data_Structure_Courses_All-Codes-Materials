#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Function to reverse a queue using a stack
queue<int> rev(queue<int> q) {
    stack<int> s;

    // Push all elements from the queue into the stack
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // Pop all elements from the stack back into the queue
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    return q;
}

int main() {
    queue<int> q;

    // Inserting elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reversing the queue
    q = rev(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

