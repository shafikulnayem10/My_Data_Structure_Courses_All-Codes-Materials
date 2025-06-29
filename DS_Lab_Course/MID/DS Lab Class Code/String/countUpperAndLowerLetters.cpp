#include <iostream>
using namespace std;

int main() {
    string s;
    int lower = 0, upper = 0;

cout << "Enter a string: ";
cin >> s;


cout << "Lowercase letters: ";
for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            cout << c << " ";
            lower++;
        }
    }
    cout << "\nTotal lowercase letters: " << lower << endl;


    cout << "Uppercase letters: ";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            cout << c << " ";
            upper++;
        }
    }
    cout << "\nTotal uppercase letters: " << upper << endl;

    return 0;
}
