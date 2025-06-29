#include<iostream>
using namespace std;

struct Employee
{
public:
    string name;
    string deg;
    int age;

private:
    string address;
    float sal;

public:
    void setValues (string a,float s)
    {
        address = a;
        sal = s;
    }
    void display ()
    {
        cout << "Address: " << address <<endl;
        cout << "Salary: " << sal <<endl;
    }



};


int main ()
{
    Employee e1;
    e1.name = "John";
    e1.deg = "Manager";
    e1.age = 38;

    cout << "Name: " << e1.name <<endl;
    cout << "Age: " << e1.age <<endl;
    cout << "Deg: " << e1.deg <<endl;

    e1.setValues("Dhaka, Bangladesh", 1500.54);
    e1.display();


    return 0;
}

