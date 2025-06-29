#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node* &tail, Node* &head, int d) {
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if(position == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if(temp == NULL || temp->next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node* &tail, Node* &head, int position) {
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        if(head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < position && curr != NULL) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if(curr == NULL) return;

        prev->next = curr->next;
        if(curr->next != NULL) {
            curr->next->prev = prev;
        }
        else {
            tail = prev;
        }
        delete curr;
    }
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data;
        if(temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

int findMidPoint(Node* head) {
    if(head == NULL) return -1;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int value) {
    if(root == nullptr) {
        return new TreeNode(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

void postorder(TreeNode* root) {
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Initial route
    Node* head = NULL;
    Node* tail = NULL;

    // Create initial delivery route
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 35);
    insertAtTail(tail, head, 50);
    insertAtTail(tail, head, 65);
    insertAtTail(tail, head, 80);

    cout << "Initial route: ";
    print(head);

    // Add 90 at the beginning
    cout << "\nAfter adding 90 at the beginning: ";
    insertAtHead(tail, head, 90);
    print(head);

    // Add 30 at 2nd last position (position 7 in current list)
    cout << "\nAfter adding 30 at 2nd last position: ";
    insertAtPosition(tail, head, 7, 30);
    print(head);

    // Remove the last stop (80)
    cout << "\nAfter removing the last stop: ";
    deleteNode(tail, head, getLength(head));
    print(head);

    // Get length and midpoint
    int length = getLength(head);
    cout << "\nLength of the route: " << length << endl;

    int midpoint = findMidPoint(head);
    if(midpoint != -1) {
        cout << "Mid-point of the route: " << midpoint << endl;
    }
    else {
        cout << "Cannot find mid-point of empty route" << endl;
    }

    // Create BST from remaining delivery points
    cout << "\nCreating BST from remaining delivery points..." << endl;
    TreeNode* root = nullptr;
    Node* temp = head;
    while(temp != NULL) {
        root = insert(root, temp->data);
        temp = temp->next;
    }

    cout << "Post-order traversal of BST: ";
    postorder(root);
    cout << endl;

    return 0;
}
