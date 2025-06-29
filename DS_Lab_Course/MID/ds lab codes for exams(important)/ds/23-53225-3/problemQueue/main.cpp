#include <iostream>
using namespace std;

class CircularQueue {
private:
    int frontIdx, rearIdx, maxSize, count;
    int* elements;

public:
    CircularQueue(int s) {
        maxSize=s;
        frontIdx=rearIdx=-1;
        count=0;
        elements=new int[maxSize];
    }

    bool isFull() {
        return count==maxSize;
    }

    bool isEmpty() {
        return count== 0;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rearIdx=(rearIdx + 1)%maxSize;
        elements[rearIdx]=val;
        count++;
        if (frontIdx==-1) frontIdx= 0;
        cout<<val<<" added to the queue"<<endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout<<elements[frontIdx]<<" removed from the queue"<<endl;
        frontIdx= (frontIdx + 1) % maxSize;
        count--;
        if (count== 0) {
            frontIdx = rearIdx = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout<<elements[(frontIdx + i) % maxSize] << " ";
        }
        cout<<endl;
    }

    void search(int val) {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            if (elements[(frontIdx + i) % maxSize] == val) {
                cout<<val<<" found at index "<<(frontIdx + i) % maxSize<<endl;
                return;
            }
        }
        cout<<"Value not found in the queue"<<endl;
    }

    void update(int idx, int newVal) {
        if (idx >= 0 && idx < count) {
            elements[(frontIdx + idx) % maxSize] = newVal;
            cout<<"Updated value at index "<<idx<<" to "<<newVal<<endl;
        } else {
            cout<<"Invalid index"<<endl;
        }
    }

    int size() {
        return count;
    }

    ~CircularQueue() {
        delete[] elements;
    }
};

int main() {
    int queueSize;
    cout<<"Enter the size of the queue: ";
    cin>>queueSize;

    CircularQueue q(queueSize);

    int choice,value,idx;
    do {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Check Queue Overflow"<<endl;
        cout<<"5. Check Queue Underflow"<<endl;
        cout<<"6. Show number of elements in the queue"<<endl;
        cout<<"7. Search an element"<<endl;
        cout<<"8. Update value at index"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            cout<<"Enter value to enqueue: ";
            cin>>value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            if (q.isFull()) {
            cout<<"Queue is full"<<endl;
            } else {
            cout<<"Queue is not full"<<endl;
            }
            break;

        case 5:
            if (q.isEmpty()) {
            cout<<"Queue is empty"<<endl;
            } else {
            cout<<"Queue is not empty"<<endl;
            }
            break;

        case 6:
            cout<<"Number of elements in queue: "<<q.size()<<endl;
            break;
        case 7:
            cout<<"Enter value to search: ";
            cin>>value;
            q.search(value);
            break;
        case 8:
            cout<<"Enter index to update: ";
            cin>>idx;
            cout<<"Enter new value: ";
            cin>>value;
            q.update(idx,value);
            break;
        case 9:
            cout<<"Exiting..."<<endl;
            break;
        default:
            cout<<"Invalid choice, please try again."<<endl;
        }
    } while (choice!=9);

    return 0;
}
