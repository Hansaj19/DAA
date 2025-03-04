#include <stdio.h>

int demo(int n){
    if(n==0){
        printf("call: %d\n",n);
        return 0;
    }
    printf("call: %d\n",n);
    demo(n-1);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("By for-loop:\n");
    for(int i=n;i>=0;i--){
        printf("iter: %d\n",i);
    }
    printf("By recursive call:\n");
    demo(n);
    return 0;
}