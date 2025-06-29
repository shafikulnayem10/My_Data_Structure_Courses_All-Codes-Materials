#include <iostream>
using namespace std;

struct Student {
    string id;
    string name;
    float quizzes[3];
};

int main() {
    int NUM_STUDENTS = 2;
    Student students[NUM_STUDENTS];
    float averages[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter details for student " << i+1 << ":\n";
        cout << "ID: "; cin >> students[i].id;
        cout << "Name: "; cin.ignore();
        getline(cin, students[i].name);
        for (int j = 0; j < 3; j++) {
            cout << "Enter marks for Quiz " << j+1 << ": ";
            cin >> students[i].quizzes[j];
        }
    }

    cout << "\nAverage of best two quizzes:\n";

    cout << "ID\tName\t\tAverage\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        float sum = 0;
        float min_mark = students[i].quizzes[0];

        for (int j = 0; j < 3; j++) {
            sum += students[i].quizzes[j];
            if (students[i].quizzes[j] < min_mark) {
                min_mark = students[i].quizzes[j];
            }
        }

        averages[i] = (sum - min_mark) / 2;
        cout << students[i].id << "\t" << students[i].name << "\t" << "\t" <<averages[i] << endl;
    }

    cout << "\nStudents who scored more than their average in at least one quiz:\n";

    for (int i = 0; i < NUM_STUDENTS; i++) {
        for (int j = 0; j < 3; j++) {
            if (students[i].quizzes[j] > averages[i]) {
                cout << students[i].id << "\t" << students[i].name << endl;
                break;
            }
        }
    }

    return 0;
}

