#include <iostream>
using namespace std;

int linearSearch (int arr[], int value, int size)
{
    for(int i = 0; i<size; i++)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}


int main ()
{
    int arr [5] = {1,2,3,4,5};
    int value = 33;
    int size = 5;
    cout << linearSearch(arr, value, size);
    return 0;
}
