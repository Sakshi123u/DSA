#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
    cout<<"Enter first array size"<<endl;
    cin>>n;
    cout<<"Enter second array size"<<endl;
    cin>>m;
    int p=m+n;
    int a[n];
    int b[m];
    int c[p];
    cout<<"Enter element in first array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter element in second array"<<endl;
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[k++]=a[i++];
        }
        else{
            c[k++]=b[j++];
        }
    }
    for(;i<n;i++){
        c[k++]=a[i];
    }
    for(;j<n;j++){
        c[k++]=b[j];
    }
    cout<<"Enter merge array"<<endl;
    for(int k=0;k<p;k++){
        cout<<c[k];
    }
}