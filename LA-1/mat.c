
// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>

int nonzero(int * A , int N){
    int ctr = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(*(A+N*i + j) != 0) ctr++;
        }
    }
    return ctr;
}


int leadDiag(int * A , int N){
    int sum = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(j > i){
                sum+=*(A+N*i + j);
            }
        }
    }
    return sum;
}

void minDiag(int * A , int N){
    int sum = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if((N-j) <= i){
                printf("%d ",*(A+N*i + j));
            }else{
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}



int prodDiag(int * A , int N){
    int sum = 1;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(i == j) sum*= *(A+N*i + j);
            else if(j == N-i-1) sum *= *(A+N*i + j);
        }
    }
    return sum;
}






int main(){
    int N;
    printf("Enter the value of n: ");
    scanf("%d",&N);

    int * A = (int * ) malloc(N*N*sizeof(int));

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d",(A+N*i + j));
        }
    }
    printf("\nThe nXn square dynamic matrix: \n");
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            
            printf("%d ",*(A+N*i + j));
        }
        printf("\n");
    }
    printf("\nNo. of non-zero elments: %d\n\n",nonzero(A,N));
    printf("sum of the elements above the leading diagonal: %d\n\n",leadDiag(A,N));
    printf("Displaying the elements below the minor diagonal: \n");
    minDiag(A,N);
    printf("Product of diagonal elements: %d\n",prodDiag(A,N));
    return 0; }