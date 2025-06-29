#include<iostream>
using namespace std;

int binarySearch(int array[], int ESize, int search)
{
    int start = 0;
    int end = ESize - 1;

    while(start <= end)
    {
        int mid = (start + end) /2;
        if(array[mid] == search)
        {
            return mid;
        }
        else if (array[mid] < search)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return - 1;
}

int main ()
{
    int ESize, search;
    cout << "Enter Array Size: ";
    cin >> ESize;

    int array[ESize];

    cout << "Enter Array " << ESize << " Elements " <<endl;
    for (int i = 0; i <ESize; i++)
    {
        cin >> array[i];
    }
    cout << "Enter Search Element: ";
    cin >> search;

    int result = binarySearch(array, ESize, search);
    if(result == -1)
    {
        cout << search << " is not found in the array" <<endl;
    }
    else
    {
        cout << search << " is found at index: " << result <<endl;
    }
    return 0;
}

