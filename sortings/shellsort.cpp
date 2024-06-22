#include<iostream>
using namespace std;

void shellsort(int A[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {  // gap should eventually reach 1
        for (i = gap; i < n; i++) {
            temp = A[i];
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
    }
}

int main() {
    int A[] = {9, 1, 3, 6, 2};
    int n = sizeof(A) / sizeof(A[0]);
    shellsort(A, n);
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
