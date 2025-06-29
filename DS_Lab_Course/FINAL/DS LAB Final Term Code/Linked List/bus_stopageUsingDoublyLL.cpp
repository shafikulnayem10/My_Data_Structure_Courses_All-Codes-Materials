#include<iostream>
using namespace std;

class Stop {
public:
    int id;
    string name;
    int passengers;
    Stop* next;
    Stop* prev;

    Stop(int id, string name, int passengers) {
        this->id = id;
        this->name = name;
        this->passengers = passengers;
        next = prev = nullptr;
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
    newStop->prev = temp;
}

void showForwardRoute(Stop* head) {
    cout << "Forward Route:\n";
    while (head) {
        cout << "[ID:" << head->id << ", " << head->name << ", Passengers: " << head->passengers << "] -> ";
        if (!head->next) break;
        head = head->next;
    }
    cout << "END\n";
}

void showBackwardRoute(Stop* tail) {
    cout << "Return Route:\n";
    while (tail) {
        cout << "[ID:" << tail->id << ", " << tail->name << ", Passengers: " << tail->passengers << "] <- ";
        tail = tail->prev;
    }
    cout << "START\n";
}

void removeStopByID(Stop*& head, int id) {
    if (!head) return;
    if (head->id == id) {
        Stop* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }
    Stop* curr = head;
    while (curr && curr->id != id) {
        curr = curr->next;
    }
    if (curr) {
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
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
    addStop(route, 2, "Stop A", 12);
    addStop(route, 3, "Stop B", 45);
    addStop(route, 4, "Stop A", 33);
    addStop(route, 5, "Stop C", 28);

    showForwardRoute(route);

    Stop* tail = route;
    while (tail && tail->next) tail = tail->next;

    showBackwardRoute(tail);

    cout << "\nRemoving stop with ID 2...\n";
    removeStopByID(route, 2);
    showForwardRoute(route);

    maxPassengerStop(route);

    return 0;
}

