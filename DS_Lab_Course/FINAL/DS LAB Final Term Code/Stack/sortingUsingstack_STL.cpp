#include <iostream>
#include <stack>
using namespace std;


void sortStack(stack<int>& original) {
    stack<int> tempStack;

    while (!original.empty()) {
        int temp = original.top();
        original.pop();


        while (!tempStack.empty() && tempStack.top() < temp) {
            original.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }


    while (!tempStack.empty()) {
        original.push(tempStack.top());
        tempStack.pop();
    }
}


void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}


int main() {
    stack<int> myStack;


    myStack.push(1);
    myStack.push(5);
    myStack.push(5);
    myStack.push(2);
    myStack.push(3);
    myStack.push(8);

    cout << "Original stack (top to bottom): ";
    printStack(myStack);

    // Sort the stack
    sortStack(myStack);

    cout << "Sorted stack (descending order, top to bottom): ";
    printStack(myStack);

    return 0;
}
