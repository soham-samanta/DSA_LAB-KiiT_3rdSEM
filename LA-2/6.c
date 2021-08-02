// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int isPerfectSquare(int x){
    int s = (int)sqrt(x); 
    return (s*s == x);
    }  
int isFibonacci(int x){
        if( isPerfectSquare(5*x*x + 4) || isPerfectSquare(5*x*x - 4)){
            printf("The number is a part of Fibonacci sequence \n");
            return 1;
        }else{
            printf("The number is not a part of Fibonacci sequence \n");
            return 0;
        }
}

int main(void){   
    printf("Enter the Number: ");
	int n;
    scanf("%d",&n);
	if (n>0){	
		printf("%d", isFibonacci(n)); 
	} 
	return 0;        
}