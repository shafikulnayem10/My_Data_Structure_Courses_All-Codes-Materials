#include<iostream>
using namespace std;

class Stop {
public:
    int id;
    string name;
    int passengers;
    Stop* next;

    Stop(int id, string name, int passengers) {
        this->id = id;
        this->name = name;
        this->passengers = passengers;
        next = nullptr;
    }
};

void addStop(Stop*& head, int id, string name, int passengers) {
    Stop* newStop = new Stop(id, name, passengers);
    if (!head) {
        head = newStop;
        return;
    }
    Stop* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newStop;
}

void showRoute(Stop* head) {
    cout << "Bus Route (Forward):\n";
    while (head) {
        cout << "[ID:" << head->id << ", " << head->name << ", Passengers: " << head->passengers << "] -> ";
        head = head->next;
    }
    cout << "END\n";
}

void reverseRoute(Stop* head) {
    if (!head) return;
    cout << "Bus Route (Return Journey):\n";


    if (head->next) reverseRoute(head->next);
    cout << "[ID:" << head->id << ", " << head->name << ", Passengers: " << head->passengers << "] <- ";
}

void removeStopByID(Stop*& head, int id) {
    if (!head) return;
    if (head->id == id) {
        Stop* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Stop* prev = nullptr;
    Stop* curr = head;
    while (curr && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        delete curr;
    }
}

void maxPassengerStop(Stop* head) {
    if (!head) return;
    Stop* maxStop = head;
    Stop* temp = head->next;
    while (temp) {
        if (temp->passengers > maxStop->passengers)
            maxStop = temp;
        temp = temp->next;
    }
    cout << "Stop with Max Passengers: [ID:" << maxStop->id << ", " << maxStop->name << ", " << maxStop->passengers << "]\n";
}

int main() {
    Stop* route = nullptr;

    addStop(route, 1, "Depot", 0);
    addStop(route, 2, "Stop A", 15);
    addStop(route, 3, "Stop B", 30);
    addStop(route, 4, "Stop A", 25);
    addStop(route, 5, "Stop C", 20);

    showRoute(route);

    reverseRoute(route);
    cout << "START\n";

    cout << "\nRemoving stop with ID 3...\n";
    removeStopByID(route, 3);
    showRoute(route);

    maxPassengerStop(route);

    return 0;
}

