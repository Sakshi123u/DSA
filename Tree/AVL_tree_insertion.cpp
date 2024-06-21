#include<iostream>
using namespace std;
class node{
    public:
    int key;
    node *left;
    node *right;
    int height;
};
int height(node *n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
int max(int a,int b){
    return (a>b)?a:b;
}
node *newnode(int key){
    node *s=new node;
    s->key=key;
    s->left=NULL;
    s->right=NULL;
    s->height=1;
    return (s);
}
node *rightrotate(node *y){
    node *x=y->left;
    node *t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
node *leftrotate(node *y){
    node *x=y->right;
    node *t2=x->left;
    x->left=y;
    y->right=t2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
int getbal(node *n){
    if(n==NULL)
    return 0;
    return height(n->left)-height(n->right);
}
node *insert(node *n,int key){
    if(n==NULL){
        return (newnode(key));
    }
    if(key<n->key){
        n->left=insert(n->left,key);
    }
    else if(key>n->key){
        n->right=insert(n->right,key);
    }
    else{
        return n;
    }
    n->height=1+max(height(n->left),height(n->right));
    int bal=getbal(n);
    if(bal>1 && key < n->left->key){
        return rightrotate(n);
    }
    if(bal<-1 && key > n->right->key){
        return leftrotate(n);
    }
    if(bal>1 && key>n->left->key){
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }
    if(bal < -1 && key < n->right->key){
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }
return n;
}
void preorder(node *root){
    if(root !=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    node *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    cout<<"preorder traversal of constructed AVL tree is : "<<endl;
    preorder(root);
    return 0;
}