#include<iostream>
using namespace std;
class string_operation{
    private:
    char *A;
    public:
    string_operation();
    void get_str();
    void count_words();
    ~string_operation();
};
string_operation::string_operation(){
    A=new char[100];
}
void string_operation::get_str(){
    cout<<"enter string :"<<endl;
    cin.getline(A,100);
}
void string_operation::count_words(){
    int count=1;
    for(int i=0;A[i]!='\0';i++){
        if(A[i]==' '&&A[i-1]!=' '){
            count++;
        }
    }
    cout<<"no.of words in sentence :"<<count<<endl;
}
string_operation::~string_operation(){
    delete []A;
}
int main(){
    string_operation s;
    s.get_str();
    s.count_words();
}