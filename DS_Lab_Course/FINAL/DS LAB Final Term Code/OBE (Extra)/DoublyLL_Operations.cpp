#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;


    Node(int d ) {
        this-> data = d;
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
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}
void insertAtTail(Node* &tail,Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

void insertAtAnyPosition(Node* & tail, Node* &head, int position, int d) {


    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }


    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }


    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}



void deleteNode(int position, Node* & head,Node* tail) {


    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
        cout << "Node in position " << position<< "  is deleted." << endl;
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
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
     cout << "Node in position " << position<< "  is deleted." << endl;
    }
}



void print(Node* head) {
    Node* temp  = head ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;
    Node* temp  = head ;

    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }

    return len;
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
            left = mid + 1;//for reverse case
        } else {
            right = mid - 1;// for reverse case
        }
    }

    cout << target << " not found in the list." << endl;
    return false;
}
//Remove Duplicates from a Sorted/UnSorted Linked List:

void removeDuplicate(Node*& head) {
    if (head == nullptr) return;

    Node* current = head;

    while (current != nullptr) {
        Node* runner = current->next;
        while (runner != nullptr) {
            if (current->data == runner->data) {
                Node* duplicate = runner;
                runner = runner->next;

                if (duplicate->prev != nullptr)
                    duplicate->prev->next = duplicate->next;
                else
                    head = duplicate->next; // duplicate was head

                if (duplicate->next != nullptr)
                    duplicate->next->prev = duplicate->prev;

                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
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
    removeDuplicate(head);
}

/*
//Merge 2 Sorted Linked Lists :
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

    // Attach remaining nodes
    if (head1 != NULL) mergedTail->next = head1;
    if (head2 != NULL) mergedTail->next = head2;

    return mergedHead;
}
*/
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
int main(){
Node* node1= new Node(10);
Node* head= node1;
Node*tail = node1;
print(head);
cout << "length:"<<getLength(head) << endl;
cout<<"1st time add on head:"<<endl;
insertAtHead(tail,head, 11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
cout<<"2nd time add on head "<<endl;

insertAtHead(tail,head, 13);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

cout<<" inserting at tail:"<<endl;
 insertAtTail(tail,head, 11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

cout<<" inserting at any position:"<<endl;

cout<<"1st time insert"<<endl;
    insertAtAnyPosition(tail, head, 2, 11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
cout<<" 2nd time insert"<<endl;
    insertAtAnyPosition(tail, head, 1, 11);
    print(head);

    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

cout<<"3rd time insert"<<endl;
    insertAtAnyPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
 cout<<" deleting:"<<endl;
    deleteNode(7, head,tail);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
     cout<< "searching:"<<endl;
    searching(head,90);
    cout<<"sorting(ASC):"<<endl;
    sorting(head);
    print(head);
    cout << "Reversing the linked list:" << endl;
   reverseLinkedList(head, tail);
    print(head);
     cout << "Binary search for 25:" << endl;
   binarySearch(head, 25);
 /* insertAtHead(tail,head, 1004);
   insertAtHead(tail,head, 1009);
 insertAtHead(tail,head,10);
insertAtTail(tail,head, 90);
insertAtAnyPosition(tail, head, 2, 20);
insertAtAnyPosition(tail, head, 3, 30);
insertAtAnyPosition(tail, head, 4, 20);
insertAtAnyPosition(tail, head, 5, 40);
insertAtAnyPosition(tail, head, 6, 20);
insertAtAnyPosition(tail, head, 7, 50);
insertAtAnyPosition(tail, head, 8, 20);
insertAtAnyPosition(tail, head, 9, 60);
insertAtAnyPosition(tail, head, 10, 70);
insertAtAnyPosition(tail, head, 11, 80);
cout << "List before removing duplicates:\n";
print(head);
removeDuplicate(head);
cout << "List after removing duplicates:\n";
print(head);

cout<<"Remove Duplicates from a Sorted/UnSorted Linked List"<<endl;
   checkAndRemoveDuplicatesSorted(head);
  print(head);
*/
/*
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
*/
   if (isPalindrome(head, tail)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is NOT a palindrome." << endl;
    }
}
