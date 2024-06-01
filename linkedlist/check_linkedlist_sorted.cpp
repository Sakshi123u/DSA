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
    int ck_sorted();
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
    node*p=first;
    while(p){
        first=first->next;
        delete p;
        p=first;
    }
}
int linkedlist ::ck_sorted(){
    node *p=first;
    int x=first->data;
    while(p){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
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
    int result=l.ck_sorted();
    if(result==true){
        cout<<"given linkedlist is sorted!"<<endl;
    }
    else{
        cout<<"not sorted!"<<endl;
    }
    return 0;
}