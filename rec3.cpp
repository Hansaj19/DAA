//fibonacci:
#include<iostream>
using namespace std;
void reachHome(int src, int dest);
int main(){
    int src=1;
    int dest=5;
    reachHome(src,dest);
    return 0;
}

void reachHome(int src, int dest){
    if(src==dest){
        cout<<"reached";
        return;
    }
    cout<<"step:"<<src<<endl;
    src++;
    reachHome(src,dest);
}