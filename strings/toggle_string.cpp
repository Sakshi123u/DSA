#include<iostream>
using namespace std;
class string_operation{
    private:
    char *A;
    public:
    string_operation();
    void get_str();
    void togglecase();
    void display();
    ~string_operation();
};
string_operation::string_operation(){
    A=new char[100];
}
void string_operation::get_str(){
    cout<<"Enter string :"<<endl;
    cin.getline(A,100);
}
void string_operation::togglecase(){
    for(int i=0;A[i]!='\0';i++){
        if(A[i]>=65 && A[i]<=90){
            A[i]+=32;
        }
        else if(A[i]>=97 && A[i]<=122){
            A[i]-=32;
        }
    }
    cout<<"case of entered string has been changed"<<endl;
}
void string_operation::display(){
    cout<<"string : "<<endl;
    cout<<A;
}
string_operation::~string_operation(){
    delete [] A;
}
int main(){
    string_operation s;
    s.get_str();
    s.togglecase();
    s.display();
    return 0;
}