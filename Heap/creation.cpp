#include <iostream>
using namespace std;

void insert(int A[], int index) {
    int temp, i;
    i = index;
    temp = A[index];
    while (i > 1 && temp > A[i / 2]) {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

void createheap(int A[], int size) {
    for (int i = 2; i <= size; i++) {
        insert(A, i);
    }
}

void display(int A[], int size) {
    for (int i = 1; i <= size; i++) { // Start from 1 to skip the 0 index
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {0, 10, 20, 30, 35, 40, 75}; // 0 is included to make 1-based indexing easier
    int size = sizeof(A) / sizeof(A[0]) - 1; // Subtract 1 to exclude the 0 index
    createheap(A, size);
    display(A, size);
    return 0;
}
