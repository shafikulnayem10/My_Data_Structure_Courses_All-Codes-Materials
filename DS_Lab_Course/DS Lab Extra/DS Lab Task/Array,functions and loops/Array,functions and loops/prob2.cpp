#include<iostream>
using namespace std;
int main(){
    int a[10] = {12,34,56,43,26,56,78,41,22,10};
    int odd=0,even=0;
    cout<<"Array : ";for(int i=0;i<10;i++)cout<<a[i]<<" ";
    for(int i=0;i<10;i++){
        if(a[i]%2==0) even++;
        else odd++;
    }
    cout<<"\nEven Numbers : "<<even<<endl;
    cout<<"Odd numbers : "<<odd<<endl;
    

}