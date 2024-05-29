#include <iostream>
using namespace std;

class string_operation {
    private:
        char *A;
    public:
        string_operation();
        void get_str();
        void valid_str();
        ~string_operation();
};

string_operation::string_operation() {
    A = new char[100];
}

void string_operation::get_str() {
    cout << "Enter string: " << endl;
    cin.getline(A, 100);
}

void string_operation::valid_str() {
    for (int i = 0; A[i] != '\0'; i++) {
        if (!((A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= 'a' && A[i] <= 'z') || (A[i] >= '0' && A[i] <= '9'))) {
            cout << "Invalid!" << endl;
            return; // Exit if an invalid character is found
        }
    }
    cout << "String is valid: " << A << endl;
}

string_operation::~string_operation() {
    delete[] A;
}

int main() {
    string_operation s;
    s.get_str();
    s.valid_str();
    return 0;
}
