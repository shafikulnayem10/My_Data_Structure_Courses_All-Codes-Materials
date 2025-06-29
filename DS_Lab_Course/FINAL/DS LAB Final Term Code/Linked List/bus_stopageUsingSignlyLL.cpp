#include<iostream>
using namespace std;

class Stop {
public:
    string name;
    Stop* next;

    Stop(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

void addStop(Stop*& head, string name) {
    Stop* newStop = new Stop(name);
    if (!head) {
        head = newStop;
        return;
    }
    Stop* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newStop;
}

void showRoute(Stop* head) {
    cout << "Bus Route: ";
    while (head) {
        cout << head->name << " -> ";
        head = head->next;
    }
    cout << "END" << endl;
}

void removeStop(Stop*& head, string name) {
    if (!head) return;
    if (head->name == name) {
        Stop* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Stop* prev = nullptr;
    Stop* curr = head;
    while (curr && curr->name != name) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        delete curr;
    }
}

int main() {
    Stop* route = nullptr;

    addStop(route, "Stop A");
    addStop(route, "Stop B");
    addStop(route, "Stop C");
    addStop(route, "Stop D");

    showRoute(route);

    cout << "\nRemoving 'Stop C'..." << endl;
    removeStop(route, "Stop C");
    showRoute(route);

    return 0;
}

