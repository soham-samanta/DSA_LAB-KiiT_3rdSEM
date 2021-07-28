// SOHAM SAMANTA CODES

#include<stdio.h>

int main(){
    printf("Enetr the number of elements in array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int small,large;
    large=small=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>large){
            large=a[i];
        }
        if(a[i]<small){
            small=a[i];
        }
    }
    printf("\nThe largest element is: %d",large);
    printf("\nThe smallest element is: %d",small);
    return 0;
}