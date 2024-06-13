#include<iostream>
using namespace std;
//node class to represent each node in tree
class node{
    public:
    node *lchild; //pointer to left child
    node *rchild; //pointer to right child
    int data; //data in the node
};
//queue class for level order traversal
class Queue{
    private:
    int front;
    int rear;
    int size;
    node **Q;  //dynamic array to store address of nodes
    public:
    Queue();   //default constructor
    Queue(int x) ; //paramitarised constructor
    void enqueue(node *x);  //fun to insert node in queue
    node *dequeue();       //fun to remove node from queue
    int isempty(){          //fun to ck the queue is empty or not
        return front==rear;
    }
};
//default costructor
Queue::Queue(){
    front=rear=-1;
    size=10;
    Q=new node*[size];
} 
//parameterised constructor
Queue::Queue(int size){
    front=rear=-1;
    this->size=size;
    Q=new node*[this->size];
}
//fun to insert node in queue
void Queue::enqueue(node *x){
    if(rear==size-1){
        cout<<"queue is full"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
//fun to remove node from queue
node *Queue::dequeue(){
    node *x=NULL;
    if(front==rear){
        cout<<"queue is empty"<<endl;
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}
//tree class to perform traversal operations
class tree{
    node *root;   //root node of tree
    public:
    tree(){
        root=NULL;
    }
    void createTree();  //fun to create tree;
    int count(){
        return count(root);
    }
    int count(node *p);  //fun to count node;
    int leafnode(){
        return leafnode(root);
    };
    int leafnode(node *p); //fun to count leaf node
    int nonleafnode(){
        return nonleafnode(root);
    }
    int nonleafnode(node *p);
    int node_deg_1(){
        return node_deg_1(root);
    }
    int node_deg_1(node *p);
};
//fun to create tree
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

//fun to count nodes
int tree::count(node *p){
    int x=0;
    int y=0;
    if(p==0){
        return 0;
    }
    if(p!=NULL){
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
}
int tree::leafnode(node *p){
    int x=0;
    int y=0;
    if(p==0){
        return 0;
    }
    if(p->lchild==NULL && p->rchild==NULL){
        return 1;
    }
     x = leafnode(p->lchild);
     y = leafnode(p->rchild);
    return x + y; 
}
int tree::nonleafnode(node *p){
    int x=0;
    int y=0;
    if(p==0){
        return 0;
    }
    if(p->lchild!=NULL && p->rchild!=NULL){
        return 1;
    }
     x = leafnode(p->lchild);
     y = leafnode(p->rchild);
    return x + y; 
}
int tree::node_deg_1(node *p) {
    if (p == NULL) {
        return 0;
    }
    int left = node_deg_1(p->lchild);
    int right = node_deg_1(p->rchild);
    
    // Check if the current node has exactly one child
    if ((p->lchild != NULL && p->rchild == NULL) || (p->lchild == NULL && p->rchild != NULL)) {
        return left + right + 1; // This node has exactly one child
    }
    return left + right; // Sum of nodes with degree 1 in both subtrees
}
int main(){
    tree t;
    t.createTree();
    int x=t.count();
    cout<<"no.of nodes in tree: "<<x<<endl;
    int x2=t.leafnode();
    cout<<"no.of nodes in tree with deg(0): "<<x2<<endl;
    int x3=t.nonleafnode();
    cout<<"no.of nodes in tree with deg(2): "<<x3<<endl;
    int x4=t.node_deg_1();
    cout<<"no of nodes with deg(1): "<<x4;
    return 0;
}