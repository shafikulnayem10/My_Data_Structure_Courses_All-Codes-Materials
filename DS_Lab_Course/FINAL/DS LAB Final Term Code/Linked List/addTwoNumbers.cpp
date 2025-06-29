
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#include <iostream>
using namespace std;

// Node structure
struct ListNode {
    int val;
    ListNode* next;
};

ListNode* createNode(int val) {
    ListNode* node = new ListNode();
    node->val = val;
    node->next = nullptr;
    return node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = nullptr;
    ListNode* last = nullptr;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        ListNode* newNode = createNode(sum % 10);

        if (result == nullptr) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    return result;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // First number: 342 (stored as 2 -> 4 -> 3)
    ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // Second number: 465 (stored as 5 -> 6 -> 4)
    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    cout << "L1: ";
    printList(l1);
    cout << "L2: ";
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result); // Expected: 7 -> 0 -> 8

    return 0;
}

