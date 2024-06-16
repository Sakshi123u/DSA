#include<iostream>
using namespace std;

// Node class to represent each node in the BST
class node {
public:
    int data;
    node* lchild;
    node* rchild;

    // Constructor to initialize a new node with given value
    node(int val) {
        data = val;
        lchild = rchild = NULL; // Initialize left and right children to NULL
    }
};

// BST_tree class to manage BST operations
class BST_tree {
private:
    node* root; // Pointer to the root node of the BST

    // Private helper function to recursively insert a new key in the BST
    node* insert(node* t, int key) {
        if (t == NULL) {
            return new node(key); // If tree is empty, create a new node
        }
        if (key < t->data) {
            t->lchild = insert(t->lchild, key); // Insert into left subtree
        }
        else if (key > t->data) {
            t->rchild = insert(t->rchild, key); // Insert into right subtree
        }
        return t;
    }

    // Private helper function to recursively delete a key from the BST
    node* delete_bst(node* t, int key) {
        if (t == NULL) {
            return NULL; // Base case: if tree or subtree is empty
        }
        // If key to be deleted is smaller, it lies in the left subtree
        if (key < t->data) {
            t->lchild = delete_bst(t->lchild, key);
        }
        // If key to be deleted is larger, it lies in the right subtree
        else if (key > t->data) {
            t->rchild = delete_bst(t->rchild, key);
        }
        else {
            // If key is same as root's key, then this is the node to be deleted
            // Node with one child or no child
            if (t->lchild == NULL) {
                node* temp = t->rchild; // Save right child
                delete t; // Delete current node
                return temp; // Return right child (may be NULL)
            }
            else if (t->rchild == NULL) {
                node* temp = t->lchild; // Save left child
                delete t; // Delete current node
                return temp; // Return left child (may be NULL)
            }
            // Node with two children: Get inorder successor (smallest in the right subtree)
            node* succParent = t;
            node* succ = t->rchild;
            while (succ->lchild != NULL) {
                succParent = succ; // Track parent of successor
                succ = succ->lchild; // Move to left child of successor
            }
            // Copy the inorder successor's content to this node
            t->data = succ->data;
            // Delete the inorder successor
            if (succParent->lchild == succ) {
                succParent->lchild = succ->rchild;
            }
            else {
                succParent->rchild = succ->rchild;
            }
            delete succ;
        }
        return t;
    }

    // Private helper function to perform inorder traversal recursively
    void inorder(node* t) {
        if (t) {
            inorder(t->lchild); // Traverse left subtree
            cout << t->data << " "; // Print current node's data
            inorder(t->rchild); // Traverse right subtree
        }
    }

public:
    // Constructor to initialize an empty BST
    BST_tree() {
        root = NULL;
    }

    // Public function to insert a new key into the BST
    void insert(int key) {
        root = insert(root, key); // Call private insert function
    }

    // Public function to delete a key from the BST
    void delete_bst(int key) {
        root = delete_bst(root, key); // Call private delete function
    }

    // Public function to perform inorder traversal of the BST
    void inorder() {
        inorder(root); // Call private inorder function
    }
};

// Main function to demonstrate BST operations
int main() {
    BST_tree t; // Create a BST object
    char choice;
    int val;

    // Loop to insert nodes into the BST
    do {
        cout << "Do you want to insert a value? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter value to insert: ";
            cin >> val;
            t.insert(val); // Insert value into BST
        }
    } while (choice == 'y' || choice == 'Y');

    // Loop to delete nodes from the BST
    do {
        cout << "Do you want to delete a value? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter value to delete: ";
            cin >> val;
            t.delete_bst(val); // Delete value from BST
        }
    } while (choice == 'y' || choice == 'Y');

    // Display inorder traversal of the BST
    cout << "Inorder traversal of the BST: ";
    t.inorder();
    cout << endl;

    return 0;
}
