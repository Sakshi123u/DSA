#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class stack{
    private:
    node *top;
    public:
    stack(){
        top=NULL;
    }
    void push(int x);
    int pop();
    void display();
    int peek(int pos);
    int stacktop();
    int is_empty();
    int is_full();
};
void stack::push(int x){
    node *t=new node;
    if(t==NULL){
        cout<<"stack overflow "<<endl;
    };
    t->data=x;
    t->next=top;
    top=t;
}
int stack::pop(){
    int x=-1;
    if(top==NULL){
        cout<<"stack underflow "<<endl;
    }
    else{
        node *p=top;
        top=top->next;
        x=p->data;
        delete(p);
        p=top;
    }
    return x;
}
void stack::display(){
    node *p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int stack::peek(int pos){
    int x=-1;
    node *p=top;
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    if(p!=0){
        return p->data;
    }
    else{
        return -1;
    }
}
int stack::stacktop(){
    if(top!=0){
        return top->data;
    }
    else{
        return -1;
    }
}
int stack::is_empty(){
    return top==NULL;  //return 1 if empty else 0
}
int stack::is_full() {
    node *t = new node;
    if (t == NULL) {
        return 1; // Return 1 if memory allocation fails (stack is full)
    } else {
        delete t;
        return 0;
    }
}
int main() {
    stack s;
    int choice, value, position;

    while (1) {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Top Element\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                if (value != -1)
                    cout << "Popped value: " << value << endl;
                break;
            case 3:
                cout << "Enter position to peek: ";
                cin >> position;
                value = s.peek(position);
                if (value != -1)
                    cout << "Value at position " << position << ": " << value << endl;
                else
                    cout << "Invalid position!" << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                if (s.is_empty())
                    cout << "Stack is empty!" << endl;
                else
                    cout << "Stack is not empty!" << endl;
                break;
            case 6:
                if (s.is_full())
                    cout << "Stack is full!" << endl;
                else
                    cout << "Stack is not full!" << endl;
                break;
            case 7:
                value = s.stacktop();
                if (value != -1)
                    cout << "Top element: " << value << endl;
                else
                    cout << "Stack is empty!" << endl;
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    return 0;
}