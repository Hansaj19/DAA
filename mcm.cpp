#include <iostream>
#include <vector>
using namespace std;
// int mChain(vector<int>&arr,int i,int j){
//     int mini = INT16_MAX;
//     if(i==j) return 0;
//     else{
//         for(int k=i;k<j;k++){
//             int steps = arr[i-1]*arr[k]*arr[j]+ mChain(arr,i,k)+mChain(arr,k+1,j);
//             mini = min(steps,mini);
//         }
//     }
//     return mini;
// }
//DP-table approach:

int mChain(vector<int>&arr,int n){
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=1;i<n;i++)dp[i][i]=0;
    for(int i=n-1;i>=1;i--){
        int mini = 1e6;
        for(int j=i+1;j<n;j++){
            for(int k=i;k<j;k++){
                int steps = arr[i-1]*arr[k]*arr[j]+ dp[i][k]+dp[k+1][j];
                if(steps<mini)mini=steps;
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}
int main(){
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    cout<<mChain(arr,n);
    return 0;
}
