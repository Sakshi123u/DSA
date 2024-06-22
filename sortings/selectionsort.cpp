#include<iostream>
using namespace std;
void selection(int A[],int n){
        int j,k;
    for(int i=0;i<n;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        int temp=A[i];
        A[i]=A[k];
        A[k]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
int main(){
    int A[]={8,3,7,2};
    int n=sizeof(A)/sizeof(A[0]);
    selection(A,n);
}