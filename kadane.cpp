#include<iostream>
#include<vector>
using namespace std;
int kadane(vector<int>&arr,int size){
    int max=INT16_MIN;
    int sum=0;
    for(int i=0;i<size;i++){
        sum +=arr[i];
        if(sum>max){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return max;
}
int main(){
    int n;
    cout<<"enter the szie fo array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int max = kadane(arr,n);
    cout<<max;
    return 0;
}