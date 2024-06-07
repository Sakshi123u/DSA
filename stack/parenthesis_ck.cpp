#include<iostream>
using namespace std;
class node{
    public:
    char data;
    node *next;
};
class stack{
    private:
    node *top;
    public:
    stack(){
        top=NULL;
    };
    void push(char x);
    char pop();
    bool is_empty();
    char stack_top();
    bool is_opening(char c);
    bool is_closing(char c);
    bool is_matching(char opening,char closing);
    bool is_balanced(string exp);
};
void stack::push(char x){
    node *t=new node;
    if(!t){
        cout<<"stack overflow "<<endl;
        return;
    }
    t->data=x;
    t->next=top;
    top=t;
}
char stack:: pop(){
    if(is_empty()){
        cout<<"stack-underflow"<<endl;
        return 0;
    }
    char x=top->data;
    node *temp=top;
    top=top->next;
    delete temp;
    return x;
}
bool stack ::is_empty(){
    return top==NULL;    //return 1 if top is null
}
char stack::stack_top(){
    if(top){
        return top->data;
    }
}
bool stack::is_opening(char c){
    return c=='(' || c=='{' || c=='[';
}
bool stack::is_closing(char c){
    return c==')' || c=='}' || c==']';
}

bool stack :: is_matching(char opening,char closing){
    return (opening=='('&& closing==')')||
           (opening=='{'&& closing=='}')||
           (opening=='['&& closing==']');
}
bool stack::is_balanced(string exp){
    stack stack;
    for(int i=0;i<exp.length();i++){
        char c=exp[i];
        if(is_opening(c)){
            stack.push(c);
        }
        else if(is_closing(c)){
            if(stack.is_empty()||!is_matching(stack.pop(),c)){
                return false;
            }
        }
    }
    return stack.is_empty();
}
int main(){
    stack s;
    string exp;
    cout<<"enter an expression"<<endl;
    getline(cin,exp);
    if(s.is_balanced(exp)){
        cout<<"parenthesis is balanced"<<endl;
    }
    else{
        cout<<"parenthesis not balanced "<<endl;
    }
    return 0;
}