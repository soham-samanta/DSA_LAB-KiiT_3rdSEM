#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack* next;
};
 
void initStack(struct stack** s)
{ 
    *s = NULL;
    
}
 
int isEmpty(struct stack* s)
{
    if (s == NULL)
        return 1;
    return 0;
}

void push(struct stack** s, int x)
{
    struct stack* p = (struct stack*)malloc(sizeof(*p));
 
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
 
    p->data = x;
    p->next = *s;
    *s = p;
}

int pop(struct stack** s)
{
    int x;
    struct stack* temp;
 
    x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    free(temp);
 
    return x;
}

int top(struct stack* s) { return (s->data); }

void sortedInsert(struct stack** s, int x)
{
    
    if (isEmpty(*s) || x > top(*s)) {
        push(s, x);
        return;
    }
 
    int temp = pop(s);
    sortedInsert(s, x);
 
    push(s, temp);
}

void sortStack(struct stack** s)
{
    
    if (!isEmpty(*s)) {
        
        int x = pop(s);
 
        sortStack(s);
 
        sortedInsert(s, x);
    }
}
 

void printStack(struct stack* s)
{
    while (s) {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}
 

int main(void)
{
    
    int val, option;
    struct stack* top;
    initStack(&top);
	do {
		printf("\n*MAIN MENU*");
		printf("\n 1. PUSH");
		
		printf("\n 2. DISPLAY");
		printf("\n 3. SORT");
		printf("\n 4. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				printf("\n Enter the number to be pushed in stack :");
				scanf("%d", &val);
				push(&top,val);
				break;
			
			case 2:
				printStack(top);
				break;
			case 3:
			sortStack(&top);
				printf("The stack has been sorted!!\n");
				printStack(top);
				break;
		}
	} while (option != 4);
  return 0;

}