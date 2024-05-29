#include <iostream>
using namespace std;

class string_operation {
    private:
        char *A;
        char *B;
    public:
        string_operation();
        void get_str();
        void str_compare();
        ~string_operation();
};

string_operation::string_operation() {
    A = new char[100];
    B=new char[100];
}

void string_operation::get_str() {
    cout << "Enter string1: " << endl;
    cin.getline(A, 100);
    cout<<"Enter string2 : "<<endl;
    cin.getline(B,100);
}
void string_operation::str_compare(){
    int i,j;
    for(i=0,j=0;A[i]!='\0'&& B[j]!='\0';i++,j++){
        if(A[i]!=B[j]){
            cout<<"un-equal string!"<<endl;
            break;
        }
    }
    if(A[i]==B[j]){
            cout<<"equal string"<<endl;
        }
        else if(A[i]<B[j]){
            cout<<"first string smaller than second"<<endl;
        }
        else{
            cout<<"first string is greater than second"<<endl;
        }
}
string_operation::~string_operation() {
    delete[] A;
    delete[]B;
}

int main() {
    string_operation s;
    s.get_str();
    s.str_compare();
    return 0;
}
