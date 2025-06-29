#include <iostream>
using namespace std;


int linearSearch (int arr[], int target, int size)
{
    for(int i = 0; i <size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}


int main ()
{
    int arr [10] = {1,2,3,4,5,6,7,8,9,10};
    int size = 10;
    int target = 777;

    cout << linearSearch(arr, target, size);

    return 0;
}
