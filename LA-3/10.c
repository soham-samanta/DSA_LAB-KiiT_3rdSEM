#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int main(){
    int m,n;
    printf("Enter the size of m and n: ");
    scanf("%d%d",&m,&n);
    int **a=(int**)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        a[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m/2;i++){
        int r1=i,r2=m-i-1;
        for(int j=0;j<n;j++){
            int t=a[r1][j];
            a[r1][j]=a[r2][j];
            a[r2][j]=t;
        }
    }
    printf("After Swapping as per question: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}