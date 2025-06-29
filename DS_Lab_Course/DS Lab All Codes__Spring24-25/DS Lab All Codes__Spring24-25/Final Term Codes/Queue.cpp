#include<iostream>
using namespace std;

class queue
{
public:
    int* arr;
    int forward;
    int backward;
    int n = 50;
    queue()
    {
        arr = new int[n];
        forward = -1;
        backward = -1;
    }
    void enequeue(int a)
    {
        if(backward == n-1)
        {
            cout << "Queue Empty..";
            return;
        }
        backward++;
        arr[backward] = a;

        if(forward == -1)
        {
            forward++;
        }
    }
    void dequeue ()
    {
        if(forward == -1 || forward > backward)
        {
            cout <<"Empty Queue. No pop..";
            return;
        }
        forward++;
    }
    int peekElement()
    {
        if(forward == -1 || forward > backward)
        {
            cout <<"Empty Queue. No pop..";
            return -1;
        }
        return arr[forward];
    }
    void display()
    {
        cout <<"Queue: ";
        for(int i = forward; i <=backward; i++)
        {
            cout << arr[i] << " ";
        }
        cout <<endl;
    }
};

int main ()
{
    queue q1;
    q1.enequeue(10);
    q1.enequeue(20);
    q1.enequeue(30);
    q1.enequeue(40);
    q1.enequeue(50);
    q1.display();
    cout << "Peek: " <<q1.peekElement() <<endl;

    q1.dequeue();
    q1.display();
    cout << "Peek: " <<q1.peekElement() <<endl;


    q1.dequeue();
    q1.display();
    cout << "Peek: " <<q1.peekElement() <<endl;

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    cout << "Peek: " <<q1.peekElement() <<endl;

}
