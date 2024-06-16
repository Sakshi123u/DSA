#include <iostream>
using namespace std;

// Node class to represent each node in the tree and stack
class node {
public:
    int data;
    node *lchild;
    node *rchild;
    node *next;

    // Constructor to initialize a new node with given data
    node(int d) {
        data = d;
        lchild = rchild = next = nullptr;
    }
};

// Stack class to manage stack operations
class stack {
private:
    node *top; // Pointer to the top node in the stack

public:
    // Constructor to initialize the stack
    stack() {
        top = nullptr;
    }

    // Function to push a node onto the stack
    void push(node *x) {
        x->next = top;
        top = x;
    }

    // Function to pop a node from the stack
    node* pop() {
        if (!isempty()) {
            node *t = top;
            top = top->next;
            t->next = nullptr;
            return t;
        }
        return nullptr;
    }

    // Function to check if the stack is empty
    bool isempty() {
        return top == nullptr;
    }

    // Function to get the top element of the stack without removing it
    node* topElement() {
        return top;
    }
};

// Tree class to manage tree operations
class tree {
private:
    node *root; // Pointer to the root of the tree

public:
    // Constructor to initialize an empty tree
    tree() {
        root = nullptr;
    }

    // Constructor to initialize the tree with an array of values (preorder)
    tree(int A[], int n) {
        create(A, n);
    }

    // Destructor to clean up allocated memory
    ~tree() {
        clear(root);
    }

    // Recursive function to clear the tree
    void clear(node* p) {
        if (p) {
            clear(p->lchild);
            clear(p->rchild);
            delete p;
        }
    }

    // Function to create a tree from a preorder traversal array
    void create(int pre[], int n) {
        stack st;
        node *t;
        int i = 0;

        // Create the root node
        root = new node(pre[i++]);
        node *p = root;

        // Iterate over the rest of the elements
        while (i < n) {
            if (pre[i] < p->data) {
                // Create left child if the current element is less than the parent's data
                t = new node(pre[i++]);
                p->lchild = t;
                st.push(p);
                p = t;
            } else {
                if (!st.isempty() && pre[i] > p->data && pre[i] < st.topElement()->data) {
                    // Create right child if the current element is greater than the parent's data
                    // and less than the data of the node at the top of the stack
                    t = new node(pre[i++]);
                    p->rchild = t;
                    p = t;
                } else {
                    // Pop from stack if the current element doesn't fit in the current subtree
                    p = st.pop();
                }
            }
        }
    }

    // Function to perform an inorder traversal and print the tree
    void inorder(node* p) {
        if (p) {
            inorder(p->lchild);
            cout << p->data << " ";
            inorder(p->rchild);
        }
    }

    // Function to start the inorder traversal from the root
    void inorder() {
        inorder(root);
    }
};

int main() {
    int pre[] = {30, 20, 10, 25, 40, 35, 50};
    int n = sizeof(pre) / sizeof(pre[0]);

    // Creating a tree with the array values
    tree t(pre, n);

    // Perform inorder traversal and print the values
    cout << "Inorder traversal of the BST: ";
    t.inorder();
    cout << endl;

    return 0;
}
