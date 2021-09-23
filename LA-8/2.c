#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int data;
    struct node * next;
};
 
struct node* top = NULL;

void disp(struct node *top){
    struct node*temp=top;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    printf("\n");
}
 
int isEmpty(struct node* top){
    if (top==NULL){
        return 1;
    }else{
        return 0;
    }
}
 
int isFull(struct node* top){
    struct node* n = (struct node*)malloc(sizeof(struct node)); // we tried to req a new node from heap (if it's NULL means memory full)
    if(n==NULL){
        return 1;
    }else{
        return 0;
    }
}
 
struct node* push(struct node* top, int val){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }else{
        struct node* n = (struct node*) malloc(sizeof(struct node));
        n->data = val;

        n->next = top;
        top = n;
        
        return top;
    }
}
 
int pop(struct node* tp){ 
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }else{
        struct node* n = tp;
        top = tp->next;
        int val = n->data;
        free(n);
        
        return val; 
    }
}
 
int peek(int pos){
    struct node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }else{
        return -1;
    }
}
 
int main(){
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);
    top = push(top, 55);
    
    disp(top);

    pop(top);
    disp(top);

    // for (int i = 1; i <= 4; i++){
    //     printf("Value at position %d is : %d\n", i, peek(i));
    // }


    return 0;
}
