#include <iostream>
using namespace std;

int linearSearch(int array[], int ESize, int search)
{
    for(int i = 0; i < ESize; i++)
    {
        if(array[i] == search)
        {
            cout << "Element " << search << " was found in index: " << i <<endl;
            return i;
        }

    }
    cout << "Element not found";
    return -1;
}

int main ()
{
    int array[10] = {1,2,3,4,5,6};
    int ESize = 6;
    int search = 33;
    linearSearch(array, ESize, search);
}

