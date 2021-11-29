#include <stdio.h>

int main(){
    printf("Enter the number of element to be sorted: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int cnt=0;
    while(cnt<n-1){
        for(int i=0;i<n-cnt-1;i++){
            if(arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            }
        }
        cnt++;
    }
    printf("Sorted Array is: \n");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    return 0;
}