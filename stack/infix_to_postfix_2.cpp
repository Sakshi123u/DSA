#include<iostream>
#include<cstring>
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
    }
    void push(char x);
    char pop();
    int is_operend(char x);
    int pre(char x);
    char *infix_postfix(const char*infix);
    bool isempty();
};
void stack::push(char x){
    node *t=new node;
    if(t==NULL){
        cout<<"stack overflow "<<endl;
    }
    t->data=x;
    t->next=top;
    top=t;
}

char stack::pop(){
    char x='\0';
    if(top==NULL){
        cout<<"stack underflow"<<endl;
    }
     x=top->data;
     node *p=top;
     top=top->next;
     delete p;
     return x;
}
int stack::is_operend(char x){
    return !(top==NULL||x=='+'||x=='-'||x=='*'||x=='/'||x==')'||x=='(');
}
int stack::pre(char x){
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0; // Assuming '(' has the lowest precedence
}
bool stack::isempty() {
    return top == NULL;
}

char *stack::infix_postfix(const char* infix){
    int len = strlen(infix);
    char *postfix = new char[len + 1]; 
    int i = 0; 
    int j = 0; 
    while (infix[i] != '\0') {
        if(is_operend(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            //if current ch is op or paranthesis
            if(infix[i]=='('){
                push(infix[i++]);
            }
            else if(infix[i]==')'){
                //pop all ele from stack until '(' this is encountered
                while(!isempty() && top->data!='('){
                    postfix[j++]=pop();  //add pop op to postfix expression
                }
                pop(); //discar '('
                i++;
            }
            else{
                //if current op has higher precendence than the top of stack,
                //push it onto the stack
                while(!isempty() && pre(infix[i])<=pre(top->data)){
                    postfix[j++]=pop(); //add pop op to postfix exp
                }
            push(infix[i++]);  //push the current op onto the stack
            }
        }
        
    }
//pop any remaining op from stack and add it to postfix
while(!isempty()){
    postfix[j++]=pop();
}
    postfix[j] = '\0'; // Null-terminate the postfix string
    return postfix;
}
int main(){
    stack s;
    const char *infix="(a+b)*c";
    char * postfix=s.infix_postfix(infix);
    cout<<"infix : "<<infix<<endl;
    cout<<"postfix : "<<postfix<<endl;
    return 0;
}