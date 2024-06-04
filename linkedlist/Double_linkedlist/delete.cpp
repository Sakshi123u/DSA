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
    node *first;
    public:
    linkedlist(){
        first=NULL;
    }
    void create(int A[],int n);
    void display(node *p);
    void delete_node(node *p,int index);
    ~linkedlist();
    node *getfirst(){
        return first;
    }
    int length(node *p);
};
void linkedlist :: create(int A[],int n){
    node *last,*t;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    first->pre=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        t->pre=last;
        last->next=t;
        last=t;
    }
}
int linkedlist :: length(node *p){
    int len=0;
    while(p!=0){
        len++;
        p=p->next;
    }
    return len;
}
void linkedlist ::display(node *p){
    cout<<"display linkedlist : "<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void linkedlist ::delete_node(node *p,int index){
    node *t=new node;
    if(index<1 || index>length(p)){
        return ;
    }
    if(index==1){
        first=first->next;
        if(first){
            first->pre=NULL;
        }
        int x=p->data;
        delete p;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        p->pre->next=p->next;
        if(p->next!=0){
            p->next->pre=p->pre;
        }
        int x=p->data;
        delete p;
    }
}
linkedlist ::~linkedlist(){
    node *p=first;
    while(p!=0){
        first=first->next;
        delete p;
        p=first;
    }
}
int main(){
    int n;
    cout<<"enter size : "<<endl;
    cin>>n;
    int A[n];
    cout<<"insert ele in doubly linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l;
    l.create(A,n);
    l.display(l.getfirst());
    l.delete_node(l.getfirst(),1);        //deleting first node
    l.display(l.getfirst());
    l.delete_node(l.getfirst(),3);
    l.display(l.getfirst());
    return 0;
}