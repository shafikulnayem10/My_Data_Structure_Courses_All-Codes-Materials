#include <iostream>
using namespace std;

int binarySearch(int array[], int ESize, int search)
{
    int start = 0;
    int end = ESize - 1;

    while(start <= end)
    {
        int mid = (start + end) / 2;
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
    return -1;
}

int main ()
{

  int ESize, search;
  cout << "Enter array element size: ";
  cin >> ESize;
  int array[ESize];
  cout << "Add " << ESize << " array elements: " <<endl;
  for(int i = 0; i < ESize; i++)
  {
      cin >> array[i];
  }
  cout << "Enter the number you want to search: ";
  cin >> search;
  cout << endl;
  cout << "Main Array: ";
  for(int i = 0; i < ESize; i++)
  {
      cout << array[i] << " ";
  }

  cout << endl;
  int result = binarySearch(array, ESize, search);
  if(result == -1)
  {
      cout << "Element " << search << " is not found" << endl;
  }
  else
  {
      cout << "Element " << search << " is found at index: " << result << endl;
  }

  return 0;
}

