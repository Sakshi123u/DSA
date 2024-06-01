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
    int ck_for_loop(node *f);
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
int linkedlist::ck_for_loop(node *f){
    node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        if(q!=0){
            q=q->next;
        }
        else{
            q=NULL;
        }

    }while(p&&q&&p!=q);
    if(p==q){
        return true;
    }
    else {
        return false;
    }
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
    //create a loop for testing
    //assuming the list has atleast two ele
    if(n>1){
        node *temp=l.getfirst();
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        //creating a loop by pointing the last node to the second node
        temp->next=l.getfirst()->next;
    }
    bool result=l.ck_for_loop(l.getfirst());
    if(result==true){
        cout<<"linkedlist is not linear! "<<endl;
    }
    else{
        cout<<"linkedlist is linear!"<<endl;
    }
}