#include <iostream>
using namespace std;
int main(){

int max_size=1000;
int og_size=12;
int id_List[max_size] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 123};

cout << "Initial list: ";
for (int i = 0; i < og_size; i++) {
        cout << id_List[i] << " ";
    }

cout << endl;

if (og_size < max_size) {

        for (int i = og_size; i > 0; i--) {
            id_List[i] = id_List[i - 1];
        }
        id_List[0] = 180;
        og_size++;

        cout << "After insert at the  beginning: ";
        for (int i = 0; i < og_size; i++) {
            cout << id_List[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Array is full.can not insert" << endl;
    }


   if (og_size <max_size) {
        id_List[og_size] = 126;
        og_size++;

        cout << "After insert at the end : ";
        for (int i = 0; i < og_size; i++) {
            cout << id_List[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Array is full. Can not insert" << endl;
    }



       if (og_size < max_size) {
        int mid = og_size / 2;


        for (int i = og_size; i > mid; i--) {
            id_List[i] = id_List[i - 1];
        }
        id_List[mid] = 501;
        og_size++;

        cout << "After insert at the middle: ";
        for (int i = 0; i < og_size; i++) {
            cout << id_List[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Array is full. Can not insert at the middle." << endl;
    }



    if (og_size > 0) {

        for (int i = 0; i < og_size - 1; i++) {
            id_List[i] = id_List[i + 1];
        }
        og_size--;

        cout << "After delete from the beginning: ";
        for (int i = 0; i < og_size ; i++) {
            cout << id_List[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Array is empty. Cannot delete from the beginning." << endl;
    }

    int delPos = 3;
    if (og_size > 0 && delPos >= 0 && delPos < og_size) {

        for (int i = delPos; i < og_size - 1; i++) {
            id_List[i] = id_List[i + 1];
        }
        og_size--;

        cout << "After delete from the position " << delPos << ": ";
        for (int i = 0; i < og_size; i++) {
            cout << id_List[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid position " << endl;
    }


    cout << "Final list in reverse order: ";
    for (int i = og_size - 1; i >= 0; i--) {
        cout << id_List[i] << " ";
    }
    cout << endl;


    cout<<"finding my id and large element :"<<endl;
     int myID = 123;
    int myIDIndex = -1;
    int largest = id_List[0];


    for (int i = 0; i < og_size; i++) {
        if (id_List[i] == myID) {
            myIDIndex = i;
        }
        if (id_List[i] > largest) {
            largest = id_List[i];

        }
    }

    if (myIDIndex != -1) {
        cout << "MY ID (" << myID << ")  at index: " << myIDIndex << endl;
    }
     else {
        cout << "MY ID (" << myID << ") is not found ." << endl;
    }

    cout << "Largest element is:" << largest << endl;



}


