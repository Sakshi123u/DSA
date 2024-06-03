#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
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
    node *getfirst(){
        return head;
    }
    void is_empty();          //if linkedlist is empty and we have to make it circular
    void insert_first();      //inserting at the beginning of circular linkedlist
    void insert_last();       //inserting at the last of circular linkedlist
    void insert();            //inserting at certain position in the circular linkedlist 
    ~linkedlist();        
};
void linkedlist::create(int A[],int n){
    node *last,*t;
    head=new node;
    head->data=A[0];
    head->next=head;          //assigning head to head->next to create a circular linkedlist
    last=head;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=last->next;  //as last->next is storing address of head now t will point to head
        last->next=t;
        last=t;    
    }
}
void linkedlist::display(node *p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}
void linkedlist ::insert_first(){
    node *q=new node;    //creating a new node to insert at first
    node *p=head;
    int x;
    cout<<"enter value to store in new data : "<<endl;
    cin>>x;
    q->data=x;
    q->next=NULL;
    while(p->next!=head){
        p=p->next;
    }
    p->next=q;
    q->next=head;
    head=q;
}
void linkedlist ::is_empty(){
    node *q=new node;   //creating a new node
    int x;
    cout<<"enter value to store in new data : "<<endl;
    cin>>x;
    q->data=x;
    q->next=NULL;
    if(head==0){
        head=q;       //head is pointing to q
        q->next=head;
        
    }
}
void linkedlist ::insert_last(){
    node *q=new node;
    int x;
    cout<<"enter value to store in new data : "<<endl;
    cin>>x;
    q->data=x;
    q->next=NULL;
    node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=q;
    q->next=head;
}
void linkedlist ::insert(){
    node *q=new node;
    node *p=head;
    int x;
    cout<<"enter value to store in new data : "<<endl;
    cin>>x;
    q->data=x;
    q->next=NULL;
    int pos;
    cout<<"enter position where u have to insert new node : "<<endl;
    cin>>pos;
    while(p->data!=pos){
        p=p->next;
    }
    q->next=p->next;
    p->next=q;
}
linkedlist::~linkedlist() {
    if (head== NULL) return;
    node *p = head;
    head = head->next;
    p->next = NULL; // Break the circular reference
    p = head;
    while (p != NULL) {
        head = head->next;
        delete p;
        p = head;
    }
}
int main(){
    int n;
    cout<<"enter size : "<<endl;
    cin>>n;
    int A[n];
    cout<<"insert ele in circular linkedlist : "<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    linkedlist l;
    l.create(A,n);
    cout<<"display linkedlist :"<<endl;
    l.display(l.getfirst());
    cout<<"inserting at first :"<<endl;
    l.insert_first();
    l.display(l.getfirst());
    cout<<"inserting at last : "<<endl;
    l.insert_last();
    l.display(l.getfirst());
    cout<<"inserting at certain pos : "<<endl;
    l.insert();
    l.display(l.getfirst());
}