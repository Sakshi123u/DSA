#include<iostream>
using namespace std;

// Node class for creating nodes of the binary tree
class node {
public:
    int data;
    node *lchild;
    node *rchild;
    node *next; // Used in stack operations

    // Constructor to initialize node with given data
    node(int d) {
        data = d;
        lchild = rchild = next = NULL; // Initialize pointers to NULL
    }
};

// Stack class for implementing stack operations using linked list
class stack {
private:
    node *top; // Pointer to track the top of the stack
    int size; // Maximum size of the stack
    node **s; // Array to hold stack elements

public:
    // Default constructor initializes stack with size 10
    stack() {
        top = NULL; // Initialize top to NULL indicating empty stack
        size = 10; // Default size of the stack
    }

    // Parameterized constructor to initialize stack with given size
    stack(int size) {
        top = NULL; // Initialize top to NULL indicating empty stack
        this->size = size; // Set the size of the stack
        s = new node*[size]; // Allocate memory for stack array
    }

    // Push operation to insert a node onto the stack
    void push(node *x);

    // Pop operation to remove and return the top node from the stack
    node* pop();

    // Function to check if the stack is empty
    int isempty() {
        return top == NULL;
    }

    // Function to check if the stack is full (not used in linked list implementation)
    int isfull() {
        node *t = new node(0); // Create a temporary node (not used in linked list)
        return t == NULL; // If memory allocation fails, stack is full
    }
};

// Push operation implementation for stack
void stack::push(node *x) {
    x->next = top; // Set next of the new node to current top of stack
    top = x; // Update top to point to the new node
}

// Pop operation implementation for stack
node* stack::pop() {
    if (!isempty()) { // Check if stack is not empty
        node *t = top; // Store current top node in a temporary variable
        top = top->next; // Move top to the next node
        t->next = NULL; // Clear next pointer of the popped node
        return t; // Return the popped node
    }
    return NULL; // Return NULL if stack is empty
}

// Tree class for binary tree operations
class tree {
    node *root; // Pointer to the root node of the tree

public:
    // Constructor to initialize tree with root node as NULL
    tree() {
        root = NULL;
    }

    // Function to create the binary tree iteratively
    void createTree();

    // Function to perform preorder traversal of the tree
    void preorder();

    // Helper function for preorder traversal
    void preorder(node *p);

    // Function to perform inorder traversal of the tree
    void inorder();

    // Helper function for inorder traversal
    void inorder(node *p);

    // Function to perform postorder traversal of the tree
    void postorder();

    // Helper function for postorder traversal
    void postorder(node *p);
};

// Function to create the binary tree iteratively using stack
void tree::createTree() {
    node *p, *t; // Pointers for creating nodes and traversing tree
    int x; // Variable to store user input for node values
    stack s(100); // Stack object to facilitate tree creation

    cout << "Enter root value: ";
    cin >> x;
    root = new node(x); // Create root node
    s.push(root); // Push root node onto stack

    // Iterative loop to create left and right children of nodes
    while (!s.isempty()) {
        p = s.pop(); // Pop node from stack
        cout << "Enter left child of " << p->data ;
        cin >> x;
        if (x != -1) {
            t = new node(x); // Create new node for left child
            p->lchild = t; // Link left child to parent node
            s.push(t); // Push left child onto stack for further processing
        }

        cout << "Enter right child of " << p->data ;
        cin >> x;
        if (x != -1) {
            t = new node(x); // Create new node for right child
            p->rchild = t; // Link right child to parent node
            s.push(t); // Push right child onto stack for further processing
        }
    }
}

// Function to perform preorder traversal of the tree
void tree::preorder() {
    preorder(root); // Call helper function with root node
    cout << endl;
}

// Helper function for preorder traversal
void tree::preorder(node *p) {
    stack st; // Stack object for iterative traversal
    while (p != NULL || !st.isempty()) {
        if (p != NULL) {
            cout << p->data << " "; // Print current node data
            st.push(p); // Push current node onto stack
            p = p->lchild; // Move to left child
        } else {
            p = st.pop(); // Pop node from stack
            p = p->rchild; // Move to right child
        }
    }
}

// Function to perform inorder traversal of the tree
void tree::inorder() {
    inorder(root); // Call helper function with root node
    cout << endl;
}

// Helper function for inorder traversal
void tree::inorder(node *p) {
    stack st; // Stack object for iterative traversal
    while (p != NULL || !st.isempty()) {
        if (p != NULL) {
            st.push(p); // Push current node onto stack
            p = p->lchild; // Move to left child
        } else {
            p = st.pop(); // Pop node from stack
            cout << p->data << " "; // Print current node data
            p = p->rchild; // Move to right child
        }
    }
}

// Function to perform postorder traversal of the tree
void tree::postorder() {
    postorder(root); // Call helper function with root node
    cout << endl;
}

// Helper function for postorder traversal
void tree::postorder(node *p) {
    stack st1, st2; // Two stacks for iterative postorder traversal
    st1.push(p); // Push root node onto first stack

    // Traverse tree using first stack to fill second stack with postorder nodes
    while (!st1.isempty()) {
        p = st1.pop(); // Pop node from first stack
        st2.push(p); // Push node onto second stack

        // Push left child and right child of popped node onto first stack
        if (p->lchild) {
            st1.push(p->lchild);
        }
        if (p->rchild) {
            st1.push(p->rchild);
        }
    }

    // Print nodes from second stack which now contains postorder traversal
    while (!st2.isempty()) {
        p = st2.pop(); // Pop node from second stack
        cout << p->data << " "; // Print node data
    }
}

// Main function to demonstrate binary tree operations
int main() {
    tree t; // Create tree object
    t.createTree(); // Create binary tree iteratively

    // Perform preorder traversal and print result
    cout << "Preorder traversal: ";
    t.preorder();

    // Perform inorder traversal and print result
    cout << "Inorder traversal: ";
    t.inorder();

    // Perform postorder traversal and print result
    cout << "Postorder traversal: ";
    t.postorder();

    return 0; // Return from main function
}
