#include <stdio.h>
int main(){
    int n, i, j, temp;
    int arr[64];
 
    printf("Enter number of elements\n");
    scanf("%d", &n);
 
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
            while ( j > 0 && arr[j-1] > arr[j]){	        
                temp     = arr[j];
                arr[j]   = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
    }
    printf("Sorted array: \n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}