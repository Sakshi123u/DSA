#include<iostream>
using namespace std;
class string_operation{
    private:
    char *A;
    public:
    string_operation();
    void get_str();
    void count_vowel_consonent();
    ~string_operation();
};
string_operation::string_operation(){
    A=new char[100];
}
void string_operation::get_str(){
    cout<<"enter string :"<<endl;
    cin>>A;
}
void string_operation::count_vowel_consonent(){
    int v_count=0;
    int c_count=0;
    for(int i=0;A[i]!='\0';i++){
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U'){
            v_count++;
        }
        else if((A[i]>'a'&& A[i]<='z')|| (A[i]>'A'&& A[i]<='Z')){
            c_count++;
        }
    }
    cout<<"no. of vowel: "<<v_count<<endl;
    cout<<"no. of consonents : "<<c_count<<endl;
}
string_operation::~string_operation(){
    delete []A;
}
int main(){
    string_operation s;
    s.get_str();
    s.count_vowel_consonent();
    return 0;
}