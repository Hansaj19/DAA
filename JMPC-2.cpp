#include<iostream>
#include<vector>
using namespace std;

int getTime(string conversation,char infected){
    int time,res;
    time=res=0;
    bool flag1=false;
    int n=conversation.length();
    for(int i = 0; i<n ;i++){
        if(conversation[i]!=infected){
            flag1=true;
        }
        else {
            flag1=false;
            break;
        }
    }
    if(!flag1){
        for(int i = 0; i<n ;i++){
            if(conversation[i]!=infected){
                time+=1;
            }
            else{
                res = max(res,time);
                time=0; 
            }
        }
        return res;
    }
    else return 0;
}
int main(){
    string conversation;
    char infected;
    cin>>conversation;
    cin>>infected;
    int time  = getTime(conversation,infected);
    cout<<time;
    return 0;
}
