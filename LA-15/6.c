#include<stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>

#define max(a,b) (a> b ? a : b)

void heapify(int ** ax, int n, int i)
{
    int * arr = *ax;
    int large = i;
    int left_node = 2 * i + 1;
    int right_node = 2 * i + 2;
 
    if (left_node < n && arr[left_node] > arr[large])
        large = left_node;
 
    if (right_node < n && arr[right_node] > arr[large])
        large = right_node;
 
    if (large != i) {
        int t = arr[large];
        arr[large] = arr[i];
        arr[i] = t;
 
        heapify(ax, n, large);
    }
}
 
void buildHeap(int ** arr, int n)
{
    int mid = (n / 2) - 1;
 
    for (int i = mid; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int KLarge(int **ax, int n, int k){      
    
    int * arr = *ax;
    int m = arr[0];    
    
    arr[0] = 0;
    if(k <= 1){
        return m;
    }
    else{
        buildHeap(&arr,n);    
        return KLarge(&arr,n,k-1);
    }
}


int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int * arr = (int*) malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++) 
    scanf("%d",&arr[i]);
    
    buildHeap(&arr,n);
    for(int i = 0; i < n ; i++)
    printf("%d ",arr[i]);
    printf("\n");

    
    printf("Kth Largest : %d\n",KLarge(&arr,n,k));
    
    
    return 0;
}