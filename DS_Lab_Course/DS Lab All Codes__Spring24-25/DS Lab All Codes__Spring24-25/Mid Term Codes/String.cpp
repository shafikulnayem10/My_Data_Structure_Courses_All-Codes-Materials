#include <iostream>
using namespace std;

void upperCase (string& str)
{
    for (char& ch : str)
    {
        ch = toupper(ch);
    }
}

void lowerCase (string& str)
{
    for (char& ch : str)
    {
        ch = tolower(ch);
    }
}


int main ()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    upperCase(str);
    cout << "Uppercase: " <<str<<endl;
    lowerCase(str);
    cout << "Lowercase: " <<str<<endl;

    //find only lowercase and uppercase letters from the given string
    //Input: BaNglaDeSH
    //Output:
    //lower: aglae
    //upper: BNDSH

}
