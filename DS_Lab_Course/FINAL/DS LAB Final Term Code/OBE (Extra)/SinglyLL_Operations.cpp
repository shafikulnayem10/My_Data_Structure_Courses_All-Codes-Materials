#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;


    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }



};


void insertAtHead(Node* &head, int d) {


    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {

    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}
void insertAtAnyPosition(Node* &tail, Node* & head, int position, int d) {



    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }


    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }


    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}


void deleteNode(int position, Node* & head,Node* &tail) {

    if(position == 1) {
        Node* temp = head;
        head = head -> next;

        temp -> next = NULL;
        delete temp;
    }
    else
    {

       Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

       if(prev != NULL){
        tail= prev;
       }
       prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;


        cout << "Node in position " << position<< "  is deleted." << endl;


    }
}


void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


void searching(Node* &head, int d) {
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr && temp->data != d) {
        temp = temp->next;
        pos++;

    }

    if (temp == nullptr) {
        cout << "Data not found" << endl;
    } else {
        cout << temp->data << " found at position " << pos << endl;
    }
}


void sorting(Node *head){
Node*fptr=head;
Node *sptr= nullptr;
while(fptr!=nullptr){
    sptr=fptr->next;
    while(sptr!=nullptr){
        if(fptr->data>sptr->data){
            swap(fptr->data,sptr->data);
        }
        sptr=sptr->next;

    }
    fptr=fptr->next;
}

}


void reverseLinkedList(Node* &head, Node* &tail) {
    if (head == NULL || head->next == NULL) return;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL) {

        forward = curr->next;

        curr->next = prev;

        prev = curr;
        curr = forward;
    }


    tail = head;
    head = prev;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
Node* getNodeAtIndex(Node* head, int index) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL && count < index) {
        temp = temp->next;
        count++;
    }
    return temp;
}
bool binarySearch(Node* head, int target) {
    int left = 0;
    int right = countNodes(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAtIndex(head, mid);

        if (midNode == NULL) return false;

        if (midNode->data == target) {
            cout << "Found " << target << " at index " << mid << endl;
            return true;
        } else if (midNode->data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << target << " not found in the list." << endl;
    return false;
}


void removeDuplicatesSorted(Node* head) {
    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
}
bool isSorted(Node* head) {
    if (head == NULL || head->next == NULL) return true;

    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data)
            return false;
        temp = temp->next;
    }
    return true;
}

void checkAndRemoveDuplicatesSorted(Node* &head) {
    cout << "Checking if list is sorted..." << endl;
    if (!isSorted(head)) {
        cout << "List is not sorted. Sorting now..." << endl;
        sorting(head);
    } else {
        cout << "List is already sorted." << endl;
    }

    cout << "Removing duplicates from sorted list..." << endl;
    removeDuplicatesSorted(head);
}


void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    while (head1 != NULL && head2 != NULL) {
        Node* temp = NULL;

        if (head1->data < head2->data) {
            temp = head1;
            head1 = head1->next;
        } else {
            temp = head2;
            head2 = head2->next;
        }

        if (mergedHead == NULL) {
            mergedHead = temp;
            mergedTail = temp;
        } else {
            mergedTail->next = temp;
            mergedTail = temp;
        }
    }


    if (head1 != NULL) mergedTail->next = head1;
    if (head2 != NULL) mergedTail->next = head2;

    return mergedHead;
}

bool isPalindrome(Node* head) {

    Node* reversed = NULL;
    Node* temp = head;
    while (temp != NULL) {
        Node* newNode = new Node(temp->data);
        newNode->next = reversed;
        reversed = newNode;
        temp = temp->next;
    }


    Node* a = head;
    Node* b = reversed;
    while (a != NULL && b != NULL) {
        if (a->data != b->data) {
            return false;
        }
        a = a->next;
        b = b->next;
    }

    return true;
}





int main() {


    Node* node1 = new Node(10);



    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout<<"insert at the head "<<endl;

    insertAtHead(head, 12);
    insertAtHead(head, 90);

    print(head);

    cout<<" insert at the tail"<<endl;

    insertAtTail(tail, 15);
    insertAtTail(tail, 5);
    print(head);
   cout<<"insert at any possition"<<endl;
    insertAtAnyPosition(tail,head, 4, 22);
    print(head);
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    cout<<"delete node:"<<endl;
    deleteNode(6, head,tail);

     print(head);
     cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    cout<< "searching:"<<endl;
    searching(head,90);
    cout<<"sorting(ASC):"<<endl;
    sorting(head);
    print(head);
    cout << "Reversing the linked list:" << endl;
   reverseLinkedList(head, tail);
   print(head);
   cout << "head " << head -> data << endl;
   cout << "tail " << tail -> data << endl;
   cout << "Binary search for 15:" << endl;
   binarySearch(head, 15);
    cout<<"Remove Duplicates from a Sorted/UnSorted Linked List"<<endl;
   checkAndRemoveDuplicatesSorted(head);
  print(head);
cout<<"merge two sorted LL:"<<endl;
 Node* head1 = NULL;
Node* tail1 = NULL;
insertAtTail(head1, tail1, 1);
insertAtTail(head1, tail1, 4);
insertAtTail(head1, tail1, 7);

Node* head2 = NULL;
Node* tail2 = NULL;
insertAtTail(head2, tail2, 2);
insertAtTail(head2, tail2, 5);
insertAtTail(head2, tail2, 6);

cout << "List 1: ";
print(head1);
cout << "List 2: ";
print(head2);

Node* merged = mergeSortedLists(head1, head2);
cout << "Merged Sorted List: ";
print(merged);

cout<<"Check Palindrome in Linked List:"<<endl;
if (isPalindrome(head)) {
    cout << "Palindrome" << endl;
} else {
    cout << "Not Palindrome" << endl;
}



}
