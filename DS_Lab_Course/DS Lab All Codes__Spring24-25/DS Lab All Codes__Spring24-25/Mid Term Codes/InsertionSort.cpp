#include<iostream>
using namespace std;

int InsertionSort (int array[], int ESize)
{
    for (int i = 1; i < ESize ; i++) // traverse each pass
    {
        int element = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > element) // check each element
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = element;
    }
}

int main ()
{
    int array[] = {2,14,9,4,5,51,6};
    int ESize = sizeof(array)/sizeof(int);
    cout << "Unsorted Main Array: ";
    for (int i = 0; i < ESize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    InsertionSort(array, ESize);
    cout << "Sorted Array (Insertion Sort): ";
    for (int i = 0; i < ESize; i++)
    {
        cout << array[i] << " ";
    }
}
