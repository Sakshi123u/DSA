#include <iostream>
#include<cstring>
using namespace std;

class string_operation {
    private:
        char *A;
        char *B;
    public:
        string_operation();
        void get_str();
        void individual_duplicate();
        void hash_duplicate();
        void bit_duplicate();
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
void string_operation::individual_duplicate(){
    for(int i=0;A[i]!='\0';i++){
        int count=1;
        if(A[i]==-1){
            continue;
        }
        for(int j=i+1;A[j]!='\0';j++){
            if(A[i]==A[j]){
                count++;
                A[j]=-1;
            }
        }
        cout<<A[i]<<"="<<count<<endl;
    }
}
void string_operation::hash_duplicate(){
    int *H = new int[26](); // Initialize to 0
    for (int i = 0; A[i] != '\0'; i++) {
        if (isalpha(A[i])) {
            char ch = tolower(A[i]); // Convert to lowercase
            H[ch - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (H[i] > 1) {
            char temp = i + 'a';
            cout << temp << " : " << H[i] << endl;
        }
    }

    delete[] H;
    
}
void string_operation::bit_duplicate(){
    int seen = 0;
    int duplicates = 0;

    cout << "Duplicate characters: ";
    for (int i = 0; A[i] != '\0'; i++) {
        char ch = A[i];
        if (ch < 'a' || ch > 'z') {
            continue;
        }

        int mask = 1 << (ch - 'a');

        if (seen & mask) {
            if (!(duplicates & mask)) {
                cout << ch << " ";
                duplicates |= mask;
            }
        } else {
            seen |= mask;
        }
    }
    cout << endl;
}
string_operation::~string_operation() {
    delete[] A;
}

int main() {
    string_operation s;
    s.get_str();
    s.individual_duplicate();
    cout<<"-------------------"<<endl;
    s.get_str();
    s.hash_duplicate();
    cout<<"------------------"<<endl;
    s.get_str();
    s.bit_duplicate();
    return 0;
}
