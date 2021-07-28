// SOHAM SAMANTA CODES
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the no. of element: ");
    scanf("%d",&n);
    int *a,*b;
    a=(int*)malloc(n*sizeof(int));
    b=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        b[i]=-1;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                b[i]=a[j];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\t-\t%d\n",a[i],b[i]);
    }

    return 0;
}