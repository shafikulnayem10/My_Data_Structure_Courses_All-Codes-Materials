#include<iostream>
using namespace std;

class stack
{
public:
    int* arr;
    int size = 50;
    int topElement;

    stack()
    {
        arr = new int[size];
        topElement = -1;
    }
    void push(int a)
    {
        if(topElement == size-1)
        {
            cout<<"Stack full.. Get lost";
            return;
        }
        topElement++;
        arr[topElement] = a;
    }
    void pop()
    {
        if(topElement == -1)
        {
            cout <<"Stack empty. Get Lost..";
            return;
        }
        topElement--;
    }
    int top()
    {
        if(topElement == -1)
        {
            cout <<"Stack empty. Nothing on top";
            return -1;
        }
        return arr[topElement];
    }
    void display()
    {
        cout << "Stack: " <<endl;
        for(int i = topElement; i>=0; i--)
        {
            cout << arr[i] <<endl;
        }
    }
};


int main ()
{
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();
    cout <<"Top: "<<s1.top() <<endl;

    s1.pop();
    s1.display();
    cout <<"Top: "<<s1.top() <<endl;


    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.display();
    cout <<"Top: "<<s1.top() <<endl;
}
