#include <iostream>
using namespace std;


int main ()
{
    int array [20] = {10,20,50,70,90};
    int *ptr;
    ptr = array;

    //cout << ptr <<endl; // address of index 0
    //cout << *ptr <<endl; // value of index 0

    for (int i = 0; i <5; i++)
    {
        cout << *ptr <<" ";
        ptr++;
    }
}


