#include<iostream>
using namespace std;

class Ticket {
public:
    string name, destination;
    int seat;
    Ticket* next;
    Ticket* prev;

    Ticket(string name, int seat, string dest) {
        this->name = name;
        this->seat = seat;
        destination = dest;
        next = prev = nullptr;
    }
};

void bookTicket(Ticket*& head, string name, int seat, string dest) {
    Ticket* newT = new Ticket(name, seat, dest);
    if (!head) {
        head = newT;
        return;
    }
    Ticket* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newT;
    newT->prev = temp;
}

void showForward(Ticket* head) {
    cout << "\nForward Booking:\n";
    while (head) {
        cout << "[" << head->seat << ": " << head->name << " -> " << head->destination << "] <--> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void showBackward(Ticket* tail) {
    cout << "\nReturn Booking View:\n";
    while (tail) {
        cout << "[" << tail->seat << ": " << tail->name << " -> " << tail->destination << "] <--> ";
        tail = tail->prev;
    }
    cout << "NULL\n";
}

void cancelTicketBySeat(Ticket*& head, int seat) {
    if (!head) return;
    Ticket* curr = head;
    while (curr && curr->seat != seat) curr = curr->next;
    if (!curr) return;
    if (curr->prev) curr->prev->next = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    if (curr == head) head = curr->next;
    delete curr;
}

void findFirstAvailableSeat(Ticket* head) {
    int expected = 1;
    while (head) {
        if (head->seat == expected) {
            expected++;
        } else if (head->seat > expected) {
            break;
        }
        head = head->next;
    }
    cout << "\nFirst Available Seat: " << expected << endl;
}

int main() {
    Ticket* head = nullptr;

    bookTicket(head, "Alice", 1, "Dhaka");
    bookTicket(head, "Bob", 2, "Sylhet");
    bookTicket(head, "Charlie", 4, "Khulna");

    showForward(head);

    Ticket* tail = head;
    while (tail && tail->next) tail = tail->next;
    showBackward(tail);

    cout << "\nCancel ticket for seat 2...\n";
    cancelTicketBySeat(head, 2);

    showForward(head);

    findFirstAvailableSeat(head);
    return 0;
}

