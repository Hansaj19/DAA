#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> floyd(vector<vector<int>>adj){
    int n=adj.size();
    vector<vector<int>>cost=adj;
    // for(int i=0;i<n;i++)cost[i][i]=0;
    for(int via=0;via<n;via++){
        for(int i =0;i<n;i++ ){
            for(int j=0;j<n;j++){
                cost[i][j] = min(cost[i][j], cost[i][via]+cost[via][j]);
            }
        }
    }
    return cost;
}
int main(){
    int n;
    cout<<"enter the no. of vertex: ";
    cin>>n;
    vector<vector<int>>adj(n, vector<int>(n));
    vector<vector<int>>ans(n, vector<int>(n));
    cout<<"enter the weights: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0; j<n ;j++){
            cin>>adj[i][j];
        }
    }
    ans=floyd(adj);
    for(int i=0;i<n;i++){
        for(int j=0; j<n ;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}