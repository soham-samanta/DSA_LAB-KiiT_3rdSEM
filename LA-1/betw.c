// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
int main(){
    int N;        
    printf("Enter the number of Elements : \n");
    scanf("%d",&N);
    int * A = (int*)malloc(N*sizeof(int));
    for(int i = 0 ; i < N;i++){
        scanf("%d",&A[i]); 
    }
    int a,b,l=-1,r=-1;
    printf("Enter the range(value of a and b): \n");
    scanf("%d%d",&a,&b);

    for (int i = 0; i < N-1; i++){
        for(int j =  0 ; j < N-i-1; j++){
            if(A[j] > A[j+1]){
                int t = A[j];
                A[j] = A[j+1];
                A[j+1] = t;
            }
        }
    }
    for(int i = 0 ; i < N ; i++){
        if(A[i] == a){
            if(l == -1)
            l = i+1;
        }
        if(A[i] == b){
            if(r == -1)
            r = i+1;
        }        
    }
    printf("displaying the elements between a and b: \n");
    for(int i=l-1;i<=r-1;i++){
        printf("%d",A[i]);
    }

    // if(l == -1 || r == -1) 
    // printf("\nINVALID, Please enter correct range!");
    // else 
    // printf("\nNumber of elements between %d and %d is:  %d ",a,b,(abs(l-r)+1));
    
    printf("\n");
    

    return 0;
}