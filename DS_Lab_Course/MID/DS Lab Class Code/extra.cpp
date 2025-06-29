#include<iostream>
using namespace std;
int main(){

int arr[4][3];
for(int i=0;i<4;i++){
    for(int j=0; j<3;j++){
        cout<<"enter element for A["<<i<<"]"<<"["<<j<<"]"<<endl;
        cin>>arr[i][j];

    }

}
cout<<"orginal array:"<<endl;
for(int i=0;i<4;i++){
    for(int j=0 ;j<3;j++){
        cout<<"enter element for A["<<i<<"]"<<"["<<j<<"]"<<endl;
        cin>>arr[i][j];

    }

}
int B[3][4];

cout<<"trasnpose array"<<endl;
for(int i=0;i<4;i++){
    for(int j=0; j<3;j++){
       B[j][i]=A[i][j];


    }

}
cout<<"transpose array :"<<endl;

for(int i=0;i<3;i++){
    for(int j=0; j<4;j++){
            cout<<B[i][j];


}
