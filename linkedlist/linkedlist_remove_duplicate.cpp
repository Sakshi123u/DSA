#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class linkedlist{
    private:
    node *first;
    public:
    linkedlist(){
        first=NULL;
    }
    linkedlist(int A[],int n);
    ~linkedlist();
    void rm_duplicate();
    void display();
};
linkedlist::linkedlist(int A[],int n){
    node *last,*t;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
linkedlist::~linkedlist(){
    node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}
void linkedlist::rm_duplicate(){
    node *p=first;
    node*q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
void linkedlist :: display(){
    node *p=first;
    while(p!=0){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"enter size : "<<endl;
    cin>>n;
    int A[n];
    cout<<"insert ele in linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l(A,n);
    cout<<"before removing duplicates : "<<endl;
    l.display();
    cout<<"after removing duplicates : "<<endl;
    l.rm_duplicate();
    l.display();
    return 0;
}
