#include <iostream>
#include <cctype> // For tolower() and isalpha()
using namespace std;

int main() {
    string input;
    int vowels = 0, consonants = 0;

    cout << "Enter a string: ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        char c = tolower(input[i]);

        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "\nNumber of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;

    return 0;
}
