#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;    
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* s, int i){
    int arrayInd = s->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }else{
        return s->arr[arrayInd];
    }
}

int stackTop(struct stack* s){
    return s->arr[s->top];
}

int stackBottom(struct stack* s){
    return s->arr[0];
}

 
int main(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");
 
    // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty\n");
    }else{
        printf("The stack is not empty\n");
    }


    push(s, 1);
    push(s, 23);
    push(s, 99);
    push(s, 75);
    push(s, 3);
    push(s, 64);
    push(s, 57);
    push(s, 46);
    push(s, 89);
    push(s, 6); // ---> Pushed 10 values 

    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);  //  ---> Poped 4 values 

    // Printing values from the stack
    for (int i = 1; i <= s->top + 1; i++){
        printf("The value at position %d is %d\n", i, peek(s, i));
    }



    return 0;
}
