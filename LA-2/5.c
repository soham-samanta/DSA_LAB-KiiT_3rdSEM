// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int ctr(int n){
    if(n==0)
    return 0;
    return 1+ctr(n/10);
}

int del_even(int n,int i){
    if(i%2 !=0)
    return del_even(n/10,i-1)*10 + (n%10);
    if(n/10==0)
    return 0;
    return del_even(n/10,i-1);
}

int main(){
    printf("Enter a number: ");
    int n;
    scanf("%d",&n);
    printf("After deleting the even positions: %d",del_even(n,ctr(n)));
    return 0;
}