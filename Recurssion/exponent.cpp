#include<iostream>
using namespace std;
int pow(int m,int n){
    if(n==0){
        return 1;
    }
    return pow(m,n-1)*m;
}
int main(){
    int result=pow(2,5);
    cout<<result;
    return 0;
}
/*alternative approach for making less number of calls
int pow(int m,int n){
    if(n==0)
    return 1;
    if(n%2==0){
        return pow(m*m,n/2);
    }
    else{
        return pow(m*m,n-1/2)*m;
    }
}*/