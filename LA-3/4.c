#include <stdio.h>

void nextGreatest(int arr[], int size){
int max_from_right = arr[size-1];

arr[size-1] = -1;

for(int i = size-2; i >= 0; i--){
	int temp = arr[i];
	arr[i] = max_from_right;
	if(max_from_right < temp)
	max_from_right = temp;
    }
}

void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    printf("Enter the no. of element: ");
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    nextGreatest (arr, size);
    printf ("The modified array is: \n");
    printArray (arr, size);
    return (0);
}
