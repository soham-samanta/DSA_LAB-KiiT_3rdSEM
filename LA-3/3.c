#include<stdio.h>

void swap(int *a, int *b);
 
void seg(int arr[], int n){
    int left = 0, right = n-1;
    while (left < right){
        while (arr[left]%2 == 0 && left < right)
            left++;
        while (arr[right]%2 == 1 && left < right)
            right--;
        if (left < right){
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
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
    int i = 0;
    seg(arr, n);
 
    printf("Array after segregation ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    return 0;
}