#include <iostream>
#include <vector>
using namespace std;
int mChain(vector<int>&arr,int i,int j){
    int mini = INT16_MAX;
    if(i==j) return 0;
    else{
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j]+ mChain(arr,i,k)+mChain(arr,k+1,j);
            mini = min(steps,mini);
        }
    }
    return mini;
}
int main(){
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    cout<<mChain(arr,1,arr.size()-1);
    return 0;
}
