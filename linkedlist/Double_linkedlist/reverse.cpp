#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *pre;
    node *next;
};
class linkedlist{
    private:
    node *first;
    public:
    linkedlist(){
        first=NULL;
    };
    void create(int A[],int n);
    void display(node *p);
    void reverse();
    node *getfirst(){
        return first;
    }
    ~linkedlist();
};
void linkedlist ::create(int A[],int n){
    node *last,*t;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    first->pre=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=last->next;
        t->pre=last;
        last->next=t;
        last=t;
    }
}
void linkedlist ::display(node *p){
    cout<<"display linkedlist : "<<endl;
    while(p!=0){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
linkedlist :: ~linkedlist(){
    node *p=first;
    while(p!=0){
        first=first->next;
        delete p;
        p=first;
    }
}
void linkedlist ::reverse(){
    node *p=first;
    while(p){
        node *temp=p->next;
        p->next=p->pre;
        p->pre=temp;
        p=p->pre;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}
int main(){
    int n;
    cout<<"enter size : "<<endl;
    cin>>n;
    int A[n];
    cout<<"enter ele in doubly likedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l;
    l.create(A,n);
    cout<<"displaying linkedlist before reversing : "<<endl;
    l.display(l.getfirst());
    cout<<"displaying linkedlist after reversing : "<<endl;
    l.reverse();
    l.display(l.getfirst());
    return 0;
}