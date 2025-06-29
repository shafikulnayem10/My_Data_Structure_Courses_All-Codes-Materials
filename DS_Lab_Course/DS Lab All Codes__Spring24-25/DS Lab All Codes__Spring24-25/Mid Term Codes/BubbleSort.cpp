#include<iostream>
using namespace std;

int BubbleSort (int array[], int ESize)
{
    for (int i = 0; i < ESize - 1 ; i++) // traverse each pass
    {
        for (int j = 0; j < ESize - 1; j++) //compare each element
        {
            if(array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
            }
        }
    }
}

int main ()
{
    //int array[] = {8,5,7,3,2};
    int array[] = {8,17,5,7,13,21,27,24,2,4};
    int ESize = sizeof(array)/sizeof(int);
    cout << "Unsorted Main Array: ";
    for (int i = 0; i < ESize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    BubbleSort(array, ESize);
    cout << "Sorted Array (Bubble Sort): ";
    for (int i = 0; i < ESize; i++)
    {
        cout << array[i] << " ";
    }
}
