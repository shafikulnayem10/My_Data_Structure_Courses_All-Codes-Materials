
//question: "There are 40 students in a course. They have marks of three quizzes. Find out the average marks of the best two quizzes of each student."
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string id;
    string name;
    float quizes[3];
};



int main() {
    const int NUM_STUDENTS = 2;
    Student students[NUM_STUDENTS];
    int avg[2];

    // Input student data
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter details for student " << i+1 << ":\n";
        cout << "ID: "; cin >> students[i].id;
        cout << "Name: "; cin.ignore();
        getline(cin, students[i].name);
       for(int j=0;j<3;j++){
        cout<<"enter number for quiz-"<<j+1<<endl;
        cin>>students[i].quizes[j];


       }
    }

    // Calculate and display average of best two quizzes
    cout << "\nAverage of best two quizzes:\n";
    cout << "ID\tName\t\tAverage\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
       int sum=0;

      int min_marks=students[i].quizes[0];
       for(int j=0;j<3;j++){
            sum=sum+students[i].quizes[j];
        if(students[i].quizes[j]<min_marks){
            min_marks=students[i].quizes[j];
        }
        avg[i]=(sum-min_marks)/3;


       }

        cout << students[i].id << "\t" << students[i].name << "\t" << avg[i]<< endl;
        cout<<endl;
    }

        cout<<"student how got more marks than avg"<<endl;
        int k=0;
       for (int i = 0; i < NUM_STUDENTS; i++){

           for(int j=0;j<3;j++){
           if(students[i].quizes[j]>avg[i]){
               k=i;

           }
       }
       }

    cout << students[k].id << "\t" << students[k].name;




    return 0;
}
