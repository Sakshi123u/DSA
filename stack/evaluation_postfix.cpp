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
    }
    void push(char x);
    char pop();
    int Eval_poxtfix(const char *postfix);
    int is_operend(char x);
};
void stack :: push(char x){
    node *t=new node;
    if(t==NULL){
        cout<<"stack overflow"<<endl;
    }
    t->data=x;
    t->next=top;
    top=t;
}
char stack :: pop(){
    char x='\0';
    if(top==NULL){
        cout<<"stack underflow"<<endl;
    }
    else{
        x=top->data;
        node *p=top;
        top=top->next;
        delete p;
    }
    return x;
}
int stack::is_operend(char x){
    return !(top==NULL||x=='+'||x=='-'||x=='*'||x=='/');
}
int stack::Eval_poxtfix(const char *postfix){
    int i,x1,x2,r;
    for(i=0;postfix[i]!='\0';i++){
        if(is_operend(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            x2=pop();
            x1=pop();
            switch(postfix[i]){
                case '+':
                    r=x1+x2;
                break;
                case '*':
                    r=x1*x2;
                break;
                case '/':
                    r=x1/x2;
                break;
                case '-':
                    r=x1-x2;
                break;
            }
            push(r);
        }
    }
    return pop();
}
int main(){
    stack s;
    s.push('#');     //since there is nothing inside stack so to not get error pushing #
    const char*postfix="234*+82/-";
    int result=s.Eval_poxtfix(postfix);
    cout<<"evaluation of postfix operation is : "<<result<<endl;
return 0;
}