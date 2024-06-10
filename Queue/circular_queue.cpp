#include<iostream>
using namespace std;
class queue{
    private:
    int size;
    int front;
    int rear;
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
    void display();
    int dequeue();
};
void queue::enqueue(int x){
    if((rear+1)%size==front){
        cout<<"oueue is full "<<endl;
    }
    else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}
int queue::dequeue(){
    int x=-1;
    if(rear==front){
        cout<<"queue is empty "<<endl;
    }
    else{
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}
void queue::display(){
    cout<<"displaying queue : "<<endl;
    int i=front+1%size;
    do{
        cout<<Q[i]<<" ";
        i=(i+1)%size;
    }while(i!=(rear+1)%size);
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
    q.display();   //displaying after filling the entire queue
    //q.dequeue(); removes the element at the front. front becomes 0.
// q.dequeue(); removes the element at the front. front becomes 1.
// q.dequeue(); removes the element at the front. front becomes 2
    q.dequeue();    
    q.dequeue();
    q.dequeue();
    //After these operations, the elements in the queue are: [_, _, _, 40, 50, 60] where _ indicates empty spots.
    q.enqueue(70);   
    q.enqueue(80);
     //The queue now contains: [70, 80, _, 40, 50, 60].
     // Displaying the queue will print: 40 50 60 70 80.
    q.display();    //displaying circular queue
    return 0;
}