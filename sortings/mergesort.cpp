#include<iostream>
using namespace std;

void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[100];
    
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++) {
        B[k++] = A[i];
    }
    for (; j <= h; j++) {
        B[k++] = A[j];
    }
    
    // Copy the merged elements back to A
    for (int i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

void mergesort(int A[], int n) {
    int pass, l, h, mid, i;
    for (pass = 2; pass <= n; pass = pass * 2) {
        for (i = 0; i + pass - 1 < n; i = i + pass) {
            l = i;
            h = i + pass - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
        
        // If the remaining elements are greater than pass/2, merge them
        if (n - i > pass / 2) {
            l = i;
            h = n - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }
    
    // Final pass to merge any remaining parts
    if (pass / 2 < n) {
        merge(A, 0, pass / 2 - 1, n - 1);
    }
}

int main() {
    int A[] = {11, 5, 14, 6, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);
    mergesort(A, n);
    cout << "MERGE SORT IS: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
