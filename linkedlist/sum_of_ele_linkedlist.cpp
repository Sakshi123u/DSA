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
    };
    linkedlist(int A[],int n);
    ~linkedlist();
    void sum_of_ele();
    int sum_of_ele1(node *q);
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
void linkedlist::sum_of_ele(){
    int sum=0;
    node *p=first;
    while(p){
        sum=sum+p->data;
        p=p->next;
    }
    cout<<"sum of ele in linkedlist : "<<sum<<endl;
}
int linkedlist::sum_of_ele1(node *q){
    if(q==0){
        return 0;
    }
    else
    {
        return sum_of_ele1(q->next)+q->data;
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
    linkedlist l(A,n);
    l.sum_of_ele();
    cout<<"by using recurrsion : "<<endl;
    int sum=l.sum_of_ele1(l.getfirst());
    cout<<"sum of ele is : "<<sum<<endl;
    return 0;
}