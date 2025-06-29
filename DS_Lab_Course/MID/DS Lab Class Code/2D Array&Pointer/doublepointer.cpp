#include <iostream>
using namespace std;

int main() {
    // Declare an integer variable
    int num = 42;

    // Pointer to store address of num
    int *ptr = &num;

    // Pointer to pointer (double pointer)
    int **doublePtr = &ptr;

    // Print all requested values
 cout << "Value of the variable (num): " << num << endl;
    cout << "Address of the variable (&num): " << &num << endl;
cout << "Value stored in first pointer (ptr): " << ptr << endl;
    cout << "Value stored in double pointer (doublePtr): " << doublePtr << endl;

    // Additional demonstration of accessing values through double pointer
    cout << "\nAdditional demonstration:" << endl;
    cout << "Accessing num through ptr: " << *ptr << endl;
    cout << "Accessing num through doublePtr: " << **doublePtr << endl;
    cout << "Accessing ptr's address through doublePtr: " << *doublePtr << endl;

    return 0;
}
