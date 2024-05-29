#include<iostream>
using namespace std;
class elements{
    public:
    int i,j,x;
};
class sparse:public elements{
    private:
    int m;
    int n;
    int num;
    elements *ele;
    public:
    sparse(int m,int n,int num){
        this->m=m;
        this->n=n;
        this->num=num;
        ele=new elements[this->num];
    }
    ~sparse(){
        delete []ele;
    }
    void read(){
        cout<<"enter non-zero elements"<<endl;
        for(int i=0;i<num;i++){
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
        }
    }
    void display(){
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ele[k].i==i && ele[k].j==j){
                    cout<<ele[k++].x<<" ";
                }
                else{
                    cout<<"0"<<" ";
                }
            }
            cout<<endl;
        }
    }
};
int main(){
    sparse s(5,5,5);
    s.read();
    s.display();
    return 0;
}