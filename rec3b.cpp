#include<iostream>
using namespace std;

int fib(int n);
int main(){
    int n ;
    cout<<"enter the number: ";
    cin>>n;
    int answer = fib(n);
    cout<<"the "<<n<<"th fibb number is "<<answer<<endl;
}

int fib(int n){
    int count=1;
    int result,strt=1;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}