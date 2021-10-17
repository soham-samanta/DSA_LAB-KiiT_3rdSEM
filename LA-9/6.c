#include <stdio.h>
#define MAX 10
int st[MAX];
int top = -1;
int pop();
void push(int c);
void display();
int del();

int main()
{
    int c, data;
    do
    {
        printf("1. Insert element at end\n");
        printf("2. Delete element at front\n");
        printf("3. Display Queue\nEnter Choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter data to be inserted : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = del();
            printf("Deleted : %d \n", data);
            break;
        case 3:
            display(top);
            printf("\n");
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

void display(int x)
{
    if (x == -1)
        return;
    else
    {
        int d = x;
        display(d - 1);
        printf("%d ", st[d]);
    }
}

int del()
{
    if (top == -1)
        return -1;

    int data = pop();
    if (top == -1)
    {
        return data;
    }
    else
    {
        int ans = del();
        push(data);
        return ans;
    }
}