// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int func(int n){  
    static int c=0; 
    if(n>0){  
      c=c+1;  
      return func(n/10);  
    }else  
    return c;  
}  

int main(){  
    int num,c=0; 
    printf("Enter a number: ");  
    scanf("%d",&num);  
    c=func(num);  
    printf("Number of digits is : %d", c);  
   return 0;  
}  
