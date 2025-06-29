#include <iostream>
#include <cstring>
using namespace std;

struct Customer {
    int CID;
    string CName;
    int Age;
    string Address;
    string City;
};

int main() {
    int numOfcustomers = 4;
    Customer customers[numOfcustomers];

    for (int i=0;i<numOfcustomers;i++) {
        cout<<"Enter details for customer "<<i+1<< ":\n";

        cout<<"Customer ID: ";
        cin>>customers[i].CID;

        cout<<"Customer Name: ";
        cin.ignore();
        getline(cin,customers[i].CName);

        cout<<"Age: ";
        cin>>customers[i].Age;

        cout<<"Address: ";
        cin.ignore();
        getline(cin, customers[i].Address);

        cout<<"City: ";
        getline(cin, customers[i].City);

        cout<<endl;

    }

    cout<<"Prize winners (age not more than 30):\n";
    for (int i=0;i<4;i++) {
        if (customers[i].Age<=30) {
            cout<<"Customer ID: " <<customers[i].CID<<endl;
            cout<<"Customer Name: " <<customers[i].CName<<endl;
            cout<<"Age: "<<customers[i].Age<<endl;
            cout<<"Address: "<< customers[i].Address<<endl;
            cout<<"City: "<<customers[i].City<<endl;
            cout<<endl;
        }
    }

    return 0;
}
