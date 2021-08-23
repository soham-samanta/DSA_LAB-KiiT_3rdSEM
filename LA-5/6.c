#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * nextptr;
}*stnode;

void create(int n);
void atHead(int num);
void disp(int a);

int main(){
    int n,num1,a;
    stnode = NULL; 	
    printf("Input the number of nodes : ");
    scanf("%d", &n);
    create(n); 
    a=1;
    disp(a);
	printf("\nInput data to be inserted at the beginning : ");
    scanf("%d", &num1);
    atHead(num1);
    a=2;
    disp(a);	

    return 0;
}

void create(int n){
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1){
        stnode = (struct node *)malloc(sizeof(struct node));

        printf(" Input data for node in circular LinkedList: ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->nextptr = NULL;
        preptr = stnode;
        for(i=2; i<=n; i++){
            newnode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &num);
            newnode->num = num;
            newnode->nextptr = NULL;
            preptr->nextptr = newnode;	
            preptr = newnode;   		
        }
        preptr->nextptr = stnode; 	
    }
}

void atHead(int num){
    struct node *newnode, *curNode;
    if(stnode == NULL){
        printf(" No data found in the List yet.");
    }else{
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = stnode;
        curNode = stnode;
        while(curNode->nextptr != stnode)
        {
            curNode = curNode->nextptr;
        }
        curNode->nextptr = newnode;
        stnode = newnode;
    }
}
void disp(int m){
    struct node *tmp;
    int n = 1;

    if(stnode == NULL){
        printf(" No data found in the List yet.");
    }else{
        tmp = stnode;
        if (m==1){
        printf("\nData entered in the circular LinkedList:\n");
        }else{
         printf("\nAfter insertion the new circular Linkedlist:\n");   
        }        
        do{
            printf("%d ", tmp->num);
            tmp = tmp->nextptr;
            n++;
        }while(tmp != stnode);
    }
}
