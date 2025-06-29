#include<iostream>
using namespace std;


int reverseString(String& input){

int l=input.length();
for(int i=0;i<l/2;i++){
    swap(input[i],input[l-i-1]);

}

}
int main(){
 string input;
 cout<<"enter input"<<endl;
 getline(cin,input);
reverseString(input)
 cout<<"reversed"<<input;




}
