#include<iostream>
using namespace std;

struct student{
int marks;
int roll;
string name;


};

int main(){

student s[3];

for(int i=0;i<3;i++){
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, s[i].name);
        cout << "Enter roll: ";
        cin >> s[i].roll;
        cout << "Enter marks: ";
        cin >> s[i].marks;

}
student h = s[0];

  for (int i = 1; i < 3; i++) {
        if (s[i].marks > h.marks) {
            h = s[i];
        }
    }
cout<<"highest mark is"<<h.marks;



}
