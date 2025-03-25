#include<iostream>
#include<vector>
using namespace std;

vector<int> pie(string p){
    int m = p.size();
    int j = 0;
    vector<int>prefix(m,0);

    for(int i=1;i<m;i++){
        while(j>0 && p[i]!=p[j]){
            j=prefix[j-1];
        }
        if(p[i]==p[j]){
            j++;
        }
        prefix[i]=j;
    }
    return prefix;
}

void kmp(string s,string p){
    vector<int>prefix = pie(p);

    cout<<"lps:";
    for(int i=0;i<prefix.size();i++){
        cout<<prefix[i]<<" ";
    }
    cout<<endl;

    int i=0,j=0,pos=-1;
    while(i<s.size()){//string's length
        if(s[i]==p[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=prefix[j-1];
            }
            else{
                i++;
            }
        }
        if(j==p.size()){
            pos = i-p.size();
            break;
        }
    }
    if(pos!=-1){
        cout<<"Match found at "<<pos;
    }
    else {
        cout<<"no match found";
    }
}
int main(){
    string s="AGCTTAGCTGAGCTAGCTAGCTGAGCTGCTAG";
    string p="GCTAG";
    kmp(s,p);
}