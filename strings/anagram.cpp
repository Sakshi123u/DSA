#include <iostream>
using namespace std;

class string_operation {
    private:
        char *A;
        char *B;
    public:
        string_operation();
        void get_str();
        void ck_anagram();
        ~string_operation();
};

string_operation::string_operation() {
    A = new char[100];
    B = new char[100];
}

void string_operation::get_str() {
    cout << "Enter string1: " << endl;
    cin.getline(A, 100);
    cout<<"Enter string2: "<<endl;
    cin.getline(B,100);
}
void string_operation::ck_anagram(){
    int H[26]={0};
    for(int i=0;A[i]!='\0';i++){
        H[A[i]-97]++;
    }
    for(int i=0;B[i]!='\0';i++){
        H[B[i]-97]--;
    }
    bool isAnagram = true;
    for(int i = 0; i < 26; i++){
        if(H[i] != 0){
            isAnagram = false;
            break;
        }
    }

    // Output the result
    if(isAnagram){
        cout << "Anagram!" << endl;
    } else {
        cout << "Not anagram!" << endl;
    }
}


string_operation::~string_operation() {
    delete[] A;
}

int main() {
    string_operation s;
    s.get_str();
    s.ck_anagram();
    return 0;
}
