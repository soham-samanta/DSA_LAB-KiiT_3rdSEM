#include<stdio.h>
#define MAX 10
int st[MAX];
int top=-1;
int pop(int st[]);
void push(int st[],int c);
void display(int st[]);

int main()
{

    int ch = 0,x;
    while(ch != -1){
        printf("Choices : \n1:Check if Empty\n2:Push\n3:Pop\n4:Display\n5:Sort\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            if(top == -1){
                printf("The Stack is Empty \n");
            }
            else{
                printf("The Stack is not Empty \n");
            }
            break;
        
        case 2:
            printf("Enter data to be pushed : ");
            scanf("%d",&x);
            push(st,x);
            break;
        
        case 3:
            printf("Popping Data : ");
            x = pop(st);
            printf("popped : %d\n",x);\
            break;
        
        case 4 :
            printf("Stack Data : \n");
            display(st);
            break;
        
        case 5:
            sort();
            printf("Sorted : \n");
            display(st);
        
        default:
            break;
        }
    }

    return  0;
}

void push(int st[],int val)
{
if(top==(MAX-1))
printf("\nStack overflow");
else
{
top++;
st[top]=val;
}
}
int pop(int st[])
{
int val;
if(top==-1)
printf("\nStack underflow");
else
{ 
val=st[top];
top--;
}
return val;
}

void display(int st[]){
    int x = top;
    while(x != -1){
        
        printf("%d\n",st[x]);
        x--;
    }
}

int ttop = -1;
int temp[MAX];

void tpush(int val)
{
if(ttop==(MAX-1))
printf("\nStack overflow");
else
{
ttop++;
temp[ttop]=val;
}
}

int tpop()
{
int val;
if(ttop==-1)
printf("\nStack underflow");
else
{
val=temp[ttop];
ttop--;
}
return val;
}



void sort(){    
    while (!(top == -1))
    {
        int tmp = pop(st);
        while (!(ttop == -1))
        {
            if(temp[ttop] < tmp)break;

            push(st,temp[ttop]);            
            tpop();
        }
        tpush(tmp);        
    }
    while(ttop != -1){
        int x = tpop();
        push(st,x);
    }
}