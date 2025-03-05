#include<iostream>
#include<vector>
#include<string>
using namespace std;

void DPtable(string s , string t){
    int m=s.size();
    int n=t.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));//vector of m+1 and n+1 rows
    // for(int i=0;i<=m;i++)dp[i][0]=0;//all (i rows of 0th col)=0.
    // for(int i=0;i<=n;i++)dp[0][i]=0;//all (i cols of 0th row)=0.
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){//check for (i-1)th letter of "s" , in "t",and fill DP table.
                dp[i][j]=1+dp[i-1][j-1];//diagonal+1
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//max of(upper,left)
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    int len = dp[m][n];
    string ans = "";
    for(int i=0;i<len;i++){
        ans+='0';
    }
    int index = len-1;//0 based indexing
    int i=m,j=n;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[index]=s[i-1];
            index--;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<ans;
}
int main(){
    string s="hansaj";
    string t="hansaraj";
    DPtable(s,t);
    return 0;
}