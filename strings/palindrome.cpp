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
        void palindrome();
        ~string_operation();
};

string_operation::string_operation() {
    A = new char[100];
    B=new char[100];
}

void string_operation::get_str() {
    cout << "Enter string1: " << endl;
    cin.getline(A, 100);
}
void string_operation::palindrome(){
    int length=strlen(A);
    int j;
    for(int i=length-1;i>=0;i--){
        for(j=0;i>=0;i--,j++){
            B[j]=A[i];
        }
        B[j]='\0';
        if(strcmp(A,B)==0){
            cout<<"it is palindrome!"<<endl;
        }
        else{
            cout<<"its not palindrome!"<<endl;
        }
    }
}
string_operation::~string_operation() {
    delete[] A;
    delete[] B;
}

int main() {
    string_operation s;
    s.get_str();
    s.palindrome();
    return 0;
}
