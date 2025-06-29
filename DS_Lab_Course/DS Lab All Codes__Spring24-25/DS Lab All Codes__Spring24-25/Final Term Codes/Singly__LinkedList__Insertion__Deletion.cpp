#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int value)
    {
        data = value;
        next = nullptr; // initially next = nullptr;
    }
};

void insertAtFirst(node* &head, int value)
{
    node* newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtLast (node* &head, int value)
{
    node* newNode = new node(value);

    if(head==nullptr)
    {
        head=newNode;
        return;
    }

    node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertAtAnyPosition(node* &head, int position, int value)
{
    if(position <=0)
    {
        cout << "Invalid Position.."<<endl;
        return;
    }

    if(position == 1)
    {
        insertAtFirst(head, value);
        return;
    }

    node* temp = head;
    for(int i = 1; i < position - 1; i++)
    {
        if(temp == nullptr)
        {
            cout << "Position out of bound.."<<endl;
            return;
        }
        temp=temp->next;
    }
    node* newNode = new node(value);
    newNode->next = temp->next;
    temp->next = newNode;



}

int search (node* &head, int key)
{
    node* temp = head;
    while(temp!= nullptr)
    {
        if(temp->data == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


void deleteAtFirst(node* &head){

head=head->next;

}

void  deleteAtLast(node* head){

node* temp=head;

while(temp->next->next!=nullptr){

    temp=temp->next;

}

temp->next=nullptr;

}

void deleteAtAnyPosition(node* &head, int position){

    node* temp=head;

for(int i=2; i< position; i++) {

  if(temp->next!=NULL) {

    temp = temp->next;
  }
}

temp->next = temp->next->next;

}



void display(node* head)
{
    node* temp = head;

    while(temp!=nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null " <<endl;
}

int main ()
{
    node* head = nullptr;
    insertAtLast(head, 15);
    insertAtLast(head, 25);
    insertAtLast(head, 35);
    insertAtLast(head, 45);
    //insertAtFirst(head, 16);
    cout << "Linked List: ";
    display(head);

    insertAtFirst(head, 16);
    cout<< endl;
    cout << "Updated List after inserting at first position: ";
    display(head);

    insertAtAnyPosition(head, 4, 33);
    cout<< endl;
    cout << "Updated List after Inserting 33 at position 4: ";
    display(head);


    cout << endl;
    int key;
    cout << "Enter search element: ";
    cin >> key;

    int result = search(head, key);
    if(result != 1)
    {
        cout << "\nElement " << key << " not found in the list...";
    }
    else
    {
        cout << "\nElement " << key << " found in the list...";
    }

    cout<< endl << endl;
    cout << "Delete at first: ";
    deleteAtFirst(head);
    display(head);

    cout<< endl;
    cout << "Delete at last: ";
    deleteAtLast(head);
    display(head);

    cout<< endl;
    cout << "Delete at specific position: ";
    deleteAtAnyPosition(head, 4);
    display(head);




}
