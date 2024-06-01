#include <iostream>
using namespace std;

class Elements {
public:
    int i, j, x;
};

class Sparse {
private:
    int m, n, num;
    Elements* ele;
public:
    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Elements[this->num];
    }

    ~Sparse() {
        delete[] ele;
    }

    void read() {
        cout << "Enter non-zero elements (row column value):" << endl;
        for (int i = 0; i < num; i++) {
            cin >> ele[i].i >> ele[i].j >> ele[i].x;
        }
    }

    void display() {
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (k < num && ele[k].i == i && ele[k].j == j) {
                    cout << ele[k++].x << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    Sparse* operator+(Sparse& s) {
        if (m != s.m || n != s.n) {
            return nullptr;
        }

        Sparse* sum = new Sparse(m, n, num + s.num);
        int i = 0, j = 0, k = 0;

        while (i < num && j < s.num) {
            if (ele[i].i < s.ele[j].i || (ele[i].i == s.ele[j].i && ele[i].j < s.ele[j].j)) {
                sum->ele[k++] = ele[i++];
            } else if (ele[i].i > s.ele[j].i || (ele[i].i == s.ele[j].i && ele[i].j > s.ele[j].j)) {
                sum->ele[k++] = s.ele[j++];
            } else {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }

        while (i < num) sum->ele[k++] = ele[i++];
        while (j < s.num) sum->ele[k++] = s.ele[j++];

        sum->num = k;
        return sum;
    }
};

int main() {
    Sparse s1(5, 5, 3);
    Sparse s2(5, 5, 3);

    s1.read();
    s2.read();

    cout << "First Matrix:" << endl;
    s1.display();

    cout << "Second Matrix:" << endl;
    s2.display();

    Sparse* s3 = s1 + s2;
    if (s3 == nullptr) {
        cout << "Matrices dimensions do not match for addition." << endl;
    } else {
        cout << "Sum of Matrices:" << endl;
        s3->display();
        delete s3;
    }

    return 0;
}
