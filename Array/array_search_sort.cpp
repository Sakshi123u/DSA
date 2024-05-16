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
    void linear_search();
    void binary_search();
    void bubble_sort();
    void selection_sort();
    void insertion_sort();
    void display();
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
void array :: linear_search(){
    int key;
    cout<<"Enter key element to be searched"<<endl;
    cin>>key;
    for(int i=0;i<l;i++){
        if(A[i]==key){
            cout<<"search successful"<<i<<endl;
            break;
        }
    }
    cout<<"search unsuccessful"<<endl;
}
void array :: binary_search(){
    int key;
    cout<<"Enter key element to be searched"<<endl;
    cin>>key;
    int l=0;
    int h=this->l-1;
    int mid;
    while(l<=h){
        mid=(l+h)/2;
        if(key<A[mid]){
             h=mid-1;
        }
        else if(key>A[mid]){
            l=mid+1;
        }
        else {
            cout<<"search successful at index :"<<mid<<endl;
            return;
        }
    }
    cout<<"search unsuccessful"<<endl;

}
void array ::bubble_sort(){
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(A[i]>A[j]){
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
}
void array ::selection_sort(){
    int min;
    for(int i=0;i<l;i++){
        min=i;
        for(int j=i+1;j<l;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        int temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}
void array::insertion_sort(){
    int key,j;
    cout<<"Enter key element"<<endl;
    cin>>key;
    for(int i=1;i<l;i++){
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j=j-1;
        }
         A[j+1]=key;
    }
}
void array :: display(){
    for(int i=0;i<l;i++){
        cout<<A[i]<<" "<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    array a(n);
    int choice;
    while(1){
        cout<<"---------------------"<<endl;
        cout<<"1.input_array\n2.linear_search\n3.bubblesort\n4.binary_search\n5.selection_sort\n6.inserton_sort"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            a.input_array();
            break;
            case 2:
            a.linear_search();
            break;
            case 3:
            a.bubble_sort();
            a.display();
            break;
            case 4:
            a.input_array();
            a.binary_search();
            break;
            case 5:
            a.input_array();
            a.selection_sort();
            a.display();
            break;
            case 6:
            a.input_array();
            a.insertion_sort();
            a.display();
            break;
        }
    }
    return 0;
}
