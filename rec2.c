//factorial program:
#include<stdio.h>

int fact(int n){
    int f;
    if(n==0){
        return 1;
    }
    f=n*fact(n-1);
    return f;
}

int main(){
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    printf("Factorial of %d is %d",n,fact(n));
    return 0;
}