#include<iostream>
using namespace std;

class stack
{
public:
    int* arr;
    int topElement;
    int n = 50;

    stack()
    {
        arr = new int[n];
        topElement = -1;
    }
    void push(int a)
    {
        if(topElement == n-1)
        {
            cout <<"Stack overflow..." <<endl;
            return;
        }
        topElement++;
        arr[topElement] = a;
    }

    void pop()
    {
        if(topElement == -1)
        {
            cout << "Stack empty. Nothing to pop" <<endl;
            return;
        }
        topElement--;
    }

    int top()
    {
        if(topElement == -1)
        {
            cout << "Stack empty. Nothing to pop" <<endl;
            return -1;
        }
        return arr[topElement];
    }

    void display()
    {
        if(topElement == -1)
        {
            cout << "Stack Empty!!!!" <<endl;
            return;
        }

        cout << "Stack: ";
        for(int i = 0; i <= topElement; i++)
        {
            cout << arr[i] << " ";
        }
        cout <<endl;
    }
};

int main ()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    s.display();
    cout << "Top Element: "<<s.top() <<endl;

    cout <<endl;
    s.pop();
    s.display();
    cout << "Top Element: "<<s.top() <<endl;

    cout <<endl;
    s.pop();
    s.pop();
    s.pop();
    s.display();
    cout << "Top Element: "<<s.top() <<endl;

    cout <<endl;
    s.pop();
    s.pop();
    s.display();
    cout << "Top Element: "<<s.top() <<endl;
}
