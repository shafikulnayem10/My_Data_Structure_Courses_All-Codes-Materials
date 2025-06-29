#include<iostream>
using namespace std;
int main() {
    int a[10] = {3,4,2,1,2,6,2,2,9};  
    cout<<"\nEnter the element to search : ";
int n,c=0;cin>>n;
for(int i=0;i<10;i++){
    if(a[i] == n) {
        c++;
    }
}
  cout<<"The number occurs "<<c<<" times"<<endl;  
}
