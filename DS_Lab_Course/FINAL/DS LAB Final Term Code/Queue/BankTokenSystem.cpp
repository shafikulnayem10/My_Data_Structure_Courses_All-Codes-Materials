#include <iostream>
#include <string>
using namespace std;

 const int MAX = 100;

struct Token {
    int tokenNumber;
    string name;
    string serviceType;
};

class BankQueue {
    Token queue[MAX];
    int front, rear;

public:
    BankQueue() {
        front = rear = 0;
    }

    void enqueue(int tokenNumber, const string& name, const string& serviceType) {


        if (rear == MAX) {
            cout << "Queue full.";
            return;
        }

        queue[rear].tokenNumber = tokenNumber;
        queue[rear].name = name;
        queue[rear].serviceType = serviceType;

        rear++;

        cout << "Customer added.\n";

        }

    void searchByName(const string& name) {
        bool found = false;
        cout << "Searching for customer: " << name << endl;
        for (int i = front; i <rear; i++) {
            if (queue[i].name == name) {
               cout << queue[i].tokenNumber << " - " << queue[i].name << " (" << queue[i].serviceType << ")\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No customer found with the name: " << name << endl;
        }
    }


    void display() {
        if (front == rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Current customers in queue:\n";
        for (int i = front; i < rear; i++) {
            cout << queue[i].tokenNumber << " - " << queue[i].name << " (" << queue[i].serviceType << ")\n";
        }
    }
};

int main() {
    BankQueue bank;

    bank.enqueue(1, "nayeem", "Deposit");
    bank.enqueue(2, "rahat", "Withdrawal");
    bank.enqueue(3, "sajjad", "accout opening");
    bank.enqueue(4, "arian", "Withdrawal");

    bank.display();


     string name;
     cout<<"Enter Customer Name:"<<endl;
     getline(cin,name);
     bank.searchByName(name);



    return 0;
}

