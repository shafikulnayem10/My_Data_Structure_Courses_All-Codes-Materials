#include<iostream>
using namespace std;
int s_sort(int a[],int n){
for(int i=0;i<n,i++){
    key=a[i];
    j=i-1;
    while(j>=0&&a[j]>key){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=key;
}
}
int bi_s(int a[],int n,int t)
{
    int start = 0;
    int end1 = n - 1;

    while(start <= end1)
    {
        int mid = (start + end1) /2;
        if(a[mid] == t)
        {
            return mid;
        }
        else if (a[mid] < t)
        {
            start = mid + 1;
        }
        else
        {
            end1 = mid - 1;
        }
    }
    return - 1;
}

int main(){

int arr[3]={4,5,80};
s_sort(arr,3);
int target=5;
int result = bi_s(arr,3,target);

    if(result == -1)
    {
        cout << target<< " is not found in the array" <<endl;
    }
    else
    {
        cout << target << " is found at index: " << result <<endl;
    }
    return 0;

}
