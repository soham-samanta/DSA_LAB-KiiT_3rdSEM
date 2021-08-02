// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int main(){
    int n, sum=0, firstDigit,l;
    printf("Enter number = ");
    scanf("%d", &n);
    sum=n;
    l = n % 10;
    while(n >= 10){
        n = n / 10;
    }
    firstDigit = n;
    printf("The first digit of %d is: %d \n",sum, firstDigit);
    return 0;
}