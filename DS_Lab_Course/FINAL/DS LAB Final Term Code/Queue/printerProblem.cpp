#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Job {
    int jobID;
    string fileName;
    int pageCount;
};

class CircularQueue {
    Job queue[SIZE];
    int front, rear;
    int count;

public:
    CircularQueue() {
        front = rear = 0;
        count = 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int jobID, const string& fileName, int pageCount) {
        if (isFull()) {
            cout << "Queue full. Cannot add job.\n";
            return;
        }


        queue[rear].jobID = jobID;
        queue[rear].fileName = fileName;
        queue[rear].pageCount = pageCount;

        rear = (rear + 1) % SIZE;
        count++;

        cout << "Job added.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No jobs to process.\n";
            return;
        }

        Job j = queue[front];
        cout << "Processing Job " << j.jobID << ": " << j.fileName << " (" << j.pageCount << " pages)\n";

        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No jobs in queue.\n";
            return;
        }

        cout << "Current jobs in queue:\n";
        int idx = front;
        for (int i = 0; i < count; ++i) {
            Job j = queue[idx];
            cout << j.jobID << " - " << j.fileName << " (" << j.pageCount << " pages)\n";
            idx = (idx + 1) % SIZE;
        }
    }
};

int main() {
    CircularQueue printer;
    printer.enqueue(101, "report.pdf", 5);
    printer.enqueue(102, "invoice.docx", 2);
    printer.display();

    printer.dequeue();
    printer.display();

    return 0;
}

