#include<iostream>
using namespace std;
class array{
    int *A;
    int *B;
    int l;
    public:
    int sizeA;
    int sizeB;
    array(int sizeA,int sizeB){
        this->sizeA=sizeA;
        this->sizeB=sizeB;
        A=new int[sizeA];
        B=new int[sizeB];
    }
    void input_array();
    int union_array();
    int intersection();
    int difference();
    ~array(){
        delete []A;
        delete []B;
    }
};
void array :: input_array(){
    cout<<"Enter first array elements"<<endl;
    for(int i=0;i<sizeA;i++){
        cin>>A[i];
    }
    cout<<"Enter second array elements"<<endl;
    for(int i=0;i<sizeB;i++){
        cin>>B[i];
    }
}
int array :: union_array(){
    int *c=new int[sizeA+sizeB];
    int i=0;
    int j=0;
    int k=0;
    while(i<sizeA && j<sizeB){
        if(A[i]<B[j]){
            c[k++]=A[i++];
        }
        else if(A[i]==B[j]){
            c[k++]=A[i++];
            j++;
        }
        else{
            c[k++]=B[j++];
        }
    }
    for(;i<sizeA;i++){
        c[k++]=A[i];
    }
    for(;j<sizeB;j++){
        c[k++]=B[j];
    }
    cout<<"Union of two array is:"<<endl;
    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    delete [] c;
}
int array :: intersection(){
    int *c=new int[sizeA+sizeB];
    int i=0;
    int j=0;
    int k=0;
    while(i<sizeA && j<sizeB){
        if(A[i]<B[j]){
            i++;
        }
        else if(A[i]==B[j]){
            c[k++]=A[i++];
            j++;
        }
        else{
            j++;
        }
    }
    cout<<"intersection of two array is:"<<endl;
    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    delete [] c;

}
int array :: difference(){
    int *c=new int[sizeA+sizeB];
    int i=0;
    int j=0;
    int k=0;
    while(i<sizeA && j<sizeB){
        if(A[i]<B[j]){
            c[k++]=A[i++];
        }
        else if(A[i]==B[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    for(;i<sizeA;i++){
        c[k++]=A[i];
    }
    cout<<"difference of two array is:"<<endl;
    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    delete [] c;
}
int main(){
    int n,m;
    cout<<"Enter size of first array"<<endl;
    cin>>n;
    cout<<"Enter size of second array"<<endl;
    cin>>m;
    array a(n,m);
    int choice;
    while(1){
        cout<<"-----------------"<<endl;
        cout<<"1.input_array\n2.union_array\n3.intersection_array\n4.difference_array"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            a.input_array();
            break;
            case 2:
            a.union_array();
            break;
            case 3:
            a.intersection();
            break;
            case 4:
            a.difference();
            break;
            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
}