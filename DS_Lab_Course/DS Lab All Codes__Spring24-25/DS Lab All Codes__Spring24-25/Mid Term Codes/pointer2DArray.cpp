#include <iostream>
using namespace std;

int main ()
{
    int array[3][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int *ptr;
    ptr = &array[0][0];

    for(int i = 0; i <3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout << *ptr << " ";
            ptr++;
        }
        cout <<endl;
    }
}
