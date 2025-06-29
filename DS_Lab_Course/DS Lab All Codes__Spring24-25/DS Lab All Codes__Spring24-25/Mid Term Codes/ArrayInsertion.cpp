#include <iostream>
using namespace std;

int main ()
{
    int arr [50] = {1,2,3,4,5};
    int size = 5;

    cout <<"Main Array: ";
    for(int i = 0; i <size; i++)
    {
        cout << arr[i] << " ";
    }

    //insert at last index
    arr[size] = 11;
    size++;
    cout <<endl;
    cout <<"Insert at last index: ";
    for(int i = 0; i <size; i++)
    {
        cout << arr[i] << " ";
    }

    cout <<endl;
    for(int i = size; i>0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = 17;
    size++;
    cout <<"Insert at first index: ";
    for(int i = 0; i <size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

