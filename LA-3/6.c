#include <stdio.h>
 
void main(){
    static int array1[10][10], array2[10][10];
    int i, j, k, a, m, n;
 
    printf("Enter the order of the matrix \n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the matrix \n");
    for (i = 0; i < m; ++i){
        for (j = 0; j < n; ++j){
            scanf("%d", &array1[i][j]);
            array2[i][j] = array1[i][j];
        }
    }
    printf("The given matrix is \n");
    for (i = 0; i < m; ++i){
        for (j = 0; j < n; ++j){
                printf(" %d", array1[i][j]);
        }
        printf("\n");
    }
    printf("After arranging rows in ascending order\n");
    for (i = 0; i < m; ++i){
        for (j = 0; j < n; ++j){
            for (k =(j + 1); k < n; ++k){
                if (array1[i][j] > array1[i][k]){
                    a = array1[i][j];
                    array1[i][j] = array1[i][k];
                    array1[i][k] = a;
                }
            }
        }
    }
    for (i = 0; i < m; ++i){
        for (j = 0; j < n; ++j){
            printf(" %d", array1[i][j]);
        }
        printf("\n");
    }
    printf("After arranging the columns in descending order \n");
    for (j = 0; j < n; ++j){
        for (i = 0; i < m; ++i){
            for (k = i + 1; k < m; ++k){
                if (array2[i][j] < array2[k][j]){
                    a = array2[i][j];
                    array2[i][j] = array2[k][j];
                    array2[k][j] = a;
                }
            }
        }
    }
    for (i = 0; i < m; ++i){
        for (j = 0; j < n; ++j){
            printf(" %d", array2[i][j]);
        }
        printf("\n");
    }
}