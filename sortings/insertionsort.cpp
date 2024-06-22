#include<iostream>
using namespace std;
void insertion(int A[],int n){
    for(int i=1;i<n;i++){
      int j=i-1;
      int x=A[i];
        while(j>-1 &&A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
int main(){
    int A[]={8,5,7,3,2};
    int n=sizeof(A)/sizeof(A[0]);
    insertion(A,n);
    return 0;
}