#include<iostream>
using namespace std;

struct stud {
    string name;
    int roll;
    int marks[5];
};

int main() {
    stud student;
    int total_marks = 0;
    float average_marks = 0.0;

    cout << "Enter student name: ";
    getline(cin, student.name);

    cout << "Enter student roll number: ";
    cin >> student.roll;

    cout << "Enter marks for 5 subjects: " << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Subject " << (i+1) << ": ";
        cin >> student.marks[i];
        total_marks += student.marks[i];
    }

    average_marks = (float)(total_marks) / 5;

    cout << "Student Details:" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.roll << endl;
    cout << "Total Marks: " << total_marks << endl;
    cout << "Average Marks: " << average_marks << endl;

    return 0;
}
