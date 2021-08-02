// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define MAX_SIZE 100

int sum(int a[], int start, int len);

int main(){
    int a[MAX_SIZE];
    int N, i, s;
    printf("Enter No. of element is array: ");
    scanf("%d", &N);
    printf("Enter elements in the array: ");
    for(i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    s = sum(a, 0, N);
    printf("Sum of array elements: %d", s);
    return 0;
}

int sum(int a[], int start, int len) {
    if(start >= len)
        return 0; 
    return (a[start] + sum(a, start + 1, len));
}