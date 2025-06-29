#include<iostream>
using namespace std;
int main(){

  int row;
  int col;
 cout<<"input"<<endl;
 cout<<"number of rows"<<endl;
 cin>>row;
 cout<<"number of cols"<<endl;
 cin>>col;
  int array [row][col];
  for(int i=0;i<row;i++){
    for(int j=0 ; j<col;j++){
        cout<<"Element ["<<i<<"]["<<j<<"] :";
        cin>>array[i][j];

    }
    cout<<endl;

  }
  cout<< "output array:"<<endl;
  for(int i=0;i<row;i++){
    for(int j=0 ; j<col;j++){
        cout<<array[i][j]<<" ";

    }
    cout<<endl;


  }
  cout<<"traspose array:"<<endl;
  for(int j=0;j<col;j++){
    for(int i=0 ; i<row;i++){
        cout<<array[i][j]<<"";

    }
    cout<<endl;

  }

  cout<<"array searching"<<endl;

  int target =10;

  for(int i=0;i<row;i++){
    for(int j=0 ; j<col;j++){
      if(array[i][j]==target){

        cout<< "Element"<<target<<"found at index["<<i<<"]["<<j<<"]";
         return 1;

      }

    }
  }
  cout<<"Element"<<target<<"is not found"<<endl;
 return 0;
cout<<"max elemnet:"<<endl;
 int max1=array[0][0];

for(int i=0;i<row;i++){
    for(int j=0 ; j<col;j++){

        if(array[i][j]>max1){
                max1=array[i][j];
               cout<< " Max Element"<<max1<<"found at index["<<i<<"]["<<j<<"]";

        }

    }
}
if(max1%2==0){
    cout<<max1<<" is even";
}
else{
    cout<<max1<<"is odd";
}


}
