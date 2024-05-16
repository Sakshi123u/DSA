#include<iostream>
using namespace std;
class array{
    int *A;
    public:
    int l;
    array(int l){
        this ->l=l;
        A=new int[100];
        
    }
    void input_array();
    void left_shift();
    void right_shift();
    void left_rotate();
    void right_rotate();
    void reverse();
    void display();
    ~array(){
        delete []A;
    }
};
void array:: input_array(){
    for(int i=0;i<l;i++){
        cin>>A[i];
    }
}
void array :: left_shift(){
    for(int i=0;i<l;i++){
        A[i]=A[i+1];
    }
    A[l-1]=0;
}
void array ::right_shift(){
    for(int i=l-1;i>0;i--){
        A[i]=A[i-1];
    }
    A[0]=0;
}
void array ::left_rotate(){
    int temp=A[0];
    for(int i=0;i<l;i++){
        A[i]=A[i+1];
    }
    A[l-1]=temp;
}
void array::right_rotate(){
    int temp=A[l-1];
    for(int i=l-1;i>0;i--){
        A[i]=A[i-1];
    }
    A[0]=temp;
}
void array :: reverse(){
    int *B=new int[l-1];
    for(int i=l-1,j=0;i>=0;i--,j++){
        B[j]=A[i];
    }
    for(int i=0;i<l;i++){
        A[i]=B[i];
    }
    delete [] B;
}
void array :: display(){
    for(int i=0;i<l;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"enter array size"<<endl;
    cin>>n;
    array a(n);
    int choice;
    while(1){
        cout<<"----------------------"<<endl;
        cout<<"1.input_array\n2.reverse\n3.left_shift\n4.right_shift\n5.left_rotate\n6.right_rotate\n"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            a.input_array();
            a.display();
            break;
            case 2:
            a.reverse();
            a.display();
            break;
            case 3:
            a.left_shift();
            a.display();
            break;
            case 4:
            a.right_shift();
            a.display();
            break;
            case 5:
            a.left_rotate();
            a.display();
            break;
            case 6:
            a.right_rotate();
            a.display();
            default :
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    return 0;
}

