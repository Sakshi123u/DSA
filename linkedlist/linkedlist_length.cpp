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
    void length();
};
linkedlist::linkedlist(int A[],int n){
    node *last,*t;
    int i=0;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
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
void linkedlist::length(){
    node *p=first;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    cout<<"length of linkedlist: "<<len<<endl;
}
int main(){
    int n;
    cout<<"enter array size : "<<endl;
    cin>>n;
    int A[n];
    cout<<"enter elements in linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l(A,n);
    l.length();
}