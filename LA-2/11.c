// SOHAM SAMANTA CODES
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

struct Emp{
    char name[100];
    char gender[10];
    char designation[100];
    char department[100];
    int basic_pay;
}; 

int main(){    
    int N ;
    printf("Enter the number of employees : \n");
    scanf("%d",&N);

    struct Emp * Employees  = (struct Emp * ) malloc(N * sizeof(struct Emp));

    for(int i = 0 ; i < N ; i++){
        printf("Enter Name : \n");
        scanf("%s",&Employees[i].name);        
        printf("Enter gender : \n");
        scanf("%s",&Employees[i].gender);
        printf("Enter designation : \n");
        scanf("%s",&Employees[i].designation);
        printf("Enter department : \n");
        scanf("%s",&Employees[i].department);
        printf("Enter basic pay : \n");        
        scanf("%d",&Employees[i].basic_pay);
    }

    for(int i = 0 ; i < N ; i++){
        int bp = Employees[i].basic_pay;
        float gp = bp + 0.25*bp + 0.75*bp;

        printf("Employee Name : %s\n",Employees[i].name);
        printf("Employee Gender : %s\n",Employees[i].gender);
        printf("Employee Designation : %s\n",Employees[i].designation);
        printf("Employee Department : %s\n",Employees[i].department);
        printf("Employee Basic Pay : %d\n",Employees[i].basic_pay);
        printf("Gross Pay = %f\n", gp);
        printf("\n");
    }

    return 0;
}