#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(string word) {
    stack<char> s;
    for (char ch : word) s.push(ch);

    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return word == reversed;
}

int main() {
    string word;
    cin >> word;

    if (isPalindrome(word))
        cout << "Yes, it's a palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;

    return 0;
}

