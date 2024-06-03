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
    void delete_first_node();
    void delete_last_node();
    void delete_node();
    node *getfirst(){
        return head;
    }
     ~linkedlist();
};
void linkedlist ::create(int A[],int n){
    node *last,*t;
    head=new node;
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void linkedlist :: display(node *p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}
void linkedlist::delete_first_node(){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        delete head;
        head= NULL;
    }
    else{
        node *t,*p;
        t=head;
        while(t->next!=head){
            t=t->next;
        }
        p=head;     //assigining new ptr to head
        head=head->next;    //moving head to head next
        t->next=head;       //pointing t->next to head
        delete p;           //deleting first node
        p=NULL;
    }
}
void linkedlist::delete_last_node(){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        delete head;
        head= NULL;
    }
    else{
        node *t,*p;
        p=NULL;
        t=head;
        while(t->next !=head){
            p=t;
            t=t->next;
        }
        p->next=head;
        delete t;
        t=NULL;
    }
}
void linkedlist ::delete_node(){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        delete head;
        head= NULL;
    }else{
        node *t,*p;
        p=NULL;
        t=head;
        cout<<"enter pos of node to delete : "<<endl;
        int x;
        cin>>x;
        while(t->data!=x){
            p=t;
            t=t->next;
        }
        p->next=t->next;
        delete t;
        t=NULL;
    }
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
    int choice;
    while(1){
        cout<<"1.display_linkedlist\n2.delete_first_node\n3.delete_last_node\n4.delete_node\n";
        cout<<"enter your choice : "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"display linkeedlist : "<<endl;
                l.display(l.getfirst());
            break;
            case 2:
                cout<<"deleting first node : "<<endl;
                l.delete_first_node();
                l.display(l.getfirst());
            break;
            case 3:
                cout<<"deleting last node : "<<endl;
                l.delete_last_node();
                l.display(l.getfirst());
            break;
            case 4:
                cout<<"deleting any node : "<<endl;
                l.delete_node();
                l.display(l.getfirst());
            break;
            default :
                cout<<"invalid choice!"<<endl;
            break;
        }
    }
    return 0;
}