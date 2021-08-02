// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

void calc_power(int,int);
 
void main() {
    int b,e;
    printf("Enter the base\n");
    scanf("%d",&b);
    printf("Enter the exponent\n");
    scanf("%d",&e);
    calc_power(b,e);
}
 
void calc_power(int b,int e){
    int power=1;
    while(e>0){
        power*=b;
        e--;
    }
    printf("The power is = %d",power);
}