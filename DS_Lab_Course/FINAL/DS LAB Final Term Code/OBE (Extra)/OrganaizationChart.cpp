#include<iostream>
using namespace std;

class Employee {
public:
    string name, role;
    Employee* left;
    Employee* right;

    Employee(string name, string role) {
        this->name = name;
        this->role = role;
        left = right = nullptr;
    }
};

void inorder(Employee* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->name << " (" << root->role << ")  ";
    inorder(root->right);
}

void preorder(Employee* root) {
    if (!root) return;
    cout << root->name << " (" << root->role << ")  ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Employee* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->name << " (" << root->role << ")  ";
}

int main() {
    Employee* ceo = new Employee("Alice", "CEO");
    ceo->left = new Employee("Bob", "Manager");
    ceo->right = new Employee("Carol", "Manager");
    ceo->left->left = new Employee("David", "Engineer");
    ceo->right->right = new Employee("Eva", "HR");

    cout << "\nInorder:\n";
    inorder(ceo);
    cout << "\n\nPreorder:\n";
    preorder(ceo);
    cout << "\n\nPostorder:\n";
    postorder(ceo);

    return 0;
}

