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
    linkedlist(int A[],int n); //creating linkelist
    ~linkedlist();
    int delete_ele(int pos);
    int length();
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
int linkedlist::length(){
    int len=0;
    node *p=first;
    while(p){
        len++;
        p=p->next;
    }
    return len;
    cout<<endl;
}
int linkedlist::delete_ele(int pos){
    node *p,*q=NULL;
    int x=-1;
    if(pos<1|| pos>length()){
        return -1;
    }
    if(pos==1){
        p=first;
        first=first->next;
        x=p->data;
        delete p;
        cout<<"deleted ele is : "<<endl;
        cout<< x;
        cout<<endl;
    }
    else{
        p=first;
        q=NULL;
        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        cout<<"deleted ele is : "<<endl;
        cout<<x<<endl;;
    }
}
void linkedlist ::display(){
    node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter size: "<<endl;
    cin>>n;
    int A[n];
    cout<<"insert ele in linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l(A,n);
    l.length();
    l.delete_ele(1); //deleting first pos ele
    l.display();
    l.delete_ele(4); //deleting ele at certain pos
    l.display();
    return 0;
}