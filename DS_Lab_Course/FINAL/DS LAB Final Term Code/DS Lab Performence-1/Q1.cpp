#include<iostream>
using namespace std;

class book {
public:
    string BName;
    int Bid;
    int BorrowTime;
    book* next;

    book(string name, int id, int time) {
        this->BName = name;
        this->Bid = id;
        this->BorrowTime = time;
        this->next = nullptr;
    }
};

void insertAttail(book*& head, book*& tail, string name, int id, int time) {
    book* newBook = new book(name, id, time);
    tail->next = newBook;
    tail = newBook;
}

void print(book*& head) {
    if (head == NULL) {
        cout << "List is empty " << endl;
        return;
    }
    book* temp = head;

    while (temp != NULL) {
        cout << temp->BName << " ";
        cout << temp->Bid << " ";
        cout << temp->BorrowTime;
        cout << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

void searching(book*& head, string name) {
    book* temp = head;
    int pos = 1;
    int count = 0;
    int firstPos = -1;
    int secondPos = -1;

    while (temp != nullptr) {
        if (temp->BName == name) {
            count++;
            if (firstPos == -1) {
                firstPos = pos;
            }
            else if (secondPos == -1) {
                secondPos = pos;
            }
        }
        temp = temp->next;
        pos++;
    }

    if (count == 0) {
        cout << "Book '" << name << "' not found in the list." << endl;
    }
    else {
        cout << "Book '" << name << "' found " << count << " time(s) in the list." << endl;
        cout << "First occurrence at position " << firstPos << endl;
        if (count >= 2) {
            cout << "Second occurrence at position " << secondPos << endl;
        }
    }
}

void deleteBook(int position, book*& head, book*& tail) {
    if (position == 1) {
        book* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        book* curr = head;
        book* prev = NULL;

        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (prev != NULL) {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        cout << "Book in position " << position << " is deleted." << endl;
    }
}

int main() {
    book* b1 = new book("harry potter", 101, 5);
    book* head = b1;
    book* tail = b1;
    insertAttail(head, tail, "hunger games", 107, 7);
    insertAttail(head, tail, "twilight", 111, 9);
    insertAttail(head, tail, "hunger games", 107, 11);
    insertAttail(head, tail, "harry potter", 102, 3);
    insertAttail(head, tail, "hunger games", 108, 4);
    print(head);

    cout << "\nSearch results:" << endl;
    searching(head, "hunger games");

    cout << "\nDelete operation:" << endl;
    deleteBook(3, head, tail);
    cout << "After deleting:" << endl;
    print(head);
}
