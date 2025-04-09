#include<iostream>
#include<vector>
using namespace std;

int orientation(pair<int,int>p,pair<int,int>q,pair<int,int>r){
    int cp = (q.second-p.second)*(r.first-q.first)-(q.first-p.first)*(r.second-q.second);
    if(cp==0)return 0;
    return(cp>0)?-1:1; //clkwise : countr clkwise
}

void jarvis_march(vector<pair<int,int>>&points,int V){
    vector<pair<int,int>>hull;
    int leftmost = 0;
    
    for(int i=0;i<V;i++){
        if(points[i].first<points[leftmost].first){
            leftmost = i;
        }
    }
    
    int p=leftmost,q;
    do{
        hull.push_back(points[p]);
        q=(p+1)%V;
        for(int i=0;i<V;i++){
            if(orientation(points[p],points[i],points[q])==1){
                q=i;//this loop will only run "h" times
            }
        }
        p=q;
        
    }while(p!=leftmost);
    
    cout<<hull.size()<<endl;
}

int main(){
    int V;
    cin>>V;
    int x,y;
    vector<pair<int,int>>points(V);
    for(int i=0;i<V;i++){
        cin>>points[i].first>>points[i].second;
    }
    if(V<3){
        cout<<"Convex hull not possible with less than 3 points";
    }
    else    jarvis_march(points,V);
    return 0;
}