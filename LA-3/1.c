#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
 
int minDist(int arr[], int n, int x, int y){
    int i, j;
    int min = INT_MAX;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((x == arr[i] && y == arr[j] || y == arr[i] && x == arr[j]) && min > abs(i - j)){
                min = abs(i - j);
            }
        }
    }
    if (min > n)
        return -1;
    return min;
}

int main(){
    int arr[] = { 3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int y = 6;
    printf("Minimum distance between %d and %d is %d\n", x,y, minDist(arr, n, x, y));
    return 0;
}