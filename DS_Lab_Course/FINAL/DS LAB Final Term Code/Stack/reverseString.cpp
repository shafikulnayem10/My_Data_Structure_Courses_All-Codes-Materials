#include<iostream>
using namespace std;

class Stack
{
public:
    char* arr;
    int topElement;
    int n = 50;

    Stack()
    {
        arr = new char[n];
        topElement = -1;
    }

    void push(char a)
    {
        if(topElement == n-1)
        {
            cout <<"Stack overflow..." <<endl;
            return;
        }
        topElement++;
        arr[topElement] = a;
    }



    void display()
    {
        if(topElement == -1)
        {
            cout << "Stack Empty!!!!" <<endl;
            return;
        }

        cout << "Stack: ";
        for(int i = topElement; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s;
    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');

    s.display();

    return 0;
}
