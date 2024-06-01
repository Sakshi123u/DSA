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
    void insert(int index,int x);
    int length();
    void display();
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
int linkedlist::length(){
    node *p=first;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
    cout<<endl;
}
void linkedlist::insert(int pos,int x){
    node *t,*p=first;
    if(pos <0 || pos>length() ){
        cout<<"invalid position";
        return;
    }
    if(pos==0){
        t=new node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<pos-1&& p;i++){
            p=p->next;
        }
        if(p){
        t=new node;
        t->data=x;
        t->next=p->next;
        p->next=t;
        }
    }
}
void linkedlist::display(){
    node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"enter linkedlist size: "<<endl;
    cin>>n;
    int A[n];
    cout<<"enter elements in linkedlist :"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l(A,n);
    l.length();
    l.insert(5,10); //insert at the end
    l.display();
    l.insert(0,10); //insert at the beginning
    l.display();
    return 0;
}