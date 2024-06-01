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
    void reverse();
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
void linkedlist::reverse(){
    node *p=first;
    int i=0;
    int n=0;
    while(p!=0){
        n++;
        p=p->next;
    }
    int *A=new int[n];
    p=first;
    for(i=0;i<n;i++){
        A[i]=p->data;
        p=p->next;
    }
    p=first;
    for(i=n-1;i>=0;i--){
        p->data=A[i];
        p=p->next;
    }
    delete []A;
}
void linkedlist::display(){
    node *p=first;
    while(p!=0){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
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
    cout<<"display linkedlist before reversing : "<<endl;
    l.display();
    l.reverse();
    cout<<"displaying linkedlist after reversing : "<<endl;
    l.display();
    return 0;
}