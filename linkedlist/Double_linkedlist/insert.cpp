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
    }
    void create(int A[],int n);
    void display(node *p);
    int length(node *p);
    node *getfirst(){
        return first;
    }
    ~linkedlist();
    void insert(node *p,int index,int x);
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
        t->next=last->next;
        t->pre=last;
        last->next=t;
        last=t;
    }
}
void linkedlist::display(node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int linkedlist ::length(node *p){
    int len=0;
    while(p!=0){
        len++;
        p=p->next;
    }
    return len;
}
void linkedlist :: insert(node *p,int index,int x){
    node *t=new node;
    if(index<0 || index >length(p)){
        return;
    }
    if(index==0){         //adding node at first
        t->data=x;
        t->next=first;
        t->pre=NULL;
        first->pre=t;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){      //inserting at certain position
            p=p->next;
        }
        t->data=x;
        t->next=p->next;
        t->pre=p;
        p->next=t;
        if(p->next){
        p->next->pre=t;
        }
        p->next=t;
    }
}
linkedlist :: ~linkedlist(){
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
    cout<<"display linkedlist :"<<endl;
    l.display(l.getfirst());
    int choice;
    while(1){
        cout<<"1.insert_first\n2.insert_at_pos\n";
        cout<<"enter your choice : "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                l.length(l.getfirst());
                l.insert(l.getfirst(),0,5);
                cout<<"display linkedlist : "<<endl;
                l.display(l.getfirst());
            break;
            case 2:
                l.length(l.getfirst());
                l.insert(l.getfirst(),2,5);
                cout<<"display linkedlist : "<<endl;
                l.display(l.getfirst());
            break;
            default :
                cout<<"invalid choice!"<<endl;
            break;
        }
    }
}