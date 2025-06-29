#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class TextEditorStack {
    string stack[MAX];
    int top;

public:
    TextEditorStack() {
        top = -1;
    }

    void push(const string& text) {
        if (top == MAX - 1) {
            cout << "Stack is full. Cannot add more text.\n";
            return;
        }
        stack[++top] = text;
        cout << "Text added.\n";
    }

    void undo() {
        if (top == -1) {
            cout << "Nothing to undo.\n";
            return;
        }
        cout << "Undo: \"" << stack[top--] << "\" removed.\n";
    }

    void show() {
        cout << "Current content (latest on top):\n";
        for (int i = top; i >= 0; --i) {
            cout << stack[i] << endl;
        }
    }
};

int main() {
    TextEditorStack editor;
    editor.push("Hello");
    editor.push("World");
    editor.show();

    editor.undo();
    editor.show();

    return 0;
}
