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
    int search(node *p,int key);
    node *getfirst(){
        return first;
    }
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
    while(p){
        first=first->next;
        delete p;
        p=first;
    }
}
int linkedlist::search(node*p,int key){
    int index=0;
    node *q=NULL;
    while(p!=0){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return index;
        }
        index++;
        q=p;
        p=p->next;
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
    cout<<"enter size: "<<endl;
    cin>>n;
    int A[n];
    cout<<"insert ele in linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l(A,n);
    cout<<"enter ele to be searched : "<<endl;
    int key;
    cin>>key;
    int index=l.search(l.getfirst(),key);
    if(index!=-1){
        cout<<"key found "<<key<<":"<<index<<endl;
    }
    else{
        cout<<"key not found!"<<endl;
    }
    l.display();   //display the list after search to show move to head effect
    return 0;
}