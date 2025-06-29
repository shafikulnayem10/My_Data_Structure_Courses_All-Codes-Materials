#include <iostream>
using namespace std;

int main() {
    int residency[50]; 
    int insideDhaka = 0, outsideDhaka = 0;

    for (int i = 0; i < 50; i++) {
        if (i<45) { 
            residency[i] = 1;
            insideDhaka++;
        } else { 
            residency[i] = 0;
            outsideDhaka++;
        }
    }

    float averageInsideDhaka = insideDhaka/50.00; 

    cout << "Average number: " << averageInsideDhaka << endl;

    return 0;
}
