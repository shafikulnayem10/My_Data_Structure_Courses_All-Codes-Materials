#include<iostream>
using namespace std;

int reverseString (string str) // pass by reference
{
    int length = str.length();
    for(int i = 0; i < length / 2 ; i++)
    {
        swap(str[i], str[length - i -1]);
    }
}

int main ()
{
    string str;
    cout << "Enter Input: ";
    getline(cin,str);

    reverseString(str);
    cout << "Reverse String: " << str;


    return 0;

}
