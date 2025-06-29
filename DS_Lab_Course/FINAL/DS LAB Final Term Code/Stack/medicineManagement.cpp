#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Medicine {
    string name;
    int batchNo;
    string expiry;
};

class MedicineStack {
    Medicine stack[MAX];
    int top;

public:
    MedicineStack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(const string& name, int batchNo, const string& expiry) {
        string today = "2025-05-26";

        if (expiry == today) {
            cout << "Cannot add medicine with today's expiry date.\n";
            return;
        }

        if (isFull()) {
            cout << "Storage is full.\n";
            return;
        }

        top++;
        stack[top].name = name;
        stack[top].batchNo = batchNo;
        stack[top].expiry = expiry;

        cout << "Medicine added successfully.\n";
    }

    void viewAll() {
        if (isEmpty()) {
            cout << "No medicine in storage.\n";
            return;
        }

        cout << "All medicines in storage:\n";
        for (int i = top; i >= 0; --i) {
            cout << "Name: " << stack[i].name
                 << ", Batch No: " << stack[i].batchNo
                 << ", Expiry: " << stack[i].expiry << endl;
        }
    }

    void searchByName(const string& name) {
        bool found = false;
        cout << "Searching for medicine: " << name << endl;
        for (int i = top; i >= 0; --i) {
            if (stack[i].name == name) {
                cout << "Found - Batch No: " << stack[i].batchNo
                     << ", Expiry: " << stack[i].expiry << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No medicine found with the name: " << name << endl;
        }
    }
};

int main() {
    MedicineStack ms;

    ms.push("Paracetamol", 201, "2025-06-01");
    ms.push("Ibuprofen", 202, "2025-05-26");
    ms.push("Aspirin", 203, "2025-07-15");

    cout << endl;
    ms.viewAll();

    cout << endl;
    ms.searchByName("Paracetamol");

    return 0;
}

