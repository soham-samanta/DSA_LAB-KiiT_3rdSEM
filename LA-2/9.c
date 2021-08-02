// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int sum(int n){
    if(n==0)
    return;
    if((n%10)%2==0)
    return n%10+sum(n/10);
    else
    return sum(n/10);
}

int main(){
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);
    printf("The sum of digits in even place is %d\n",sum(a));
}