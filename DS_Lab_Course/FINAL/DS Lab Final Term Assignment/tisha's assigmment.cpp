#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ===================== Part 1: Passenger & Baggage (DLL) =====================
class Passenger {
public:
    string name;
    string passport;
    int baggage;
    Passenger* prev;
    Passenger* next;

    Passenger(string name, string passport, int baggage) {
        this->name = name;
        this->passport = passport;
        this->baggage = baggage;
        this->prev = NULL;
        this->next = NULL;
    }
};

// ======================= Passenger List Manager =======================
class PassengerList {
private:
    Passenger* head;
    Passenger* tail;
    Passenger* undoStack[100];
    int undoTop;

public:
    PassengerList() {
        head = NULL;
        tail = NULL;
        undoTop = -1;
    }

    void AddPassenger(string name, string passport, int baggage) {
        Passenger* p = new Passenger(name, passport, baggage);

        if (head == NULL) {
            head = tail = p;
        } else {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }

        undoStack[++undoTop] = p;

        cout << "Passenger Added:\n";
        cout << "Name: " << name << "\nPassport: " << passport << "\nBaggage: " << baggage << "kg\n\n";
    }

    void DisplayPassengersForward() {
        if (head == NULL) {
            cout << " No passengers to display.\n\n";
            return;
        }

        Passenger* temp = head;
        cout << " Passenger List (Forward):\n";
        while (temp != NULL) {
            cout << "(" << temp->name << " | " << temp->passport << " | " << temp->baggage << "kg)";
            if (temp->next != NULL) cout << " ↔ ";
            temp = temp->next;
        }
        cout << "\n\n";
    }

    void UndoLastCheckin() {
        if (undoTop == -1) {
            cout << " No check-in to undo.\n\n";
            return;
        }

        Passenger* p = undoStack[undoTop--];
        cout << " Undoing Last Check-in:\nRemoved: " << p->name << " | Passport: " << p->passport << " | Baggage: " << p->baggage << "kg\n\n";

        if (p->prev) p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        if (p == head) head = p->next;
        if (p == tail) tail = p->prev;

        delete p;
    }
};

// ===================== Part 2: Frequent Flyers (BST) =====================
#include <iostream>
#include <string>
using namespace std;

// ========================== Flyer Node Class ==========================
class Flyer {
public:
    int id;
    string name;
    int flights;
    Flyer* left;
    Flyer* right;

    // Constructor
    Flyer(int id, string name, int flights) {
        this->id = id;
        this->name = name;
        this->flights = flights;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// ========================== Flyer Tree Class ==========================
class FlyerTree {
public:
    Flyer* root;

    FlyerTree() {
        root = nullptr;
    }

    Flyer* InsertFlyer(Flyer* node, int id, string name, int flights) {
        if (!node) {
            Flyer* newNode = new Flyer(id, name, flights);
            cout << " Frequent Flyer Inserted: ID " << id << " | Name: " << name << " | Flights: " << flights << "\n\n";
            return newNode;
        }

        if (id < node->id) node->left = InsertFlyer(node->left, id, name, flights);
        else if (id > node->id) node->right = InsertFlyer(node->right, id, name, flights);
        return node;
    }

    void InOrderFlyers(Flyer* node) {
        if (!node) return;
        InOrderFlyers(node->left);
        cout << "ID: " << node->id << " | Name: " << node->name << " | Flights: " << node->flights << "\n";
        InOrderFlyers(node->right);
    }

    void Insert(int id, string name, int flights) {
        root = InsertFlyer(root, id, name, flights);
    }

    void DisplayInOrder() {
        if (!root) {
            cout << " No flyers to display.\n\n";
            return;
        }
        cout << " Frequent Flyers (In-Order Traversal):\n";
        InOrderFlyers(root);
        cout << "\n";
    }
};


// ===================== Part 3: Terminal Graph (Adjacency List with char[]) =====================
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
        cout << terminals[i] << " → ";
        for (int j = 0; j < connectionCount[i]; j++) {
            cout << terminals[adjList[i][j]];
            if (j < connectionCount[i] - 1) cout << ", ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// ===================== Part 4: Infix to Prefix + Evaluation (W and D variables) =====================
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

// ===================== Main =====================
int main() {
   PassengerList system;

    system.AddPassenger("Alice", "P12345", 20);
    system.AddPassenger("Bob", "P67890", 25);
    system.AddPassenger("Charlie", "P99999", 30);

    system.DisplayPassengersForward();

    system.UndoLastCheckin();
    system.DisplayPassengersForward();


    FlyerTree tree;

    tree.Insert(1002, "Alice", 6);
    tree.Insert(1005, "Bob", 11);
    tree.Insert(1001, "Charlie", 8);
    tree.Insert(1004, "Diana", 3);

    tree.DisplayInOrder();



    AddTerminal("T1");
    AddTerminal("T2");
    AddTerminal("T3");
    ConnectTerminals("T1", "T2");
    ConnectTerminals("T2", "T3");
    DisplayTerminalConnections();

    CalculateCharge("((W*100)+200)-D", 25, 150);

    return 0;
}

