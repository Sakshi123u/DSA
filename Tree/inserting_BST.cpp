#include <iostream>
using namespace std;

// Node class to represent each node in the binary search tree (BST)
class node {
public:
    node *lchild;  // Pointer to the left child
    node *rchild;  // Pointer to the right child
    int data;      // Data stored in the node
};

// BST_tree class to manage the BST operations
class BST_tree {
private:
    node *root;  // Pointer to the root of the BST

public:
    // Constructor to initialize the root to NULL
    BST_tree();
    
    // Method to insert a key into the BST
    void insert(int key);
    
    // Method to perform in-order traversal starting from a given node
    void inorder(node *x);
    
    // Overloaded method to start in-order traversal from the root
    void inorder() {
        inorder(root);
        cout << endl;  // Add a newline after in-order traversal
    }
    
    // Method to search for a key in the BST
    node *search(int key);
};

// Constructor implementation
BST_tree::BST_tree() {
    root = NULL;
}

// Insert method implementation
void BST_tree::insert(int key) {
    node *t = root;  // Temporary pointer to traverse the tree
    node *p, *r;     // Pointers to create a new node and keep track of the parent

    // If the tree is empty, create the root node
    if (root == NULL) {
        p = new node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    // Traverse the tree to find the appropriate location to insert the new node
    while (t != NULL) {
        r = t;
        if (key < t->data) {
            t = t->lchild;
        } else if (key > t->data) {
            t = t->rchild;
        } else {
            return;  // If the key is already present, do nothing
        }
    }

    // Create the new node and attach it to the appropriate parent node
    p = new node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key > r->data) {
        r->rchild = p;
    } else {
        r->lchild = p;
    }
}

// In-order traversal method implementation
void BST_tree::inorder(node *x) {
    if (x) {
        inorder(x->lchild);  // Traverse the left subtree
        cout << x->data << " ";  // Visit the node
        inorder(x->rchild);  // Traverse the right subtree
    }
}

// Search method implementation
node *BST_tree::search(int key) {
    node *t = root;  // Temporary pointer to traverse the tree

    // Traverse the tree to find the key
    while (t != NULL) {
        if (key == t->data) {
            return t;  // If the key is found, return the node
        } else if (key < t->data) {
            t = t->lchild;  // Move to the left child
        } else {
            t = t->rchild;  // Move to the right child
        }
    }
    return NULL;  // If the key is not found, return NULL
}

int main() {
    BST_tree t;  // Create an instance of the BST_tree class
    char choice;
    int value;

    // Loop to allow user to insert values into the BST
    do {
        cout << "Do you want to insert a value into the BST? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter the value to insert: ";
            cin >> value;
            t.insert(value);  // Insert the value into the BST
        }
    } while (choice == 'y' || choice == 'Y');

    // Perform in-order traversal and display the BST
    cout << "In-order traversal: ";
    t.inorder();

    // Ask the user for a value to search in the BST
    cout << "Enter the value to search: ";
    cin >> value;
    node *temp = t.search(value);  // Search for the value
    if (temp != NULL) {
        cout << "Element found: " << temp->data << endl;  // If found, display the value
    } else {
        cout << "Element not found" << endl;  // If not found, display not found message
    }

    return 0;
}
