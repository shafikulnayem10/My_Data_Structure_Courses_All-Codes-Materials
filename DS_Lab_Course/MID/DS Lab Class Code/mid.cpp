#include <iostream>
using namespace std;

struct Student {
    string name;
    string rollNumber;
    int marks;
};


void sortStudents(Student students[], int n) {
    for (int i = 1; i < n; i++) {

        Student key = students[i];
        int j = i - 1;


        while (j >= 0 && (students[j].marks > key.marks ||(students[j].marks == key.marks && students[j].name > key.name))) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

int main() {
  int SIZE = 3;
    Student students[SIZE];


    for (int i = 0; i < SIZE; i++) {

        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Marks : ";

        cin >> students[i].marks;


    }


    sortStudents(students, SIZE);


    cout << "\nStudent Details :\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Name: " << students[i].name<< ", Roll No: " << students[i].rollNumber<<",marks:"<< students[i].marks;

    }


    cout << "\nSorted Marks: ";
      for (int i = 0; i < SIZE; i++) {

        cout<< students[i].marks<<" ";
        }

      }

    cout << "Lowest Marks: " << students[0].marks << endl;
    cout << "Highest Marks: " << students[SIZE - 1].marks << endl;

    return 0;
}


