// SOHAM SAMANTA CODES
#include<stdio.h>
#include<stdlib.h>

int main(){
      int *p,n;
      printf("Enter the No. of elements in array: ");
      scanf("%d",&n);
      p=(int*)malloc(n * sizeof(int));
      printf("Enter %d Numbers: \n",n);
      for(int i=0;i<n;i++){
            scanf("%d",p+i);
      }
      printf("Reverse Order is: \n");
      for(int i=n-1;i>=0;i--){
            printf("%d ",*(p+i));
      }
      return 0;
}