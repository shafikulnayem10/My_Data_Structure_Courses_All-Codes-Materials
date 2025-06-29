#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int* stackArray;
    int maxSize;

public:
    Stack(int size) {
        maxSize=size;
        stackArray=new int[maxSize];
        top=-1;
    }

    ~Stack(){
        delete[] stackArray;
    }

    bool isEmpty() const {
        return top==-1;
    }

    bool isFull()const {
        return top==maxSize-1;
    }

    bool push(int elem) {
        if (isFull()) {
            cout<<"Stack Overflow. jayga nai."<<endl;
            return false;
        }
        top++;
        stackArray[top]=elem;
        return true;
    }

    bool pop() {
        if (isEmpty()) {
            cout<<"Stack Underflow. khali."<<endl;
            return false;
        }
        top--;
        return true;
    }

    void topele() {
        if (!isEmpty()) {
            cout<<"Top: "<<stackArray[top]<<endl;
        } else {
            cout<<"Stack is empty."<<endl;
        }
    }

    void show() const {
        if (!isEmpty()) {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout<<stackArray[i]<<" ";
            }
            cout<<endl;
        } else {
            cout<<"Stack is empty."<<endl;
        }
    }

    int getCount()const {
        return top+1;
    }
};

int main(){
    int size,choice,value;

    cout<<"Enter the size of the stack: ";
    cin>>size;

    Stack s(size);

    do {
        cout<<"1. Push element to stack" << endl;
        cout<<"2. Pop element from stack" << endl;
        cout<<"3. Check Stack Overflow" << endl;
        cout<<"4. Check Stack Underflow" << endl;
        cout<<"5. Show top element" << endl;
        cout<<"6. Display stack elements" << endl;
        cout<<"7. Count elements in stack" << endl;
        cout<<"8. Exit"<<endl; cout<<"Enter your choice: "<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the element to push: ";
                cin>>value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if(s.isFull()){
                    cout<<"Stack is in Overflow state."<<endl;
                } else{
                    cout<<"Stack is not in Overflow state."<<endl;
                }
                break;
            case 4:
                if(s.isEmpty()) {
                    cout<<"Stack is in Underflow state."<<endl;
                } else {
                    cout<<"Stack is not in Underflow state."<<endl;
                }
                break;
            case 5:
                s.topele();
                break;
            case 6:
                s.show();
                break;
            case 7:
                cout<<"Number of elements in stack: "<<s.getCount()<< endl;
                break;
            case 8:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please enter a valid choice."<< endl;
                break;
        }
    } while (choice!=8);

    return 0;
}
