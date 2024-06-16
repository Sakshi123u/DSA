#include<iostream>
using namespace std;

// Node class to represent each node
class node{
    public:
    node *lchild;
    int data;
    node *rchild;
};

// BST_tree class to manage BST operations
class BST_tree{
    private:
    node *root;
    int key;
    public:
    // Constructors
    BST_tree();
    BST_tree(int key);

    // Recursive method to insert node in BST
    node* insert(node *p, int key);

    // Wrapper for insert to start from the root
    void insert(int key) {
        root = insert(root, key);
    }

    // Method to perform in-order traversal
    void inorder() {
        inorder(root);
    }

    // Helper method for in-order traversal
    void inorder(node *t);
};

// Constructor implementations
BST_tree::BST_tree() {
    root = NULL;
}

BST_tree::BST_tree(int key) {
    root = NULL;
    this->key = key;
}

// Insert method implementation
node* BST_tree::insert(node *p, int key) {
    if (p == NULL) {
        node *t = new node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    
    // Traverse the tree to find the appropriate location for the new node
    if (key < p->data) {
        p->lchild = insert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = insert(p->rchild, key);
    }
    // If key is equal, do nothing (assuming no duplicates are allowed)

    return p; // Return the updated node
}

// In-order traversal method implementation
void BST_tree::inorder(node *t) {
    if (t) {
        inorder(t->lchild);
        cout << t->data << " ";
        inorder(t->rchild);
    }
}

int main() {
    BST_tree t; // Create an instance of the BST_tree class
    char choice;
    int val;

    // Loop to allow user to insert values into the BST
    do {
        cout << "Do you want to insert a value into the BST? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter the value to insert: ";
            cin >> val;
            t.insert(val); // Insert the value into the BST
        }
    } while (choice == 'y' || choice == 'Y');

    // Perform in-order traversal and display the BST
    cout << "In-order traversal: ";
    t.inorder();
    cout << endl;

    return 0;
}
