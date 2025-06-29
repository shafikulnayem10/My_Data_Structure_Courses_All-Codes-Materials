#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


node* insert(node* root, int value)
{
    if(root == nullptr)
    {
        return new node(value);
    }
    else if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(node* root)
{
    if(root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* search(node* root, int key)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    else if(root->data == key)
    {
        return root;
    }
    else if(key > root->data)
    {
        return search(root->right, key);
    }
    else
    {
         return search(root->left, key);
    }
}



int main ()
{
    node* root = nullptr;
    root = insert(root, 5);
    insert(root, 1);
    insert(root, 8);
    insert(root, 4);
    insert(root, 2);
    insert(root, 3);
    insert(root, 10);
    insert(root, 6);

    cout << "BST: ";
    inorder(root);

    int key;
    cout << "\nEnter Search Element:";
    cin>> key;

    node* result = search(root, key);
    if(result == nullptr)
    {
        cout <<key << " does not exist..";
    }
    else{
        cout <<key << " exists in the BST..";
    }
}
