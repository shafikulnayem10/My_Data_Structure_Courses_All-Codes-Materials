/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to check if the list has a cycle
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast two steps and slow one step
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;             // 1 step
        fast = fast->next->next;       // 2 steps

        if (slow == fast) {
            return true;               // They meet = cycle exists
        }
    }

    return false;                      // fast reached end = no cycle
}
int main() {
    // Create nodes manually
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    // Link them: 1 -> 2 -> 3 -> 4
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create a cycle: 4 -> 2 (node4 points back to node2)
    node4->next = node2;

    // Check for cycle
    if (hasCycle(node1)) {
        cout << "Cycle found!" << endl;
    } else {
        cout << "No cycle." << endl;
    }

    return 0;
}

