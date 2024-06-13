#include<iostream>
using namespace std;

// Node class to represent each node in the tree
class node{
    public:
    node *lchild; // Pointer to left child
    int data;     // Data in the node
    node *rchild; // Pointer to right child
};

// Queue class for level order traversal
class Queue{
    private:
    int front;
    int rear;
    int size;
    node **Q;  // Dynamic array to store addresses of nodes
    public:
    Queue();           // Default constructor
    Queue(int x);      // Parameterized constructor
    void enqueue(node *x); // Function to insert a node into the queue
    node *dequeue();       // Function to remove a node from the queue
    int isempty(){          // Function to check if the queue is empty
        return front==rear;
    }
};

// Default constructor
Queue::Queue(){
    front = rear = -1;
    size = 10;
    Q = new node *[size];
}

// Parameterized constructor
Queue::Queue(int size){
    front = rear = -1;
    this->size = size;
    Q = new node *[this->size];
}

// Function to insert a node into the queue
void Queue::enqueue(node *x){
    if(rear == size-1){
        cout << "Queue is full" << endl;
    }
    else{
        rear++;
        Q[rear] = x;
    }
}

// Function to remove a node from the queue
node *Queue::dequeue(){
    node *x = NULL;
    if(front == rear){
        cout << "Queue is empty " << endl;
    }
    else{
        front++;
        x = Q[front];
    }
    return x;
}

// Tree class to perform traversal operations
class tree{
    node *root; // Root node of the tree
    public:
    tree(){ // Constructor to initialize root to NULL
        root = NULL;
    }
    void createTree(); // Function to create the tree
    void preorder();   // Function to call preorder traversal
    void preorder(node *p); // Function to perform preorder traversal
    void inorder();    // Function to call inorder traversal
    void inorder(node *p);  // Function to perform inorder traversal
    void postorder();  // Function to call postorder traversal
    void postorder(node *p); // Function to perform postorder traversal
    int height();      // Function to get the height of the tree
    int height(node *p); // Function to calculate the height of the tree
    void levelorder(); // Function to call level order traversal
    void levelorder(node *p); // Function to perform level order traversal
};

// Function to create the tree
void tree::createTree(){
    node *p, *t;
    int x;
    Queue q(100);
    cout << "Enter root val: " << endl;
    cin >> x;
    root = new node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while(!q.isempty()){
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": " << endl;
        cin >> x;
        if(x != -1){
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": " << endl;
        cin >> x;
        if(x != -1){
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

// Function to call preorder traversal
void tree::preorder(){
    cout << "Preorder of tree is: " << endl;
    preorder(root);
    cout << endl;
}

// Function to perform preorder traversal
void tree::preorder(node *p){
    if(p != NULL){  // Base case if node is not null
        cout << p->data << " "; // Visit the root
        preorder(p->lchild);    // Recursive call to visit left subtree
        preorder(p->rchild);    // Recursive call to visit right subtree
    }
}

// Function to call inorder traversal
void tree::inorder(){
    cout << "Inorder of tree is: " << endl;
    inorder(root);
    cout << endl;
}

// Function to perform inorder traversal
void tree::inorder(node *p){
    if(p != NULL){  // Base case if node is not null
        inorder(p->lchild); // Recursive call to visit left subtree
        cout << p->data << " "; // Visit the root
        inorder(p->rchild); // Recursive call to visit right subtree
    }
}

// Function to call postorder traversal
void tree::postorder(){
    cout << "Postorder of tree is: " << endl;
    postorder(root);
    cout << endl;
}

// Function to perform postorder traversal
void tree::postorder(node *p){
    if(p != NULL){  // Base case if node is not null
        postorder(p->lchild); // Recursive call to visit left subtree
        postorder(p->rchild); // Recursive call to visit right subtree
        cout << p->data << " "; // Visit the root
    }
}

// Function to get the height of the tree
int tree::height(){
    return height(root);
}

// Function to calculate the height of the tree
int tree::height(node *p){
    int x = 0, y = 0;
    if(p == NULL){
        return 0; // Base case: height of an empty tree is 0
    }
    x = height(p->lchild); // Recursive call to calculate height of left subtree
    y = height(p->rchild); // Recursive call to calculate height of right subtree
    return x > y ? x + 1 : y + 1; // Height is the maximum of left or right subtree height plus 1
}

// Function to call level order traversal
void tree::levelorder(){
    cout << "Level order of tree is: " << endl;
    levelorder(root);
    cout << endl;
}

// Function to perform level order traversal
void tree::levelorder(node *p){
    Queue q(100);
    cout << p->data << " "; // Print the root
    q.enqueue(p); // Enqueue the root
    while(!q.isempty()){
        p = q.dequeue();
        if(p->lchild){
            cout << p->lchild->data << " "; // Print the left child
            q.enqueue(p->lchild); // Enqueue the left child
        }
        if(p->rchild){
            cout << p->rchild->data << " "; // Print the right child
            q.enqueue(p->rchild); // Enqueue the right child
        }
    }
}

// Main function
int main(){
    tree t;
    int choice;
    while(1){
        cout << "1. Create Tree\n2. Preorder\n3. Inorder\n4. Postorder\n5. Height\n6. Level Order\n";
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch(choice){
            case 1:
                t.createTree();
                break;
            case 2:
                t.preorder();
                break;
            case 3:
                t.inorder();
                break;
            case 4:
                t.postorder();
                break;
            case 5:
                int x;
                x = t.height();
                cout << "Height of tree is: " << x << endl;
                break;
            case 6:
                t.levelorder();
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
