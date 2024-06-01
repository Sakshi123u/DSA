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
    void reverse();
    void display();
    ~linkedlist();
    void reverse2(node *q,node *p);    //recurrsive fun to reverse linkedlist
    node *getfirst(){
        return first;
    }
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
void linkedlist::reverse(){
    node *p=first;
    node *q=NULL;
    node *r=NULL;
    while(p!=0){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void linkedlist::display(){
    node *p=first;
    while(p!=0){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void linkedlist::reverse2(node *q,node*p){
    if(p!=0){
        reverse2(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
int main(){
    int n;
    cout<<"enter size: "<<endl;
    cin>>n;
    int A[n];
    cout<<"insert ele in linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l(A,n);
    cout<<"before reversing : "<<endl;
    l.display();
    cout<<"After reversing : "<<endl;
    l.reverse();
    l.display();
    l.reverse(); //reverse again to get orignal linkelist
    cout<<endl;
    cout<<"by recurssion :"<<endl;
    l.reverse2(NULL,l.getfirst());
    l.display();
    return 0;
}