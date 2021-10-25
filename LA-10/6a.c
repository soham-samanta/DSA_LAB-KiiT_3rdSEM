#include <stdio.h>
#define MAX 10
int st[MAX];
int top = -1;
int pop();
void push(int c);
void display();
int peeklowest();

int main(){
    
    int c, data;
    do
    {
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display\n");
        printf("4. Peek Lowest\nEnter Choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter data to be inserted : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Deleted : %d \n", data);
            break;
        case 3:
            display();
            printf("\n");
        case 4:
            data = peeklowest();
            printf("Lowest : %d\n",data);
        default:
            break;
        }
    } while (c != -1);

    return 0;
}


void push(int val)
{
    if (top == (MAX - 1))
        printf("\nStack overflow");
    else
    {
        top++;
        st[top] = val;
    }
}
int pop()
{
    int val;
    if (top == -1)
        printf("\nStack underflow");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}

void display(){    
    for(int i=top;i>=0;i--){
        printf("%d ",st[i]);
    }
    printf("\n");
}

int peeklowest(){
    if(top == -1) return -1;
    int data = pop();
    if(top == -1){
        push(data);
        return data;
    }
    else{
        int last = peeklowest();
        push(data);
        return last;    
    }    
}