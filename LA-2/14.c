// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

struct test{
    int value;
};

struct test * get_struct_array(int N){
    struct test * ans = (struct test *) malloc(sizeof(struct test));
    printf("Enter value: \n");
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&ans[i].value);
    return ans;
}

int main(){
    int N;
    printf("Enter no. of element : ");
    scanf("%d",&N);
    struct test * arr = get_struct_array(N);
    printf("Array Struct values : \n");
    for(int i = 0 ; i < N ; i++){
        printf("%d\n",arr[i].value);
    }
    
    return 0;
}