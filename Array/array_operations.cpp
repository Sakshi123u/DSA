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
    void un_array_pair_sum();
    void sorted_array_pair_sum();
    void single_missing_ele();
    void many_missing_ele();
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
void array ::un_array_pair_sum(){
    int key;
    cout<<"enter element to get sum of:"<<endl;
    cin>>key;
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            if(A[i]+A[j]==key){
                cout<<A[i]<<"+"<<A[j]<<"="<<key<<endl;
            }
        }
    }
}
/*another approach by hash table :
    for(int i=0;i<l;i++){
        if(H[key-A[i]]!=0){
            cout<<a[i]<<"+"<<k-a[i]<<"="<<key<<endl;
        }
        h[A[i]]++;
    }
*/
void array::sorted_array_pair_sum(){
    int key;
    cout<<"enter element to get sum of:"<<endl;
    cin>>key;
    int i=0;int j=l-1;
    while(i<j){
        if(A[i]+A[j]==key){
             cout<<A[i]<<"+"<<A[j]<<"="<<key<<endl;
        }
        else if(A[i]+A[j]<key){
            i++;
        }
        else{
            j--;
        }
    }
}
void array::single_missing_ele(){
    int dif=A[0]-0;
    for(int i=0;i<l;i++){
        if(A[i]-i!=dif){
            cout<<"Missing element :"<<i+dif<<endl;
            break;
        }
    }
}
void array::many_missing_ele(){
    int dif=A[0]-0;
    for(int i=0;i<l;i++){
        if(A[i]-i!=dif){
            while(dif<A[i]-i){
                cout<<"Missing elements"<<i+dif<<endl;
                dif++;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    array a(n);
    int choice;
    while(1){
        cout<<"--------------------"<<endl;
        cout<<"1.input_array\n2.un_array_pair_sum\n3.sorted_array_pair_sum\n4.single_missing_ele\n5.many_missing_ele"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            a.input_array();
            break;
            case 2:
            a.un_array_pair_sum();
            break;
            case 3:
            a.input_array();
            a.sorted_array_pair_sum();
            break;
            case 4:
            a.input_array();
            a.single_missing_ele();
            break;
            case 5:
            a.input_array();
            a.many_missing_ele();
            break;
            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    return 0;
}