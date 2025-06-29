#include<iostream>
using namespace std;
int main(){
    int a[10] = {12,34,56,43,26,56,78,41,22,10};
    cout<<"Normal Array : ";
    for(int i=0;i<10;i++) cout<<" "<<a[i];
    cout<<"\nReverse Array : ";
        for(int i=9;i>=0;i--) cout<<" "<<a[i];
}