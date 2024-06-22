#include<iostream>
using namespace std;
void bubblesort(int A[],int n){
    int flag;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            cout<<"given array is already sorted";
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
int main(){
    int A[]={90,2,8,3,7};
    int n=sizeof(A)/sizeof(A[0]);
    bubblesort(A,n);
    return 0;
}