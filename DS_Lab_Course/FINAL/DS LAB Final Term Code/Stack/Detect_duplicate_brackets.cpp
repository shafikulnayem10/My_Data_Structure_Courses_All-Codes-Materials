#include <iostream>
#include <stack>
using namespace std;

bool hasDuplicateBrackets(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == ')') {
            if (s.top() == '(') return true;
            while (s.top() != '(') s.pop();
            s.pop();
        } else {
            s.push(ch);
        }
    }
    return false;
}

int main() {
    string expr;
    getline(cin, expr);
    if (hasDuplicateBrackets(expr))
        cout << "Duplicate brackets found" << endl;
    else
        cout << "No Duplicate brackets" << endl;

    return 0;
}
