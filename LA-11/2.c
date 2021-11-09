#include<stdio.h>
#include<stdlib.h>
#define bool int
 
struct Node
{
    char data;
    struct Node *next;
};
 
void push(struct Node** top_ref,int new_data)
{
    
    struct Node* newnode =
        (struct Node*) malloc(sizeof(struct Node));
 
    if (newnode == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
 
    newnode->data = new_data;
    newnode->next = (*top_ref);
    (*top_ref) = newnode;
}
 

int pop(struct Node** top_ref)
{
    char res;
    struct Node *top;
 
   
    if (*top_ref == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
bool isEmpty(struct Node* top) {
    if (top == NULL)
		return 1;
	else
		return 0;
}

void printstack(struct Node* top) {
    printf("\n");
    while (top != NULL)
    {
        printf(" %d ", top->data);
        top = top->next;
    }
}
 

void insertAtBottom(struct Node** top_ref,int item) {
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else
    {
 
       
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
 
        push(top_ref, temp);
    }
}

void reversestack(struct Node** top_ref) {
    if (!isEmpty(*top_ref))
    {
        
        int temp = pop(top_ref);
        reversestack(top_ref);
        insertAtBottom(top_ref, temp);
    }
}
 

int main()
{
    int val, option;
    struct Node *temp = NULL;
    
    do {
		printf("\n*MAIN MENU*");
		printf("\n 1. PUSH");
		
		printf("\n 2. DISPLAY");
		printf("\n 3. REVERSE");
		printf("\n 4. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				printf("\n Enter the number to be pushed in stack :");
				scanf("%d", &val);
				push(&temp,val);
				break;
			
			case 2:
				printstack(temp);
				break;
			case 3:
			reversestack(&temp);
				printf("The stack has been reversed!!\n");
				printstack(temp);
				break;
		}
	} while (option != 4);
  return 0;

}