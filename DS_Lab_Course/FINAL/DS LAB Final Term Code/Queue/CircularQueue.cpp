#include<iostream>
using namespace std;

class circularQueue
{
public:
    int* arr;
    int front,end,capacity,currentSize;

    circularQueue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        currentSize = 0;
        front = -1;
        end = -1;
    }
    void push(int x)
    {
        if(currentSize == capacity)
        {
            cout << "CQ is full. No push";
            return;
        }
        end = (end+1)%capacity;
        arr[end] = x;
        currentSize++;

        if(front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if(currentSize == 0)
        {
            cout << "CQ empty. No pop..";
            return;
        }
        front = (front+1)%capacity;
        currentSize--;
    }
    int peek()
    {
        if(currentSize == 0)
        {
            cout << "CQ empty. No peek..";
            return -1;
        }
        return arr[front];
    }
    void diplay()
    {
        if(currentSize == 0)
        {
            cout << "CQ empty.";
            return;
        }
        cout << "Circular Queue: ";

        int count = currentSize;
        int i = front;

        while(count--)
        {
            cout << arr[i] << " ";
            i = (i+1)%capacity;
        }
    }

};

int main ()
{
    circularQueue q1(4);
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    q1.diplay();
    cout << "\nPeek: " << q1.peek() <<endl;

    q1.pop();
    q1.pop();
    q1.diplay();
    cout << "\nPeek: " << q1.peek() <<endl;

    q1.push(50);
    q1.diplay();
    cout << "\nPeek: " << q1.peek() <<endl;

    q1.pop();
    q1.pop();
    q1.diplay();
    cout << "\nPeek: " << q1.peek() <<endl;

    q1.pop();
    q1.diplay();
    cout << "\nPeek: " << q1.peek() <<endl;

    q1.push(60);
    q1.diplay();
    cout << "\nPeek: " << q1.peek() <<endl;

}
