#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to add a node to the end of a list
void appendNode(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two sorted lists
Node* mergeLists(Node* list1, Node* list2) {
    Node* mergedList = nullptr;

    // While both lists have nodes
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            appendNode(mergedList, list1->data);
            list1 = list1->next;
        } else {
            appendNode(mergedList, list2->data);
            list2 = list2->next;
        }
    }

    // If list1 still has nodes left
    while (list1 != nullptr) {
        appendNode(mergedList, list1->data);
        list1 = list1->next;
    }

    // If list2 still has nodes left
    while (list2 != nullptr) {
        appendNode(mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

// Function to print a linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create the first sorted list: 3, 7, 10, 15, 19, 35
    Node* list1 = nullptr;
    appendNode(list1, 3);
    appendNode(list1, 7);
    appendNode(list1, 10);
    appendNode(list1, 15);
    appendNode(list1, 19);
    appendNode(list1, 35);

    // Create the second sorted list: 2, 6, 12, 17
    Node* list2 = nullptr;
    appendNode(list2, 2);
    appendNode(list2, 6);
    appendNode(list2, 12);
    appendNode(list2, 17);

    // Merge the two lists
    Node* mergedList = mergeLists(list1, list2);

    // Print the merged list
    cout << "Merged sorted list: ";
    printList(mergedList);

    return 0;
}
