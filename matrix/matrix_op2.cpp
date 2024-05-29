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
class tri_diagonal:public matrix{
public:
tri_diagonal(int n):matrix(n){};
void set_data(int i,int j,int x){
    if(i-j==1){
        A[i-1]=x;
    }
    else if(i-j==0){
        A[size-1+i-1]=x;
    }
    else if(i-j==-1){
        A[2*size-1+i-1]=x;
    }
}
int get_data(int i, int j){
    if(i-j==1){
        return A[i-1];
    }
    else if(i-j==0){
        return A[size-1+i-1];
    }
    else if(i-j==-1){
        return A[2*size+i-1];
    }
    return 0;
}
void display(){
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            if(i-j==1){
                cout<<A[i-1]<<" ";
            }
            else if(i-j==0){
                cout<<A[size-1+i-1]<<" ";
            }
            else if(i-j==-1){
                cout<< A[2*size-1+i-1]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
};
class symmetric_matrix:public matrix{
    public:
    symmetric_matrix(int n):matrix(n){};
    void set_data(int i,int j,int x){
        if(i <size && j<size){
            A[i*size+j]=x; //set element at position i and j
            A[j*size+i]=x; //set ele at position j and i 
        }
    }
    int get_data(int i,int j){
        if(i<size && j<size){
            return A[i*size+j]; //return ele at i andj
        }
        else{
            return -1;
        }
    }
    void display(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(j<=i){
                    cout<<A[i*size+j]<<" ";
                }
                else{
                    cout<<A[j*size+i]<<" ";
                }
            }
            cout<<endl;
        }
    }

};
class toeplitz_matrix:public matrix{
    public:
    toeplitz_matrix(int n):matrix(n){};
    void set_data(int i,int j,int x){
    if(i<=j){
        A[j-i]=x;
    }
    else if(i>j){
        A[size+i-j-1]=x;
    }
}
int get_data(int i, int j){
    if(i<=j){
        return A[j-i];
    }
    else if(i>j){
        return A[size+i-j-1];
    }
    return 0;
}
void display(){
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            if(i<=j){
                cout<<A[j-i]<<" ";
            }
            else if(i>j){
                cout<<A[size+i-j-1]<<" ";
            }
        }
        cout<<endl;
    }
}

};
int main() {
    int choice;
    int x;
    while (true) {
        cout << "1. Tri-Diagonal Matrix\n";
        cout << "2. Symmetric Matrix\n";
        cout << "3. Toeplitz Matrix\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                tri_diagonal d(5);
                cout << "Enter elements for tri-diagonal matrix:" << endl;
                for (int i = 1; i <= 5; i++) {
                    for (int j = 1; j <= 5; j++) {
                        cin >> x;
                        d.set_data(i, j, x);
                    }
                }
                cout << "Tri-Diagonal Matrix:" << endl;
                d.display();
                break;
            }
            case 2: {
                symmetric_matrix s(4);
                cout << "Enter elements for symmetric matrix:" << endl;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        cin >> x;
                        s.set_data(i, j, x);
                    }
                }
                cout << "Symmetric Matrix:" << endl;
                s.display();
                break;
            }
            case 3: {
                toeplitz_matrix t(4);
                cout << "Enter elements for toeplitz matrix:" << endl;
                for (int i = 1; i <= 4; i++) {
                    for (int j = 1; j <= 4; j++) {
                        cin >> x;
                        t.set_data(i, j, x);
                    }
                }
                cout << "Toeplitz Matrix:" << endl;
                t.display();
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
