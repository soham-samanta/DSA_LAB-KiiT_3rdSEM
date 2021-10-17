#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *head = NULL, *front = NULL, *rear = NULL;

void insert(void);
int delete (void);
int peek(void);
void display(void);

void main()
{
  int val, option;

  do
  {
    printf("\n***MAIN MENU*");
    printf("\n 1. Insert an element");
    printf("\n 2. Delete an element");
    printf("\n 3. PEEK");
    printf("\n 4. Display the queue");
    printf("\n 5. EXIT");
    printf("\n Enter your option");
    scanf("%d", &option);

    switch (option)
    {

    case 1:

      insert();
      break;

    case 2:

      val = delete ();

      if (val != -1)
        printf("\n The deleted element from queue is : %d", val);
      break;

    case 3:

      val = peek();

      if (val != -1)
        printf("\n The first value in queue is : %d", val);
      break;

    case 4:

      display();
      break;
    }

  } while (option != 5);
}

void insert()
{

  int num;
  printf("\n Enter the number to be inserted in queue :");
  scanf("%d", &num);
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = num;
  n->next = NULL;

  if (front == NULL && rear == NULL)
  {
    front = rear = n;
  }

  else
  {
    rear->next = n;
    rear = n;
  }
}

int delete ()
{

  int val;
  if (front == NULL)
  {
    printf("\nQueue underflow");
    return -1;
  }

  else
  {

    val = front->data;
    front = front->next;
    return val;
  }
}

int peek()
{

  if (front == NULL)
  {
    printf("\nQueue is empty");
    return -1;
  }
  else

    return (front->data);
}

void display()
{
  int i;
  if (front == NULL || rear == NULL)
  {
    printf("\nQueue is empty");
  }

  else
  {
    for (Node *curr = front; curr != rear->next; curr = curr->next)
      printf("\t%d", curr->data);
  }
}