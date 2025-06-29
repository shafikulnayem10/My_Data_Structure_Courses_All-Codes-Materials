#include<iostream>
using namespace std;
bool isprime(int s){
    int c=0;
    for(int i=2;i<s;i++){
        if(s%i==0)c++;
    }
    if(c==0) return true;
    else return false;
}
void factorial(int s){
    int f=1;
    for(int i=s;i>=1;i--){
        f = f*i;
    }
    cout<<f<<endl;
}
int main(){
int s;cin>>s;
bool prime = isprime(s);
if(prime) {factorial(s);}
else cout<<"\nError"<<endl;
}