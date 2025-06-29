#include <iostream>
#include <string>
using namespace std;

// Structure to hold employee information
struct Employee {
    int id;
    string name;
    float salary;
    int age;
};

int main() {
    const int SIZE = 40;
    Employee employees[SIZE];

    // Input data for 40 employees
    for (int i = 0; i < SIZE; i++) {
        employees[i].id = i + 1; // Unique ID starting from 1
        cout << "Enter details for employee " << employees[i].id << ":\n";
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Salary: ";
        cin >> employees[i].salary;
        cout << "Age: ";
        cin >> employees[i].age;
        cout << endl;
    }

    // Display IDs of employees meeting the criteria
    int k=0;
    cout << "Employees with age < 40 and salary > 50000:\n";
    for (int i = 0; i < SIZE; i++) {
        if (employees[i].age < 40 && employees[i].salary > 50000) {
                k=i;
            cout << "Employee ID: " << employees[k].id << endl;
        }
    }

    return 0;
}

