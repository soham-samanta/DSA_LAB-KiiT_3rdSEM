// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

struct Dist{
    int value;
} d1,d2;

struct Dist * add_dist(struct Dist dis1 , struct Dist dis2){
    struct Dist * ans = (struct Dist * ) malloc(sizeof(struct Dist));
    dis1.value = dis1.value * 1000;
    ans->value = dis1.value + dis2.value;
    return ans;
}

int main(){
    printf("Enter a distance in km : \n");
    scanf("%d",&d1.value);
 
    printf("Enter a distance in meter : \n");
    scanf("%d",&d2.value);
 
    

    printf("Sum of both in meters : %d\n",add_dist(d1,d2)->value);

    return 0;
}