#include <stdio.h>
#include<stdlib.h>

void heapify(int ** q, int n, int i){
    int * arr = *q;
    int small = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] < arr[small])
        small = l;
 
    if (r < n && arr[r] < arr[small])
        small = r;
 
    if (small != i) {
        int t = arr[small];
        arr[small] = arr[i];
        arr[i] = t;
 
        heapify(q, n, small);
    }
}
 
void buildHeap(int ** arr, int n)
{
    int startIdx = (n / 2) - 1;
 
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int * arr = (int*) malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);
    
    buildHeap(&arr,n);
    for(int i = 0; i < n ; i++) printf("%d ",arr[i]);
    printf("\n");

    return 0;
}