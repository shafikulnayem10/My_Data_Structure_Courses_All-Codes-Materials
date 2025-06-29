#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string department;
    Student* left;
    Student* right;
};

class StudentBST {
public:
    Student* root;

    StudentBST() {
        root = nullptr;
    }

    Student* insert(Student* node, int id, const string& name, const string& dept) {
        if (!node) {
            node = new Student{id, name, dept, nullptr, nullptr};
        } else if (id < node->id) {
            node->left = insert(node->left, id, name, dept);
        } else if (id > node->id) {
            node->right = insert(node->right, id, name, dept);
        } else {
            cout << "Duplicate ID. Not inserted.\n";
        }
        return node;
    }

    void inorder(Student* node) {
        if (node) {
            inorder(node->left);
            cout << "ID: " << node->id << ", Name: " << node->name << ", Dept: " << node->department << endl;
            inorder(node->right);
        }
    }

    Student* search(Student* node, int id) {
        if (!node || node->id == id)
            return node;
        if (id < node->id)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    Student* findMin(Student* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Student* deleteNode(Student* node, int id) {
        if (!node) return nullptr;

        if (id < node->id)
            node->left = deleteNode(node->left, id);
        else if (id > node->id)
            node->right = deleteNode(node->right, id);
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left || !node->right) {
                Student* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                Student* temp = findMin(node->right);
                node->id = temp->id;
                node->name = temp->name;
                node->department = temp->department;
                node->right = deleteNode(node->right, temp->id);
            }
        }
        return node;
    }
};

int main() {
    StudentBST bst;

    bst.root = bst.insert(bst.root, 102, "Alice", "CS");
    bst.root = bst.insert(bst.root, 101, "Bob", "EE");
    bst.root = bst.insert(bst.root, 103, "Charlie", "ME");

    cout << "All Students (Inorder):\n";
    bst.inorder(bst.root);

    cout << "\nSearching for ID 101:\n";
    Student* s = bst.search(bst.root, 101);
    if (s) cout << "Found: " << s->name << ", " << s->department << endl;
    else cout << "Not found.\n";

    cout << "\nDeleting ID 102\n";
    bst.root = bst.deleteNode(bst.root, 102);
    bst.inorder(bst.root);

    return 0;
}

