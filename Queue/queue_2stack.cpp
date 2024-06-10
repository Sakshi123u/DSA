#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class stack{
    private:
    node*top;
    public:
    stack(){
        top=NULL;
    }
    void push(int x);
    int pop();
    bool is_empty(){
        return top==NULL;
    }
    void display();
    node* getTop() {
            return top;
    }
};
//push operation
void stack::push(int x){
    node *t=new node;
    if(t==NULL){
        cout<<"stack overflow "<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
//pop operation
int stack::pop(){
    int x=-1;
    if(top==NULL){
        cout<<"stack underflow "<<endl;
    }
    else{
        node *t=new node;
        t=top;
        x=t->data;
        top=top->next;
        delete t;
    }
    return x;
}
//display stack 
void stack::display(){
    node *p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
//queue class using two stack
class queue_using_stack{
    private:
    stack stack1;
    stack stack2;
    public:
    void enqueue(int x);
    int dequeue();
    void display();
};
void queue_using_stack ::enqueue(int x){
    stack1.push(x);
}
int queue_using_stack ::dequeue(){
    if(stack2.is_empty()){
        if(stack1.is_empty()){
            cout<<"oueue is empty "<<endl;
            return -1;
        }
        while(!stack1.is_empty()){
            stack2.push(stack1.pop());
        }
    }
    return stack2.pop();
}
void queue_using_stack ::display(){
    if(stack2.is_empty() && stack1.is_empty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    //displaying the ele in stack2 which are in correct order of deque
    if(!stack2.is_empty()){
        stack2.display();
    }
    //display ele in stack1 (which need to be reversed)
    if(!stack1.is_empty()){
        //using temporary stack to reverse the order
        stack temp;
        node *current=stack1.getTop();
        while(current!=NULL){
            temp.push(current->data);
            current=current->next;
        }
        temp.display();
    }
}
int main() {
    queue_using_stack q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();   // Displaying after enqueuing elements

    q.dequeue();   // Removing elements to show how queue works
    q.dequeue();
    q.dequeue();
    q.enqueue(70);
    q.enqueue(80);
    q.display();   // Displaying the queue after some dequeues and additional enqueues

    return 0;
}