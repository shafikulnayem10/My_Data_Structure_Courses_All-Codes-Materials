#include<iostream>
using namespace std;

int main ()
{
    int a = 10;
    int *p = &a;

    cout << "value of p: " << p <<endl; //address
    cout << "value of *p: " << *p <<endl <<endl; //value

    int **q;
    q = &p;

    cout << "value of q: " << q <<endl; // address of q
    cout << "value of *q: " << *q <<endl; // value of p
    cout << "value of **q: " << **q <<endl; // value of a

}





