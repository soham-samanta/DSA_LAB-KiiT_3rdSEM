#include<stdio.h>
#include<stdlib.h>

void bubmod(int ** arr, int n){
    for(int i = 0 ; i < n-1; i++){
        int swapped = 0;
        for(int j = 0 ; j < n-i-1; j++){
            if((*arr)[j] > (*arr)[j+1]){
                int t = (*arr)[j];
                (*arr)[j] = (*arr)[j+1];
                (*arr)[j+1] =  t;
                swapped = 1;
            }
        }
        if(!swapped)
        return;
    }    
}

int main(){
    int n;
    scanf("%d",&n);
    int * arr = (int*) malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++) 
    scanf("%d",&arr[i]);

    bubmod(&arr,n);
    for(int i = 0 ; i < n ; i++) 
    printf("%d ",arr[i]);
    printf("\n");
    return 0;
}