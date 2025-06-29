#include <iostream>
using namespace std;

struct Student
{
    string name;
    int ID;
    float cgpa;
    string dept;

    void addition (int a, int b)
    {
        cout << "Add: " << a + b <<endl;
    }
};


int main ()
{
    Student s1;
    s1.name = "John";
    s1.ID = 123;
    s1.cgpa = 3.78;
    s1.dept = "CS";

    cout << s1.name <<endl;
    cout << s1.ID <<endl;
    cout << s1.cgpa <<endl;
    cout << s1.dept <<endl;

    s1.addition(10,15);

}



