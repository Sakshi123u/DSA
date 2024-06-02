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
    node *second;
    public:
    linkedlist(){
        first=NULL;
        second=NULL;
    }
    void create(int A[],int n);
    void create2(int B[],int n);
    ~linkedlist();
    void concatenate(node *p,node *q);
    void display(node *p);
    node *getfirst(){
        return first;
    }
    node *getsecond(){
        return second;
    }
};
void linkedlist::create(int A[],int n){
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
void linkedlist::create2(int B[],int n){
    node *last,*t;
    second=new node;
    second->data=B[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
linkedlist::~linkedlist(){
    node *p=first;
    node *q=second;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
    while(second){
        second=second->next;
        delete q;
        q=second;
    }
}
void linkedlist :: concatenate(node *p,node*q){
    while(p->next!=0){
        p=p->next;
    }
    p->next=q;
}
void linkedlist :: display(node *p){
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
    int B[n];
    cout<<"insert ele in first  linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<"insert ele in second linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    linkedlist l;
    l.create(A,n);
    cout<<"display first linkedlist :"<<endl;
    l.display(l.getfirst());    //display first linkedlist
    l.create2(B,n);
    cout<<"display second linkedlist : "<<endl;
    l.display(l.getsecond());      //display second linkedlist
    l.concatenate(l.getfirst(),l.getsecond());        //concatinate two linkedlist
    cout<<"displaying linkedlist after concatination : "<<endl;
    l.display(l.getfirst());
    return 0;
}
