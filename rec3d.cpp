#include<iostream>
using namespace std;

void saydigit(int n);
int main(){
    int n ;
    cout<<"enter the number: ";
    cin>>n;
    saydigit(n);
    // cout<<"the "<<n<<"th fibb number is "<<answer<<endl;
}

void saydigit(int n){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int digit;
    if(n==0){
        return;
    }
    digit=n%10;
    saydigit(n/10);
    cout<<arr[digit]<<endl;
}