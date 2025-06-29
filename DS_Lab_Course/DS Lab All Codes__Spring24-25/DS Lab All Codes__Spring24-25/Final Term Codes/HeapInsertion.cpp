#include <iostream>
using namespace std;

class MaxHeap
{
public:

    int heap[100];
    int currentSize = 0;

    void insert(int value)
    {
        currentSize++;
        heap[currentSize] = value;
        int index = currentSize;

        while(index > 1 && heap[index] > heap[index/2])
        {
            swap(heap[index] , heap[index/2]);
            index = index/2;
        }
    }
};

int main()
{
    MaxHeap h;
    int n, value;
    cout << "Number of Array Elements: ";
    cin>> n;
    for(int i = 0; i<n; i++)
    {
        cout << "Enter element " << i+1 << " : ";
        cin>> value;
        h.insert(value);
    }
    cout << "Max Heap Elements: ";
    for(int i = 1; i <= n; i++)
    {
        cout << h.heap[i] << " ";
    }
}

