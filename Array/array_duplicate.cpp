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
    void array_duplicate();
    void array_count_duplicate();
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
void array :: array_duplicate(){
    int last_duplicate=0;
    for(int i=0;i<l;i++){
        if(A[i]==A[i+1] && A[i]!=last_duplicate){
            cout<<"Duplicate elements are:"<<A[i]<<" ";
            last_duplicate=A[i];
        }
    }
    cout<<endl;
}
// another approach by using hash table
/*for(int i=0;i<n;i++){
    H[A[i]]++;
}
for(int i=0;i<=max;i++){
    if(h[i]>1){
        cout<<h[i]<<i;
    }
}
*/
void array ::array_count_duplicate(){
    int j=0;
    for(int i=0;i<l-1;i++){
        if(A[i]==A[i+1]){
            j=i+1;
            while(A[j]==A[i]){
                j++;
            }
            cout<<A[i]<<" Reapeated :"<<j-i<<endl;
            i=j-1;
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
        cout<<"-------------------------"<<endl;
        cout<<"1.input_array\n2.find_duplicate\n3.count_duplicate"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            a.input_array();
            break;
            case 2:
            a.array_duplicate();
            break;
            case 3:
            a.array_count_duplicate();
            break;
            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    return 0;
}