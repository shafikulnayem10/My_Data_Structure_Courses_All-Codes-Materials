#include<iostream>
using namespace std;

class Node{
public:
int data;
Node*prev;
Node*next;
Node(int d){
this->data=d;
this->prev=nullptr;
this->next=nullptr;

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

void removeDuplicate(Node* head) {
    if (head == nullptr){
         return;
    }

    Node* current = head;

    while (current != nullptr) {
        Node* runner = current->next;
        while (runner != nullptr) {
            if (current->data == runner->data) {
                Node* duplicate = runner;
                runner->prev->next = runner->next;
                if (runner->next != nullptr) {
                    runner->next->prev = runner->prev;
                }
                runner = runner->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
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
int main(){

Node* head= nullptr;
Node*tail = nullptr;
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
cout<<"before deleting duplicates:"<<endl;
print(head);
removeDuplicate(head);
cout<<"after deleteing duplicates:"<<endl;
print(head);




}
