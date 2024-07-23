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
    void create1(int A[],int n);
    void create2(int B[],int n);
    void display(node *p);
    ~linkedlist();
    void merge(node *first,node *second);
    node *getfirst(){
        return first;
    }
    node *getsecond(){
        return second;
    }
};
void linkedlist ::create1(int A[],int n){
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
void linkedlist ::create2(int A[],int n){
    node *last,*t;
    second=new node;
    second->data=A[0];
    second->next=NULL;
    last=second;
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
    p=second;
    while(second){
        second=second->next;
        delete p;
        p=second;
    }
}
void linkedlist :: merge(node *p,node *q){
    node *third,*last=NULL;
    if(p->data < q->data){
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p!=0 && q!=0){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)last->next=p;
    if(q!=NULL)last->next=q;
    first=third;          //update first to point to the head of merged list
}
void linkedlist::display(node *p){
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
    cout<<"insert ele in first linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int B[n];
    cout<<"insert ele in second linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    linkedlist l;
    l.create1(A,n);
    cout<<"display first linkedlist : "<<endl;
    l.display(l.getfirst());
    l.create2(B,n);
    cout<<"displaying second linkedlist : "<<endl;
    l.display(l.getsecond());
    l.merge(l.getfirst(),l.getsecond());
    cout<<"display after merging two linkedlist : "<<endl;
    l.display(l.getfirst());
    return 0;
}
