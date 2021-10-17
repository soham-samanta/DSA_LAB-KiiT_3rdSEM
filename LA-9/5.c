#include <stdio.h>

#define MAX 10

typedef struct Node
{
    int data;
    struct Node *next, *prev;
} Node;

Node *head = NULL, *left = NULL, *right = NULL;

void input_deque(void);
void output_deque(void);
void insert_left(void);
void insert_right(void);
void delete_left(void);
void delete_right(void);
void display(void);
int main()
{
    int option;

    Node *ele, *prev = NULL;
    int n = MAX - 1;

    while (n != 0)
    {
        ele = (Node *)malloc(sizeof(Node));
        ele->data = -1;
        ele->prev = prev;
        ele->next = NULL;
        if (prev == NULL)
        {
            prev = ele;
            head = ele;
        }
        else
        {
            prev->next = ele;
        }
        prev = ele;
        n--;
    }

    prev->next = head;
    head->prev = prev;

    deque_fx();
    return 0;
}
void deque_fx()
{
    int option;
    do
    {
        printf("\n INPUT RESTRICTED DEQUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Insert at left");
        printf("\n 3.Delete from left");
        printf("\n 4.Delete from right");
        printf("\n 5.Display");
        printf("\n 6.Quit");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            delete_right();
            break;
        case 5:
            display();
            break;
        }
    } while (option != 6);
}
void insert_right()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if ((right != NULL && right->next == left))
    {
        printf("\n OVERFLOW");
        return;
    }
    if (left == NULL) /* if queue is initially empty */
    {
        left = head;
        right = head;
    }
    else
    {
        right = right->next;
    }
    printf("sd\n");
    right->data = val;
}
void insert_left()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if (left->prev == right)
    {
        printf("\n Overflow");
        return;
    }
    if (left == NULL) /*If queue is initially empty*/
    {
        left = head;
        right = head;
    }
    else
    {
        left = left->prev;
    }
    left->data = val;
}
void delete_left()
{
    if (left == NULL)
    {
        printf("\n UNDERFLOW");
        return;
    }
    printf("\n The deleted element is : %d", left->data);
    left->data = -1;
    if (left == right) /*Queue has only one element */
    {
        left = NULL;
        right = NULL;
    }
    else
    {
        left = left->next;
    }
}
void delete_right()
{
    if (left == NULL)
    {
        printf("\n UNDERFLOW");
        return;
    }
    printf("\n The element deleted is : %d", right->data);
    right->data = -1;
    if (left == right) /*queue has only one element*/
    {
        left = NULL;
        right = NULL;
    }
    else
    {
        right = right->prev;
    }
}
void display()
{

    if (left == NULL)
    {
        printf("\n QUEUE IS EMPTY");
        return;
    }
    printf("\n The elements of the queue are : ");

    Node *curr = left;
    while (curr != right)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("%d \n", right->data);
}