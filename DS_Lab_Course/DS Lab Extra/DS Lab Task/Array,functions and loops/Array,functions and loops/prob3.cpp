#include<iostream>
using namespace std;
void print(int s,int e){
    cout<<"starting value : "<<s<<endl;
    cout<<"Ending value : "<<e<<endl;
    for(int i=s;i<=e;i++){
        if(i%2!=0)cout<<" "<<i;
    }
}
int main(){
int s,e;cin>>s>>e;
print(s,e);

}