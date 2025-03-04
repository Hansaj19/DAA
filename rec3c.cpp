#include<iostream>
using namespace std;

int stairs(int n);
int main(){
    int n ;
    cout<<"enter the number: ";
    cin>>n;
    int answer = stairs(n);
    cout<<answer<<endl;
}

int stairs(int n){
    int count=1;
    int result,strt=1;
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return stairs(n-1)+stairs(n-2);
}