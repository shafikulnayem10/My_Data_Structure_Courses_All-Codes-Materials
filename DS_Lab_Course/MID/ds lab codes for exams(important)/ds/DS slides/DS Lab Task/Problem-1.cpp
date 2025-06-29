#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    int i,j,temp,flag;

    for(i=0;i<n-1;i++)
    {
        flag=0;

        for(j=0;j<n-1-i;j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }

        if (flag==0)
        {
            break;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    bubble_sort(arr,n);

    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
