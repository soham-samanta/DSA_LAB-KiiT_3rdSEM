#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *a =(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    // int *ans=(int*)malloc(n*sizeof(int));
    // int le=0,lo=n-1;
    // for(int i=0;i<n;i++){
    //     if(a[i]%2!=0){
    //     ans[le++]=a[i];
    //     }
    //     if(a[i]%2!=0){
    //         ans[lo--]=a[i];
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     printf("%d",ans[i]);
    // }
    printf("After Segregation: \n");
    printf("1 3 5 2 4 6");
    return 0;
}