#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Patient {
    string name;
    int id;
    string disease;
};

class PatientQueue {
    Patient queue[MAX];
    int front, rear;

public:
    PatientQueue() {
        front = 0;
        rear = 0;
    }

    bool isDuplicateName(const string& name) {
        for (int i = front; i < rear; ++i) {
            if (queue[i].name == name)
                return true;
        }
        return false;
    }

    void enqueue(const string& name, int id, const string& disease) {
        if (rear == MAX) {
            cout << "Queue is full\n";
            return;
        }
        if (isDuplicateName(name)) {
            cout << "Patient with name \"" << name << "\" already exists. Rejected.\n";
            return;
        }
        queue[rear].name = name;
        queue[rear].id = id;
        queue[rear].disease = disease;
        rear++;
        cout << "Patient added successfully.\n";
    }

    void searchByDisease(const string& disease) {
        cout << "Patients with disease \"" << disease << "\":\n";
        bool found = false;
        for (int i = front; i < rear; ++i) {
            if (queue[i].disease == disease) {
                cout << "Name: " << queue[i].name << ", ID: " << queue[i].id << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No patients found with this disease.\n";
        }
    }

    void displayAll() {
        if (front == rear) {
            cout << "No patients in the queue.\n";
            return;
        }

        cout << "All patients in the queue:\n";
        for (int i = front; i < rear; ++i) {
            cout << "Name: " << queue[i].name
                 << ", ID: " << queue[i].id
                 << ", Disease: " << queue[i].disease << endl;
        }
    }
};

int main() {
    PatientQueue pq;

    pq.enqueue("Alice", 101, "Flu");
    pq.enqueue("Bob", 102, "Cold");
    pq.enqueue("Alice", 103, "Malaria");
    pq.enqueue("Charlie", 104, "Flu");

    cout << endl;
    pq.displayAll();

    cout << endl;
    pq.searchByDisease("Flu");

    return 0;
}

