#include<iostream>
using namespace std;
float fun(int x,int n){
    static float p=1;
    static float f=1;
    if(n==0){
        return 1;
    }
    float r=fun(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;

}
int main(){
    float result=fun(1,4);
    cout<<result<<endl;
    return 0;
}