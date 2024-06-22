#include<iostream>
using namespace std;
int partition(int A[],int l,int h){
    int pivot=A[l];
    int i=l,j=h;
    while(1){
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>=pivot){
            j--;
        }
        if (i < j) {
            // Swap elements at i and j
            swap(A[i], A[j]);
        } else {
            // Swap pivot with element at j
            swap(A[l], A[j]);
            return j;
        }
    }
    
}
void quicksort(int A[],int l,int h){
    int j=0;
    if(l<h){
        j=partition(A,l,h);
        quicksort(A,l,j-1);
        quicksort(A,j+1,h);
    }
}
int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3,98};
    int n=sizeof(A)/sizeof(A[0]);
    quicksort(A,0,n-1);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}