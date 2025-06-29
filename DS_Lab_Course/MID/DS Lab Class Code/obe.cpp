#include<iostream>
using namespace std;

struct student{
string name;
int roll;
int marks[2];


};

int main(){
student s1[3];
for(int i=0;i<3;i++){
    cout<<"enter name"<<endl;
    cin.ignore();
    getline(cin,s1[i].name);
    cout<<"enter roll"<<endl;
    cin>>s1[i].roll;
    cout<<"enter 3 marks"<<endl;
    for(int j=0;j<2;j++){
        cin>>s1[i].marks[j];

    }


}




}
