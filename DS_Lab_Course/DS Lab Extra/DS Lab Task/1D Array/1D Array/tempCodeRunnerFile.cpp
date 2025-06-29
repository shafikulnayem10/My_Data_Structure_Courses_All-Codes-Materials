#include <iostream>
using namespace std;
int main() {
    int a[10] = {8,4,6,1,6,9,6,1,9,8},n = 10, a2[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < n; i++) {
        if (a2[i]) continue;
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                a2[j] = 1;
            }
        }
        cout<<a[i]<<" occurs "<<count<<" times"<<endl;
    }
}
