#include <iostream>
#include <cmath>
using namespace std;
int main() {
     int s = 10;
    int c[s] = {0};
    c[3] = 100;
    c[7] = -57;
    for (int i = 0;i<s;i++) {
            cout<<cos(c[i]) << endl;
    }
}
