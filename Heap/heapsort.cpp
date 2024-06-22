#include<iostream>
using namespace std;
void insert(int A[],int index){
    int i,temp;
    temp=A[index];
    i=index;
    while(i>1 && temp>A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int deleteheap(int A[],int size){
    int i,j,val,temp,x;
    val=A[1];
    x=A[size];
    A[1]=A[size];
    A[size]=val;
    i=1;j=i*2;
    while(j<=size-1){
        if(j<size-1 && A[j+1]>A[j] ){
            j=j+1;
        }
        if(A[i]<A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else{
            break;
        }
    }
    return val;
}
int main(){
    int H[]={0,14,15,5,20,30,8,40};
    int i;
    for(i=2;i<=7;i++){
        insert(H,i);
    }
    for(i=7;i>1;i--){
        deleteheap(H,i);
    }
    cout<<"Heap sort : "<<endl;
    for(i=1;i<=7;i++){
        cout<<H[i]<<" ";
    }
}