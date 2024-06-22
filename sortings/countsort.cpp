#include<iostream>
using namespace std;
int findmax(int A[],int n){
    int max=A[0];
    for(int i=0;i<n;i++){
        if(max<A[i]){
            max=A[i];
        }
    }
    return max;
}
void countsort(int A[],int n){
    int max;
    int *c;
    int j=0,i=0;
    max=findmax(A,n);
    c=new int [max+1];
    for(int i=0;i<max+1;i++){
        c[i]=0;
    }
    for(int i=0;i<n;i++){
        c[A[i]]++;
    }
    while(i<max+1){
        if(c[i]>0){
            A[j++]=i;
            c[i]--;
        }
        else{
            i++;
        }
    }
    delete [] c;
}
int main(){
    int A[]={6,3,9,10,15,6,8,12,3,6};
    int n=sizeof(A)/sizeof(A[0]);
    countsort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}