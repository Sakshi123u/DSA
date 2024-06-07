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
    int pre(char x);   //fun for checking precendence
    int is_operend(char x);
    char * infix_postfix(const char *infix);
};
void stack ::push(char x){
    node *t=new node;
    if(t==NULL){
        cout<<"stack is full"<<endl;
    }
    t->data=x;
    t->next=top;
    top=t;
}
char stack ::pop(){
    char x='\0';
    if(top==NULL){
        cout<<"stack is empty! "<<endl;
    }
    else{
    x=top->data;
    node *p=top;
    top=top->next;
    delete p;
    }
return x;
}
int stack::pre(char x) {
    if (top == NULL || x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int stack ::is_operend(char x){
     return !(x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')');
}
char *stack::infix_postfix(const char *infix){
    int len=strlen(infix);
    char *postfix=new char[len+2];
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(is_operend(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i])>pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=0){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    stack s;
    const char *infix="a+b*c";
    s.push('#');
    char *postfix=s.infix_postfix(infix);
    cout<<"postfix of given infix operation is : "<<postfix;
    delete [] postfix;
    return 0;
}