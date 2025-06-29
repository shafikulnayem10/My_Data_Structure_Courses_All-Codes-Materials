#include<iostream>
using namespace std;
class node {

int data;
node* next;
node(int d){
this->data=d;
this->next=nullptr;



}

};

//insert:

void insertAtHead(node* &head,int d){

node* newnode= new node(d);
newnode->next=head;
head=newnode;


}
void insertAtTail(node* &tail,int d){

node* newnode= new node(d);
tail->next=newnode;
tail=newnode;



}
void insertAtMiddle(node* head, node*tail,int d){


node* temp=head;
while(temp->data!=d&&temp->next==nullptr){
    temp=temp->next;
}
node* newnode=new node(d);
newnode->next=temp->next;
temp->next=newnode;

}

int main(){

node* head=nullptr;
node* tail=nullptr;
insertAtHead(head,5);
insertAtTail(tail,8);
insertAtMiddle(head,tail,5);




}
