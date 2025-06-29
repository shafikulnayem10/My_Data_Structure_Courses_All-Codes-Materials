#include <iostream>

using namespace std;

struct Customer {
    int id;
    string name;
    int age;
    string address;
    string country;
};

int main() {
    const int SIZE = 4;
    Customer customers[SIZE] = {
        {89, "Ayaan Rahman", 23, "Road 5, Dhanmondi, Dhaka", "Bangladesh"},
        {90, "Nayra Karim", 21, "Road 10, Islamabad", "Pakistan"},
        {91, "Zayan Ahmed", 30, "Kolkata, West Bengal", "India"},
        {92, "Meher Fatima", 56, "Johar Town, Lahore", "Pakistan"}
    };

    int prizeWinners = 0;

    cout << "Prize Winner Customers (Age < 30):\n";
    for (int i = 0; i < SIZE; i++) {
        if (customers[i].age < 30) {
            prizeWinners++;
            cout << "ID: " << customers[i].id
                 << ", Name: " << customers[i].name
                 << ", Age: " << customers[i].age
                 << ", Address: " << customers[i].address
                 << ", Country: " << customers[i].country << endl;


            if (customers[i].country == "Bangladesh") {
                cout << "** Congratulations! You are a prize winner from Bangladesh! **\n";
            }
        }
    }

    cout << "\nTotal Number of Prize Winners: " << prizeWinners << endl;

    return 0;
}
