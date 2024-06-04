#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *pre;
};
class linkedlist{
    private:
    node *head;
    public:
    linkedlist(){
        head=NULL;
    }
    void create(int A[],int n);
    void display(node *p);
    node *gethead(){
        return head;
    }
    ~linkedlist();
};
linkedlist :: ~linkedlist(){
    node *p=head;
    while(p!=NULL){
        head=head->next;
        delete p;
        p=head;
    }
}
void linkedlist::create(int A[],int n){
    node *last,*t;
    head=new node;
    head->data=A[0];
    head->next=NULL;
    head->pre=NULL;
    last=head;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        t->pre=last->next;
        last->next=t;
        last=t;
    }

}
void linkedlist :: display(node *p){
    while(p!=NULL){
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
    linkedlist l;
    l.create(A,n);
    cout<<"display doubly linkedlist : "<<endl;
    l.display(l.gethead());
    return 0;
}