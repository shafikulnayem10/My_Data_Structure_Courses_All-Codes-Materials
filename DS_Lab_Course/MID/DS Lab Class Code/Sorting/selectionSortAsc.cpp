#include<iostream>
using namespace std;

int main(){
int arr[5];
for(int i=0;i<5;i++){

    cout<<"enter A["<<i+1<<"]"<<endl;
    cin>>arr[i];
}
for(int i=0;i<5;i++){
    int small=i;
    for(int j=i+1;j<5;j++){
        if(arr[j]<arr[small]){
            small=j;

        }
        int temp=arr[i];
        arr[i]=arr[small];
        arr[small]=temp;
    }
}

cout<<"after sorting:"<<endl;


for(int i=0;i<5;i++){


    cout<<arr[i]<<" ";
}


}
