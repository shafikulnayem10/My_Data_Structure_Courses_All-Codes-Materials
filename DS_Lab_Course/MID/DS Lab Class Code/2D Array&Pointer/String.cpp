#include <iostream>
using namespace std;

int reverseString (string& input)
{
    int length = input.length();
    for(int i = 0; i <length/2 ; i++)
    {
        swap(input[i], input[length-i-1]);
    }
}


int main ()
{
    string input;
    cout << "Enter Input: ";
    getline(cin, input);
    reverseString(input);
    cout << "Reversed: " << input;
}
