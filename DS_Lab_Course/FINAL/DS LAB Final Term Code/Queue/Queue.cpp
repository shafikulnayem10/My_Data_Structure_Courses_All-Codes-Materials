#include<iostream>
using namespace std;

class queue
{
public:
    int* arr;
    int n = 4;
    int front, end;

    queue()
    {
        arr = new int[n];
        front = -1;
        end = -1;
    }
    void enqueue(int x)
    {
        if(end == n-1)
        {
            cout << "\nQueue is Full. Can't push";
            return;
        }
        end++;
        arr[end] = x;

        if(front == -1)
        {
            front++;
        }
    }
    void dequque()
    {
        if(front == -1 && front>end)
        {
            cout <<"\nQueue empty. Can not pop";
            return;
        }
        front++;
    }
    int topElement()
    {
         if(front == -1 || front>end)
        {
            cout <<"\nQueue empty. No top element";
            return -1;
        }
        return arr[front];
    }
    void display()
    {
        cout << "\nQueue: ";
        for(int i = front; i<=end; i++)
        {
            cout << arr[i] << " ";
        }
    }

};



int main ()
{
    queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.display();
    cout <<"\nPeek: " <<q1.topElement() <<endl;

    q1.enqueue(50);

    q1.dequque();
    q1.display();
    cout <<"\nPeek: " <<q1.topElement() <<endl;

    q1.dequque();
    q1.display();
    cout <<"\nPeek: " <<q1.topElement() <<endl;
}
