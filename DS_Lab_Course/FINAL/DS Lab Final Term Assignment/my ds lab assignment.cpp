#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ===================== Part 1: Passenger & Baggage (DLL) =====================
class PassengerNode {
public:
    string name;
    string passport;
    int baggage;
    PassengerNode* prev;
    PassengerNode* next;

    PassengerNode(string n, string p, int b) {
        this->name = n;
        this->passport = p;
        this->baggage = b;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class PassengerList {
public:
    PassengerNode* head;
    PassengerNode* tail;
    PassengerNode* undoStack[100];
    int undoTop;

    PassengerList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->undoTop = -1;
    }

    void AddPassenger(string name, string passport, int baggage) {
        PassengerNode* p = new PassengerNode(name, passport, baggage);

        if (this->head == nullptr) {
            this->head = p;
            this->tail = p;
        } else {
            this->tail->next = p;
            p->prev = this->tail;
            this->tail = p;
        }

        this->undoTop++;
        this->undoStack[this->undoTop] = p;

        cout << "Passenger Added: " << name << "\nPassport: " << passport << "\nBaggage: " << baggage << "kg\n\n";
    }

    void DisplayPassengersForward() {
        PassengerNode* temp = this->head;
        cout << "Passenger Linked List (Forward):\n";
        while (temp != nullptr) {
            cout << "(" << temp->name << " | " << temp->passport << " | " << temp->baggage << "kg)";
            if (temp->next != nullptr) cout << " - ";
            temp = temp->next;
        }
        cout << "\n\n";
    }

    void UndoLastCheckin() {
        if (this->undoTop == -1) {
            cout << "No check-in to undo.\n\n";
            return;
        }

        PassengerNode* p = this->undoStack[this->undoTop];
        this->undoTop--;

        cout << "Undo Last Check-in\nRemoved: " << p->name << " | Passport: " << p->passport << " | Baggage: " << p->baggage << "kg\n\n";

        if (p->prev != nullptr) p->prev->next = p->next;
        if (p->next != nullptr) p->next->prev = p->prev;
        if (p == this->head) this->head = p->next;
        if (p == this->tail) this->tail = p->prev;
        delete p;
    }
};

// ===================== Part 2: Frequent Flyers (BST) =====================
class FlyerNode {
public:
    int id;
    string name;
    int flights;
    FlyerNode* left;
    FlyerNode* right;

    FlyerNode(int i, string n, int f) {
        this->id = i;
        this->name = n;
        this->flights = f;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class FlyerBST {
public:
    FlyerNode* root;

    FlyerBST() {
        this->root = nullptr;
    }

    FlyerNode* Insert(FlyerNode* root, int id, string name, int flights) {
        if (root == nullptr) {
            FlyerNode* newNode = new FlyerNode(id, name, flights);
            cout << "Frequent Flyer Inserted: ID " << id << " | Name: " << name << " | Flights: " << flights << "\n\n";
            return newNode;
        }
        if (id < root->id) {
            root->left = Insert(root->left, id, name, flights);
        } else if (id > root->id) {
            root->right = Insert(root->right, id, name, flights);
        }
        return root;
    }

    void InsertFlyer(int id, string name, int flights) {
        this->root = Insert(this->root, id, name, flights);
    }

    void InOrder(FlyerNode* root) {
        if (root == nullptr) return;
        InOrder(root->left);
        cout << "ID: " << root->id << " | " << root->name << " | Flights: " << root->flights << "\n";
        InOrder(root->right);
    }

    void DisplayFlyers() {
        cout << "In-order Traversal of Frequent Flyers:\n";
        InOrder(this->root);
        cout << "\n";
    }
};

// ===================== Part 3: Terminal Graph (Adjacency List) =====================
class TerminalGraph {
public:
    static const int MAX_TERMINALS = 20;
    string terminals[MAX_TERMINALS];
    int adjList[MAX_TERMINALS][MAX_TERMINALS];
    int connectionCount[MAX_TERMINALS];
    int terminalCount;

    TerminalGraph() {
        terminalCount = 0;
        for (int i = 0; i < MAX_TERMINALS; i++) {
            connectionCount[i] = 0;
        }
    }

    int getTerminalIndex(const string& name) {
        for (int i = 0; i < terminalCount; i++) {
            if (terminals[i] == name) {
                return i;
            }
        }
        return -1;
    }

    void AddTerminal(const string& name) {
        if (getTerminalIndex(name) != -1) {
            cout << "Terminal " << name << " already exists.\n";
            return;
        }
        if (terminalCount >= MAX_TERMINALS) {
            cout << "Maximum number of terminals reached.\n";
            return;
        }
        terminals[terminalCount] = name;
        terminalCount++;
        cout << "Terminal Added: " << name << "\n";
    }

    void ConnectTerminals(const string& t1, const string& t2) {
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
};

// ===================== Part 4: Infix to Prefix + Evaluation =====================
class ExpressionCalculator {
public:
    char opStack[100];
    int opTop;

    ExpressionCalculator() {
        this->opTop = -1;
    }

    void pushOp(char ch) { this->opStack[++this->opTop] = ch; }
    char popOp() { return this->opStack[this->opTop--]; }
    char topOp() { return this->opStack[this->opTop]; }
    bool isEmptyOp() { return this->opTop == -1; }

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
};

// ===================== Main =====================
int main() {
    // Part 1: Passenger & Baggage
    PassengerList passengers;
    passengers.AddPassenger("Alice", "P12345", 18);
    passengers.AddPassenger("Bob", "P67890", 30);
    passengers.DisplayPassengersForward();

    passengers.UndoLastCheckin();
    passengers.DisplayPassengersForward();

    // Part 2: Frequent Flyers
    FlyerBST flyers;
    flyers.InsertFlyer(101, "Alice", 12);
    flyers.InsertFlyer(105, "Bob", 8);
    flyers.DisplayFlyers();

    // Part 3: Terminal Graph
    TerminalGraph terminals;
    terminals.AddTerminal("T1");
    terminals.AddTerminal("T2");
    terminals.AddTerminal("T3");
    terminals.ConnectTerminals("T1", "T2");
    terminals.ConnectTerminals("T2", "T3");
    terminals.DisplayTerminalConnections();

    // Part 4: Charge Calculation
    ExpressionCalculator calculator;
    calculator.CalculateCharge("((W*100)+200)-D", 25, 150);

    return 0;
}
