#include<iostream>
using namespace std;
void merge(int A[],int l,int mid,int h){
        int i,j,k;
        int B[100];
        i=l;j=mid+1;k=l;
        while(i<=mid && j<=h){
            if(A[i]<A[j]){
                B[k++]=A[i++];
            }
            else{
                B[k++]=A[j++];
            }
        }
        while(i<=mid){
            B[k++]=A[i++];
        }
        while(j<=h){
            B[k++]=A[j++];
        }
        // copy sorte ele in first array
        for(int x=l;x<=h;x++){
            A[x]=B[x];
        }
}
void mergesort(int A[],int l,int h){
    if(l<h){
    int mid=(l+h)/2;
    mergesort(A,l,mid);
    mergesort(A,mid+1,h);
    merge(A,l,mid,h);
    }
}
int main(){
    int A[6]={11,1,20,7,2,3};
    int n=sizeof(A)/sizeof(A[0]);
    int l=0;
    int h=n-1;
    mergesort(A,l,h);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}