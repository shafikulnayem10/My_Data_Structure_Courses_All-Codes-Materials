#include<iostream>
using namespace std;

class Node{

int data;
Node* next;
Node* prev;
 Node(int d){
 this->data=d;
 this->next=nullptr;
 this->prev=nullptr;

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

void searching(Node* &head, int d) {
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr && temp->data != d) {
        temp = temp->next;
        pos++;
        return;
    }

    if (temp == nullptr) {
        cout << "Data not found" << endl;
    }
    else {
        cout << temp->data << " found at position " << pos << endl;
    }
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
 insertAtTail(tail,head, 25);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

cout<<" inserting at any position:"<<endl;

cout<<"1st time insert"<<endl;
    insertAtAnyPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
cout<<" 2nd time insert"<<endl;
    insertAtAnyPosition(tail, head, 1, 101);
    print(head);

    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
    cout<< "searching:"<<endl;
    searching(head,25);
}
