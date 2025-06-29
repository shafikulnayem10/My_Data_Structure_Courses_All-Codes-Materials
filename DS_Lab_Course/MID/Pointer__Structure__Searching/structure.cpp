#include<iostream>
using namespace std;

struct Student
{
    string name;
    int age;
    float cgpa;
    string ID;
    double salary;

    int add (int a , int b)
    {
        cout << "Addition: " << a + b <<endl;
    }

};


int main ()
{
    Student s1;
    s1.name = "John";
    s1.age = 21;
    s1.cgpa = 3.48;
    s1.ID = "24-45125-2";
    s1.salary = 15000.484;

    cout << "Name: " << s1.name <<endl;
    cout << "Age: " << s1.age <<endl;
    cout << "Salary: " << s1.salary <<endl;

    s1.add(10,20);


    return 0;
}

