#include <iostream>
using namespace std;


int reverseArray (int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    for (int i = 0; i < size; i++)
    {
        if (start < end)
        {
            swap(arr[start], arr[end]);
            start ++;
            end--;
        }
    }
}


int main ()
{
    int arr [10] = {1,2,3,4,5,6,7,8,9,10};
    int size = 10;

    cout << "Main Array: ";
    for(int i = 0; i < size; i++)
    {
        cout <<arr[i] << " ";
    }

    cout <<endl;

    cout << "Reverse Array: ";
    reverseArray(arr, size);
    for(int i = 0; i < size; i++)
    {
        cout <<arr[i] << " ";
    }

    cout <<endl;
    cout <<endl;


    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);

    cout <<size1<<endl;
    cout <<size1<<endl;


    return 0;
}

