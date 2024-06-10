#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class queue{
    node *front;
    node *rear;
    public:
    queue(){
        front=NULL;
        rear=NULL;
    }
    void enqueue(int x);
    int dequeue();
    void display();
};
void queue::enqueue(int x){
    node *t;
    t=new node;
    if(t==NULL){
        cout<<"Queue is full "<<endl;
    }
    else{
        t->data=x;
        t->next=NULL;
        //now chk the node which is created is it a first node
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }

    }
}
int queue::dequeue(){
    int x=-1;
    node *p;
    if(front==NULL){
        cout<<"queue is empty "<<endl;
    }
    else{
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }
    return x;
}
void queue::display(){
    cout<<"displaying queue : "<<endl;
    node *p=new node;
    p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout<<"dequeue ele is : "<<endl;
    int x=q.dequeue();
    cout<<x<<endl;
    q.display();
    return 0;
}