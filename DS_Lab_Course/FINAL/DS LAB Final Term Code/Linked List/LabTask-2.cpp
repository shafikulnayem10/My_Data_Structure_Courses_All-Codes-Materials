#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void insertAtTail(Node*& head, Node*& tail, char d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

bool isPalindrome(Node* head, Node* tail) {
    while (head != NULL && tail != NULL && head != tail && tail->next != head) {
        if (head->data != tail->data){
             return false;
        }

        head = head->next;
        tail = tail->prev;
    }
    return true;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    string str = "racecar";
    for (char c : str)
        insertAtTail(head, tail, c);

    cout << "Character List:" << endl;
    print(head);

    if (isPalindrome(head, tail)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is NOT a palindrome." << endl;
    }

    return 0;
}

