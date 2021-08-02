// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int get_lcm( int a, int b); 
  
int main()  {  
    int n1, n2, lcm;  
    printf ("Enter any two numbers: \n");  
    scanf ("%d %d", &n1, &n2);  
    lcm = get_lcm( n1, n2); 
    printf("\nLCM of %d and %d is %d", n1, n2, lcm);  
    return 0;  
}  
  
int get_lcm ( int n1, int n2){  
    static int max = 1;  
    if ( max % n1  == 0 && max % n2 == 0)  {  
        return max;  
    }else{  
        max++;  
        get_lcm( n1, n2);  
        return max;  
    }  
}  