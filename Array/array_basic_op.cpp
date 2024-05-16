#include<iostream>
using namespace std;
class array{
    int *A;
    int l;
    public:
    array(int l){
        this->l=l;
        A=new int[l];
    }
    void input_array();
    void max_min();
    void get();
    void set(int index,int x);
    void sum();
    ~array(){
        delete []A;
    }
};
void array :: input_array(){
    cout<<"Enter  array elements"<<endl;
    for(int i=0;i<l;i++){
        cin>>A[i];
    }
    cout<<endl;
}
void array :: max_min(){
    int min=A[0];
    int max=A[0];
    for(int i=0;i<l;i++){
        if(A[i]<min){
            min=A[i];
        }
        else if(A[i]>max){
            max=A[i];
        }
    }
    cout<<"max elemet in array is:"<<max<<endl;
    cout<<"min element in array is"<<min<<endl;
}
// this function is used to get value at specific location
void array:: get(){
    int n;
    cout<<"enter index number"<<endl;
    cin>>n;
    if(n>=0 && n<l){
        cout<<A[n]<<endl;
    }
}
void array::set(int index,int x){
    int n=index;
    if(n>=0 && n<l){
        A[n]=x;
    }
    // displaying array after changing element at specific index
    cout<<" array :"<<endl;
    for(int i=0;i<l;i++){
        cout<<A[i];
    }
    cout<<endl;
}
void array ::sum(){
    int sum=0;
    for(int i=0;i<l;i++){
        sum=sum+A[i];
    }
    cout<<"sum is :"<<sum<<endl;
    cout<<"avg is:"<<sum/l<<endl;
}
int main(){
    int index,value;
    array a(6);
    int choice;
    while(1){
        cout<<"--------------------"<<endl;
        cout<<"1.input_array\n2.get()\n3.set()\n4.min_max\n5.sum_avg"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            a.input_array();
            break;
            case 2:
            a.get();
            break;
            case 3:
            cout<<"enter index and value"<<endl;
            cin>>index>>value;
            a.set(index,value);
            break;
            case 4:
            a.max_min();
            break;
            case 5:
            a.sum();
            break;
            default :
            cout<<"invalid choice"<<endl;
            break;
        }
    }
    return 0;
}
