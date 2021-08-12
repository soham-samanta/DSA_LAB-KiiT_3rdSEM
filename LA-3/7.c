#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

// void fun(int *&a,int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             int t=a[j];
//             a[j]=a[j+1];
//             a[j+1]=t;
//         }
//     }
// }

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *a =(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the value of k: ");
    int k;
    scanf("%d",&k);
    // fun(a,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            int t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    }
    printf("Kth smallest: %d\nKth Largest: %d\n",a[k-1],a[n-k]);

    return 0;
}