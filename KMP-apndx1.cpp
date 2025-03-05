#include<iostream>
#include<vector>
using namespace std;

vector<int> prefix_func(string s){
    int n=s.size();
    vector<int> pi(n,0);//vector pi, initialised with 0.
    for(int i=1;i<n;i++){
        int j=pi[i-1]; //store the no. of char matched till now.
        while (j>0 && s[i]!=s[j]){// if no match found goto pi of i-1 index.
            j=pi[j-1];
        }
        if(j<n && s[i]==s[j]){//if next elemnt is matched then increase "j" and move to next letter.
            j++;
        }
        pi[i]=j;//increased pi[i] by 1.
        //time complexity = o(n)
    }
    return pi;
}

int main(){
    string s="ansa";
    string t="hansaj";
    int pos=-1;
    vector<int> prefix = prefix_func(s);
    for(auto i:prefix){
        cout<<i<<" ";
    }
    int i=0,j=0;// j for pattern and "i" for string to find the patern.
    while(i<t.size()){
        if(t[i]==s[j]){
            j++; //if match found then increase both i and j.
            i++;
        }
        else{
            if(j!=0){
                j=prefix[j-1];//if j!=0 and match not found, go to the index, ie. the num prev term is storing.  "in pi[]" till match found.
            }
            else{
                i++;
            }
        }
        if(j==s.size()){//if strng end
            pos=i-s.size();
            break;
        }  
    }
    cout<<"\n";
    cout<<pos;
}