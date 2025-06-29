#include <iostream>
using namespace std;


int main ()
{
    int a = 10;
    int *ptr;
    ptr = &a;

    cout << a <<endl; // 10
    cout << ptr <<endl; // address
    cout << &a <<endl; // address
    cout << *ptr <<endl; // 10

    //cout << endl;
    //cout << "******* Wild Pointer *******" <<endl;
    //int b = 20;
    //int *ptr1;
    //cout << ptr1 <<endl; //address
    //cout << *ptr1 <<endl; // value

    cout <<endl;
    cout << "****** Null pointer ******" <<endl;
    int b = 55;
    int *ptr2 = nullptr;
    if(ptr2 == nullptr)
    {
        cout << "Null Pointer" <<endl;
    }
    else
    {
        cout << "Not Null Pointer" <<endl;
    }

    ptr2 = &b;
    cout << "After assigning value: " <<ptr2 <<endl;
    cout << "After assigning value: " <<*ptr2 <<endl;

    cout <<endl;
    cout << "****** Void pointer ******" <<endl;
    int c = 10;
    float d = 10.55;
    double e = 10.654654;
    char f = 'c';

    void *ptr3;

    ptr3 = &c;
    cout << "Value of c: " << *(int*)ptr3 <<endl;

    ptr3 = &f;
    cout << "Value of f: " << *(char*)ptr3 <<endl;


}

