#include <stdio.h>
#define MAX 10
int st1[MAX],st2[MAX];
int top1 = -1,top2=-1;
int pop(int st[], int *top);
void push(int val, int st[], int *top);
void display(int st[], int top);
void reverse();

int main(){
    
    int c, data;
    do
    {
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display\n");
        printf("4. Reverser : \nEnter Choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter data to be inserted : ");
            scanf("%d", &data);
            push(data,st1,&top1);
            break;
        case 2:
            data = pop(st1,&top1);
            printf("Deleted : %d \n", data);
            break;
        case 3:
            display(st1,top1);
            printf("\n");
            break;
        case 4:
            reverse();
            display(st1,top1);
            printf("\n");
        default:
            break;
        }
    } while (c != -1);

    return 0;
}


void push(int val, int st[], int *top)
{
    if (*top == (MAX - 1))
        printf("\nStack overflow");
    else
    {
        (*top)++;
        st[*top] = val;
    }
}
int pop(int st[], int *top)
{
    int val;
    if (*top == -1)
        printf("\nStack underflow");
    else
    {
        val = st[*top];
        (*top)--;
    }
    return val;
}

void display(int st[], int top){    
    for(int i=top;i>=0;i--){
        printf("%d ",st[i]);
    }
    printf("\n");
}

void reverse(){
    if(top1 == -1) 
    return;
    int data = pop(st1,&top1);
    if(top1 == -1){
        push(data,st1,&top1);
    }
    else{
        reverse();
        int popped = 0;
        while(top1 != -1){
            int data = pop(st1,&top1);
            push(data,st2,&top2);
            popped++;
        }
        push(data,st1,&top1);
        while(popped--){
            int data = pop(st2,&top2);
            push(data,st1,&top1);
        }
    }
}