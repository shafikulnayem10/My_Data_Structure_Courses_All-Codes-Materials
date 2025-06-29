#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Passenger {
    string name;
    string passport;
    int baggage;
    Passenger* prev;
    Passenger* next;
};

Passenger* head = nullptr;
Passenger* tail = nullptr;

Passenger* undoStack[100];
int undoTop = -1;

void AddPassenger(string name, string passport, int baggage) {
    Passenger* p = new Passenger{name, passport, baggage, nullptr, nullptr};

    if (!head) head = tail = p;
    else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }

    undoStack[++undoTop] = p;

    cout << "Passenger Added: " << name << "\nPassport: " << passport << "\nBaggage: " << baggage << "kg\n\n";
}

void DisplayPassengersForward() {
    Passenger* temp = head;
    cout << "Passenger Linked List (Forward):\n";
    while (temp) {
        cout << "(" << temp->name << " | " << temp->passport << " | " << temp->baggage << "kg)";
        if (temp->next) cout << " - ";
        temp = temp->next;
    }
    cout << "\n\n";
}

void UndoLastCheckin() {
    if (undoTop == -1) {
        cout << "No check-in to undo.\n\n";
        return;
    }

    Passenger* p = undoStack[undoTop--];
    cout << "Undo Last Check-in\nRemoved: " << p->name << " | Passport: " << p->passport << " | Baggage: " << p->baggage << "kg\n\n";

    if (p->prev) p->prev->next = p->next;
    if (p->next) p->next->prev = p->prev;
    if (p == head) head = p->next;
    if (p == tail) tail = p->prev;
    delete p;
}

struct Flyer {
    int id;
    string name;
    int flights;
    Flyer* left;
    Flyer* right;
};

Flyer* flyerRoot = nullptr;

Flyer* InsertFlyer(Flyer* root, int id, string name, int flights) {
    if (!root) {
        Flyer* newNode = new Flyer{id, name, flights, nullptr, nullptr};
        cout << "Frequent Flyer Inserted: ID " << id << " | Name: " << name << " | Flights: " << flights << "\n\n";
        return newNode;
    }
    if (id < root->id) root->left = InsertFlyer(root->left, id, name, flights);
    else if (id > root->id) root->right = InsertFlyer(root->right, id, name, flights);
    return root;
}

void InOrderFlyers(Flyer* root) {
    if (!root) return;
    InOrderFlyers(root->left);
    cout << "ID: " << root->id << " | " << root->name << " | Flights: " << root->flights << "\n";
    InOrderFlyers(root->right);
}

const int MAX_TERMINALS = 20;
char terminals[MAX_TERMINALS][10];
int terminalCount = 0;
int adjList[MAX_TERMINALS][MAX_TERMINALS];
int connectionCount[MAX_TERMINALS] = {0};

int getTerminalIndex(const char* name) {
    for (int i = 0; i < terminalCount; i++) {
        if (strcmp(terminals[i], name) == 0) return i;
    }
    return -1;
}

void AddTerminal(const char* name) {
    if (getTerminalIndex(name) != -1) {
        cout << "Terminal " << name << " already exists.\n";
        return;
    }
    strcpy(terminals[terminalCount++], name);
    cout << "Terminal Added: " << name << "\n";
}

void ConnectTerminals(const char* t1, const char* t2) {
    int i1 = getTerminalIndex(t1);
    int i2 = getTerminalIndex(t2);

    if (i1 == -1 || i2 == -1) {
        cout << "One or both terminals not found.\n";
        return;
    }

    adjList[i1][connectionCount[i1]++] = i2;
    adjList[i2][connectionCount[i2]++] = i1;
    cout << "Connection Added: " << t1 << " <-> " << t2 << "\n";
}

void DisplayTerminalConnections() {
    cout << "\nTerminal Connections (Adjacency List):\n";
    for (int i = 0; i < terminalCount; i++) {
        cout << terminals[i] << " ->";
        for (int j = 0; j < connectionCount[i]; j++) {
            cout << terminals[adjList[i][j]];
            if (j < connectionCount[i] - 1) cout << ", ";
        }
        cout << "\n";
    }
    cout << "\n";
}

char opStack[100];
int opTop = -1;

void pushOp(char ch) { opStack[++opTop] = ch; }
char popOp() { return opStack[opTop--]; }
char topOp() { return opStack[opTop]; }
bool isEmptyOp() { return opTop == -1; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

void reverseString(string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - 1 - i]);
}

string infixToPrefix(string infix) {
    reverseString(infix);
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    string result = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            pushOp(c);
        }
        else if (c == ')') {
            while (!isEmptyOp() && topOp() != '(') {
                result += popOp();
            }
            if (!isEmptyOp()) popOp();
        }
        else {
            while (!isEmptyOp() && precedence(topOp()) >= precedence(c)) {
                result += popOp();
            }
            pushOp(c);
        }
    }

    while (!isEmptyOp()) {
        result += popOp();
    }

    reverseString(result);
    return result;
}

int evaluatePrefix(string prefix, int weight, int discount) {
    int stack[100], top = -1;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            if (c == 'W') stack[++top] = weight;
            else if (c == 'D') stack[++top] = discount;
            else stack[++top] = c - '0';
        }
        else {
            int a = stack[top--];
            int b = stack[top--];
            int res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            else if (c == '^') {
                res = 1;
                for (int j = 0; j < b; j++) res *= a;
            }
            stack[++top] = res;
        }
    }
    return stack[top];
}

void CalculateCharge(string expr, int weight, int discount) {
    cout << "Charge Expression: " << expr << "\n";
    string prefix = infixToPrefix(expr);
    cout << "Prefix Expression: " << prefix << "\n";
    cout << "Values: Weight = " << weight << ", Discount = " << discount << "\n";
    int result = evaluatePrefix(prefix, weight, discount);
    cout << "Final Charge: " << result << "\n\n";
}

int main() {
    AddPassenger("Alice", "P12345", 18);
    AddPassenger("Bob", "P67890", 30);
    DisplayPassengersForward();

    UndoLastCheckin();
    DisplayPassengersForward();

    flyerRoot = InsertFlyer(flyerRoot, 101, "Alice", 12);
    flyerRoot = InsertFlyer(flyerRoot, 105, "Bob", 8);
    cout << "In-order Traversal of Frequent Flyers:\n";
    InOrderFlyers(flyerRoot);
    cout << "\n";

    AddTerminal("T1");
    AddTerminal("T2");
    AddTerminal("T3");
    ConnectTerminals("T1", "T2");
    ConnectTerminals("T2", "T3");
    DisplayTerminalConnections();

    CalculateCharge("((W*100)+200)-D", 25, 150);

    return 0;
}
