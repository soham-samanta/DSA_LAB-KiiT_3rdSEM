#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * prev;
    struct node * next;
}*stnode, *ennode;
 

void create(int n);
void atHead(int num);
void disp(int a);

int main(){
    int n,num1,a;
    stnode = NULL;
    ennode = NULL;

    printf("Input the number of nodes : ");
    scanf("%d", &n);
    create(n); 
    a=1;
    disp(a);
    // printf("\nInput data for the first node : ");
    scanf("%d", &num1);
    atHead(num1);
    a=2;
    disp(a);
    return 0;
}
 
void create(int n){
    int i, num;
    struct node *fnNode;
 
    if(n >= 1){
        stnode = (struct node *)malloc(sizeof(struct node));
        if(stnode != NULL){
            printf("Input data  : "); 
            scanf("%d", &num);
            stnode->num = num;
            stnode->prev = NULL;
            stnode->next = NULL;
            ennode = stnode;
            for(i=2; i<=n; i++){
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL){
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->prev = ennode;    
                    fnNode->next = NULL;
 
                    ennode->next = fnNode;   
                    ennode = fnNode;           
                }else{
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }else{
            printf(" Memory can not be allocated.");
        }
    }
}

void atHead(int num){
    struct node * newnode;
    if(stnode == NULL){
        printf(" No data found in the list!\n");
    }else{
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->next = stnode; 
        newnode->prev = NULL;   
        stnode->prev = newnode;   
        stnode = newnode;          
    }
}

void disp(int m){
    struct node * tmp;
    // int n = 1;
    if(stnode == NULL){
        printf(" No data found in the List yet.");
    }else{
        tmp = stnode;
        if (m==1){
        printf("\nData entered in the list are :\n");
        }else{
         printf("\nAfter insertion the new list are :\n");   
        }
        while(tmp != NULL){
            printf("%d ", tmp->num);
           
            tmp = tmp->next; 
        }
    }
}
