#include<iostream>
using namespace std;
int sum(int n){
    if(n==0){
        return n;
    }
    return sum(n-1)+n;
}
int main(){
    int s=sum(5);
    cout<<s;
    return 0;
}