#include <stdio.h>
#include <limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int A[100000][2];

void sort_by_st_time(int N){
    for(int i = 0 ; i < N-1 ; i++){
        for(int j = 0 ; j < N - i- 1 ; j++){
            if((A[i][0] > A[i+1][0]) || (A[i][0] == A[i+1][0] && A[i][1] > A[i+1][1]) ){
                int t = A[i][0];
                A[i][0] = A[i+1][0];                
                A[i+1][0] = t;
                t = A[i][1];
                A[i][1] = A[i+1][1];
                A[i+1][1] = t;
            }
        }
    }
}

int main(){
    int N;
    scanf("%d",&N);

    int st,end;    
    for(int i = 0 ; i < N; i++){
        scanf("%d%d",&A[i][0],&A[i][1]);        
    }

    sort_by_st_time(N);

    int l = 1 , r = A[0][0];

    for(int i = 0 ; i < N ; i++){        
        if(A[i][0] >= l && A[i][1] > r){            
            printf("%d-%d\n",l,max(r,A[i][0]));
            l = max(A[i][0],A[i][1]);
            r = l;
        }
        else{
            l = A[i][1];
            r = l;
        }
                        
    }
    
    return 0;
}