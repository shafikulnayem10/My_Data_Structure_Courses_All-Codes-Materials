#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeatingChar(string stream) {
    int freq[256] = {0};
    queue<char> q;

    for (char ch : stream) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
}

int main() {
    string stream = "bbcd";
    cout << "Stream: " << stream << endl;
    cout << "Output : ";
    firstNonRepeatingChar(stream);
    return 0;
}

