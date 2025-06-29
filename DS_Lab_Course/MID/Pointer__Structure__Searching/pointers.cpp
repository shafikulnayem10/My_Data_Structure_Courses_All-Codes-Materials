#include<iostream>
using namespace std;

int main ()
{
    /* int a = 40;
    int *ptr;
    ptr = &a;

    cout << a <<endl; // 40
    cout << &a <<endl; //address
    cout << ptr << endl; //address
    cout << *ptr << endl; //40
    */

    // Types of pointer
    // Wild pointer
    int b = 10;
    int *ptr;
    cout << "Wild Pointer" <<endl;
    cout << ptr <<endl; //address
    //cout << *ptr <<endl; // value

    // Null pointer
    int c = 54;
    cout << "Null Pointer example" <<endl;
    int *ptr1 = nullptr;
    if(ptr1 == nullptr)
    {
        cout << "This is Null Pointer" <<endl;
    }
    else
    {
        cout << "Not Null Pointer" <<endl;
    }
    ptr1 = &c;
    cout << ptr1 <<endl; //c => address
    cout << *ptr1 <<endl; // c => value


    cout << "Void Pointer example" <<endl;
    int d = 10;
    float e = 3.14;
    double f = 2.654466;
    char g = 'a';

    void *ptr2;

    ptr2 = &d;
    cout << "Value of d: " << *(int*)ptr2 <<endl;

    ptr2 = &g;
    cout << "Value of g: " << *(char*)ptr2 <<endl;

    ptr2 = &f;
    cout << "Value of f: " << *(double*)ptr2 <<endl;


    // Print the element of an array using pointer
    cout <<endl;
    cout << "Print array using pointer: ";
    int array [10] = {1,2,3,4,5,6,7,8,9};
    int *ptr3;
    ptr3 = array;

    for (int i = 0; i < 9; i++)
    {
        cout << *ptr3++ << " ";
        //ptr3++;
    }





    return 0;
}
