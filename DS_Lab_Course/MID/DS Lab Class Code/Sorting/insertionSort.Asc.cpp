#include<iostream>
using namespace std;

int main(){
int arr[5];
for(int i=0;i<5;i++){

    cout<<"enter A["<<i+1<<"]"<<endl;
    cin>>arr[i];
}
for(int i=1;i<5;i++){
    int key= arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;

    }
    arr[j+1]=key;

}
cout<<"after sorting:"<<endl;


for(int i=0;i<5;i++){


    cout<<arr[i]<<" ";
}

}
