
#include<iostream>
using namespace std;
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
void bubblesort(int a[],int  n){
for(int i=0; i<n-1;i++){
    for(int j=0; j<n-1; j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);

        }
    }
}
}
int main(){

int arr[3]={5,4,7};
bubblesort(arr,3);
cout<<"after sorting"<<endl;

for(int i=0 ;i<3;i++){
    cout<<arr[i];
}
cout<<endl;
cout<<"target finding"<<endl;

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


}
