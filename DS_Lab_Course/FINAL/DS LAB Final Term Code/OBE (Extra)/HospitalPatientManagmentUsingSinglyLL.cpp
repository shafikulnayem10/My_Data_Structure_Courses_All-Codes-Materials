#include<iostream>
using namespace std;

class Patient {
public:
    string name;
    int age;
    int severity;
    Patient* next;

    Patient(string name, int age, int severity) {
        this->name = name;
        this->age = age;
        this->severity = severity;
        next = nullptr;
    }
};

void addPatient(Patient*& head, string name, int age, int severity) {
    Patient* newP = new Patient(name, age, severity);
    if (!head) {
        head = newP;
        return;
    }
    Patient* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newP;
}

void displayPatients(Patient* head) {
    cout << "\nPatient List:\n";
    while (head) {
        cout << head->name << ", Age: " << head->age << ", Severity: " << head->severity << " → ";
        head = head->next;
    }
    cout << "NULL\n";
}

void removePatientByName(Patient*& head, string target) {
    if (!head) return;
    if (head->name == target) {
        Patient* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Patient* prev = nullptr;
    Patient* curr = head;
    while (curr && curr->name != target) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        delete curr;
    }
}

void mostSeverePatient(Patient* head) {
    if (!head) return;
    Patient* worst = head;
    while (head) {
        if (head->severity > worst->severity)
            worst = head;
        head = head->next;
    }
    cout << "\nMost Critical Patient: " << worst->name << " (Severity: " << worst->severity << ")\n";
}

int main() {
    Patient* queue = nullptr;
    addPatient(queue, "Alice", 30, 2);
    addPatient(queue, "Bob", 45, 5);
    addPatient(queue, "Charlie", 25, 4);

    displayPatients(queue);

    mostSeverePatient(queue);

    cout << "\nRemoving patient: Alice\n";
    removePatientByName(queue, "Alice");

    displayPatients(queue);
    return 0;
}

