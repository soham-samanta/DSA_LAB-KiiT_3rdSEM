#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

void modify(int arr[], int n){
    if (n <= 1)
      return;
    int prev = arr[0];
    arr[0] = arr[0] * arr[1];
    for (int i=1; i<n-1; i++){
        int curr = arr[i];
        arr[i] = prev * arr[i+1];
        prev = curr;
    }
    arr[n-1] = prev * arr[n-1];
}

int main(){
    printf("Enter the no. of element: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    modify(arr, n);
    for (int i=0; i<n; i++)
    printf("%d ",arr[i]);
    return 0;
}