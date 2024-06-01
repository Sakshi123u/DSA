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
    void max_ele();
    void min_ele();
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
void linkedlist::max_ele(){
    node *p=first;
    int max=first->data;
    while(p){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    cout<<"Max ele in linkedlist : "<<max<<endl;
}
void linkedlist::min_ele(){
    node *p=first;
    int min=first->data;
    while(p){
        if(p->data<min){
            min=p->data;
        }
        p=p->next;
    }
    cout<<"Min ele in linkedlist : "<<min<<endl;
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
    l.max_ele();
    l.min_ele();
    return 0;
}