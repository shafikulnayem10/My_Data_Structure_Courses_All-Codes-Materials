#include<iostream>
using namespace std;
int main(){
    int a[5] = {3,4,5,1,2};
        int b[3] = {8,3,9};
        int c[sizeof(a)+sizeof(b)];
        for(int i=0;i<5;i++){
            c[i] = a[i];
        }
         for(int i=5,j=0;i<8,j<3;i++,j++){
            c[i] = b[j];
        }
        cout<<"\nMerged Array : ";
        for(int i=0;i<8;i++){
            cout<<" "<<c[i];
        }
    
}