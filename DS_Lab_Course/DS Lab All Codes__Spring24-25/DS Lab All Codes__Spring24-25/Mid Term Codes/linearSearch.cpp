#include <iostream>
using namespace std;

int linerSearch (int array[], int ESize, int search)
{
    for(int i = 0; i < ESize; i++)
    {
        if(array[i] == search)
        {
            return i;
        }
    }
    return -1;
}

int main ()
{

  int array[10] = {1,2,3,4,5,6};
  int ESize = 6;
  int search = 55;

  int result = linerSearch (array, ESize, search);
  if(result == -1)
  {
      cout << "Element " << search << " is not found" <<endl;
  }
  else
  {
      cout << "Element " << search << " is found at index: " << result <<endl;
  }

  return 0;
}


