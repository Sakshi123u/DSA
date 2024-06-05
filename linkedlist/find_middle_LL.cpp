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
    void create(int A[],int n);
    void find_middle();
    ~linkedlist();
};
void linkedlist::create(int A[],int n){
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
void linkedlist::find_middle(){
    node *p=first;
    node *q=first;
    while(q!=0 && q->next!=0){
        q=q->next->next;
        if(q!=0){
            p=p->next;
        }
    }
    cout<<"middle ele in linkedlist : "<<p->data<<endl;
}
linkedlist ::~linkedlist(){
    node *p=first;
    while(p){
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
    cout<<"insert ele in linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l;
    l.create(A,n);
    l.find_middle();
    return 0;
}