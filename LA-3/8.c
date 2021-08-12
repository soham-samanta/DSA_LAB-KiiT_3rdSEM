#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *a =(int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int l=a[0],ctr=1;
    for(int i=0;i<n;i++){
        if(a[i]==l)
        ctr++;
        if(a[i]>l){
            l=a[i];
            ctr=1;
        }
    }
    printf("Largest Element: %d\nOccurence: %d\n",l,ctr);
    return 0;
}