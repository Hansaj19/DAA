#include <iostream>
using namespace std;
int findsum(int arr[],int size);

int findsum(int arr[],int size){
    if(size==0){
        return 0;
    }
    int sum=arr[size-1];
    sum=sum+findsum(arr,size-1);
    return sum;
}

int main(){
    int arr[5]={1,2,3,4,5};
    int sum=findsum(arr,5);
    cout<<"The sum is: "<<sum;
    return 0;
}