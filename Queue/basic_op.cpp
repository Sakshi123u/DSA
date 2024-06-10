#include<iostream>
using namespace std;
class queue{
    private:
    int front;
    int rear;
    int size;
    int *Q;
    public:
    queue(){
        front =rear=-1;
        size=10;
        Q=new int [size];
    }
    queue(int size){
        front =rear=-1;
        this->size=size;
        Q=new int [this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};
void queue::enqueue(int x){
    if(rear==size-1){
        cout<<"queue is full"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
int queue::dequeue(){
    int x=-1;
    if(front == rear){
        cout<<"queue is empty "<<endl;
    }
    else{
        x=Q[front];
        front++;
    }
    return x;
}
void queue::display(){
    cout<<"displaying queue : "<<endl;
    for(int i=front+1;i<=rear;i++){      //as initially the front is pointing to-1 so front+1
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
int main(){
    queue q(6);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    q.dequeue();
    cout<<"displaying queue after dequeue : "<<endl;
    q.display();
}