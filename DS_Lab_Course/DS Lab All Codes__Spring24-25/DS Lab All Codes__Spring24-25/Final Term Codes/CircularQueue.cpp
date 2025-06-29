#include<iostream>
using namespace std;

class circularQueue
{
public:
    int* arr;
    int capacity, currentSize, front, end;

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
            cout << "\nCQ Full. Can't push..";
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
            cout << "\nCQ Empty. Can't pop.";
            return;
        }
        front = (front+1)%capacity;
        currentSize--;
    }
    int Peek()
    {
        if(currentSize == 0)
        {
            cout << "CQ Empty. Nothing on top.";
            return -1;
        }
        return arr[front];
    }
    void display()
    {
        cout << "\nCircular Queue: ";
        if (currentSize == 0) {
            cout << "CQ Empty";
            return;
        }
        int count = currentSize;
        int i = front;

        while (count--) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
    }
};


int main ()
{
    /* circularQueue cq(4);
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.display();
    cout << "\nPeek: " << cq.Peek();

    cq.pop();
    cq.display();
    cout << "\nPeek: " << cq.Peek();

    cq.push(50);
    cq.display();
    cout << "\nPeek: " << cq.Peek();

    cq.pop();
    cq.display();
    cout << "\nPeek: " << cq.Peek();

    cq.push(60);
    cq.display();
    cout << "\nPeek: " << cq.Peek(); */

    circularQueue q1(4);
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    q1.display();
    cout << "\nPeek: " << q1.Peek() <<endl;

    q1.pop();
    q1.display();
    cout << "\nPeek: " << q1.Peek() <<endl;


    q1.push(50);
    q1.display();
    cout << "\nPeek: " << q1.Peek() <<endl;

    q1.pop();
    q1.pop();
    q1.display();
    cout << "\nPeek: " << q1.Peek() <<endl;

    q1.pop();
    q1.display();
    cout << "\nPeek: " << q1.Peek() <<endl;

    q1.push(60);
    q1.display();
    cout << "\nPeek: " << q1.Peek() <<endl;
}
