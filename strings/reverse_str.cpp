#include <iostream>
#include<string.h>
using namespace std;

class string_operation {
    private:
        char *A;
        char *B;
    public:
        string_operation();
        void get_str();
        void reverse_1();
        void reverse_2();
        ~string_operation();
};

string_operation::string_operation() {
    A = new char[100];
    B=new char[100];
}

void string_operation::get_str() {
    cout << "Enter string: " << endl;
    cin.getline(A, 100);
}
void string_operation::reverse_1(){
    int length=strlen(A);
    int j;
    for(int i=length-1;i>=0;i--){
        for(j=0;i>=0;i--,j++){
            B[j]=A[i];
        }
        B[j]='\0';
        cout<<"reverse string :"<<B<<endl;
    }
}
void string_operation::reverse_2(){
    int length=strlen(A);
    int i;
    for(int j=length-1;j>=0;j--){
        for(i=0;i<j;i++,j--){
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    cout<<"reverse string :"<<B<<endl;
}
string_operation::~string_operation() {
    delete[] A;
    delete[]B;
}

int main() {
    string_operation s;
    s.get_str();
    s.reverse_1();
    s.reverse_2();
    return 0;
}
