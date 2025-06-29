#include <iostream>
using namespace std;

struct Student
{
public:
    string name;
    string ID;
    string dept;
    int age;

    int getTaka (int f1, int f2, int f3)
    {
        cout << "Total Taka: " << f1 + f2 + f3;
    }

private:
    string mobile;
    string address;
    float cgpa;

public:
    void setValues (string m, string a, float c)
    {
        mobile = m;
        address = a;
        cgpa = c;
    }
    void display()
    {
        cout << "Mobile: " << mobile <<endl;
        cout << "Address: " << address <<endl;
        cout << "CGPA: " << cgpa <<endl;
    }
} ;


int main ()
{
  Student s1;
  s1.name = "John";
  s1.ID = "24-12345-3";
  s1.dept = "Computer Science";
  s1.age = 22;

  cout << "Name: " <<s1.name <<endl;
  cout << "ID: " <<s1.ID <<endl;
  cout << "Department: " <<s1.dept <<endl;
  cout << "Age: " <<s1.age <<endl;

  s1.setValues("01712345678", "Dhaka, Bangladesh", 3.96);
  s1.display();
  s1.getTaka(1000, 1500, 2500);

  return 0;
}
