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
    int search(node *p,int key,int index);
    node *getfirst(){
        return first;
    }
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
 int linkedlist :: search(node *p,int key,int index){
    if(p==NULL){
        return -1;
    }
    if(key==p->data){
        return index;
    }
    return search(p->next,key,index+1);
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
    cout<<"enter ele to be searched : "<<endl;
    int key;
    cin>>key;
    int index=0;
    int index1=l.search(l.getfirst(),key,index);
    if(index !=-1){
        cout<<"key found "<<key<<":"<<index1<<endl;
    }
    else{
        cout<<"key not found!"<<endl;
    }
    return 0;
 }