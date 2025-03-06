#include <stdio.h>
#include <math.h>
#include <string.h>

// Helper to get size of number
int getSize(long long numbr){
    int sz=0;
    while(numbr){
        sz++;
        numbr/=10;
    }
    return sz;
}

// Karatsuba for integer part
long long karatsuba(long long x,long long y){
    if(x<10||y<10){
        return x*y;
    }

    int szX=getSize(x);
    int szY=getSize(y);
    int n=fmax(szX,szY);
    int h=n/2;

    long long pwr=1;
    for(int i=0;i<h;i++){
        pwr*=10;
    }

    long long a=x/pwr;
    long long b=x%pwr;
    long long c=y/pwr;
    long long d=y%pwr;

    long long ac=karatsuba(a,c);
    long long bd=karatsuba(b,d);
    long long ad_bc=karatsuba(a+b,c+d)-ac-bd;

    return ac*pwr*pwr+ad_bc*pwr+bd;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        long long x, y;
  
        scanf("%lld %lld", &x, &y);

        long long res = karatsuba(x, y);
        printf("Product of pair %d: %lld\n", i, res);
    }

    return 0;
}
