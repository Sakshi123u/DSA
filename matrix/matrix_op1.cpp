#include<iostream>
using namespace std;
class matrix{
public:
int size;
int *A;
matrix(int n);
~matrix();
virtual void set_data(int i,int j,int x)=0;
virtual int get_data(int i,int j)=0;
virtual void display()=0;
};
matrix::matrix(int n):size(n){
A=new int[size*size];
for(int i=0;i<size;i++){
    A[i]=0;
}
}
matrix::~matrix(){
    delete []A;
}
class diagonal:public matrix{
public:
diagonal(int n):matrix(n){};
void set_data(int i,int j,int x){
    if(i==j){
    A[i-1]=x;
    }    
}
int get_data(int i, int j){
    if(i==j){
        return A[i-1];
    }
    return 0;
}
void display(){
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            if(i==j){
                cout<<A[i-1]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
};
class lower_triangular_matrix:public matrix{
public:
lower_triangular_matrix(int n):matrix(n){};
void set_data(int i ,int j,int x){
    if(i>=j){
        A[i*(i-1)/2+j-1]=x;
    }
}
int get_data(int i, int j){
    if(i>=j){
        return A[i*(i-1)/2+j-1];
    }
    return 0;
}
void display(){
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            if(i>=j){
                cout<<A[i*(i-1)/2+j-1]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
};
class upper_triangular_matrix:public matrix{
public:
upper_triangular_matrix(int n):matrix(n){};
void set_data(int i ,int j,int x){
    if(i<=j){
        A[(i-1)*size-((i-2)*(i-1))/2+j-i]=x;
    }
}
int get_data(int i, int j){
    if(i<=j){
        return A[(i-1)*size-((i-2)*(i-1))/2+j-i];
    }
    return 0;
}
void display(){
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            if(i<=j){
                cout<<A[(i-1)*size-((i-2)*(i-1))/2+j-i]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
};
int main() { 
    int choice;
    int x;
    while (1) {
        cout << "1. diagonal_matrix\n2. lower_triagular_matrix\n3. upper_triangular_matrix\n";
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                diagonal d(3);
                cout<<"Enter elements in matrix"<<endl;
                for (int i = 1; i <= 3; i++) {
                    for (int j = 1; j <= 3; j++) {
                        cin >> x;
                        d.set_data(i, j, x);
                    }
                }
                d.display();
                break;
            }
            case 2: {
                lower_triangular_matrix l(3);
                cout<<"Enter elements in matrix"<<endl;
                for (int i = 1; i <= 3; i++) {
                    for (int j = 1; j <= 3; j++) {
                        cin >> x;
                        l.set_data(i, j, x);
                    }
                }
                l.display();
                break;
            }
            case 3: {
                upper_triangular_matrix u(3);
                cout<<"Enter elements in matrix"<<endl;
                for (int i = 1; i <= 3; i++) {
                    for (int j = 1; j <= 3; j++) {
                        cin >> x;
                        u.set_data(i, j, x);
                    }
                }
                u.display();
                break;
            }
            default:
                cout << "invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
