#include <stdio.h>

#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

void insert(int);
int delete (void);
int peek(void);
void display(void);
int del();

int main()
{
  int c, data, num;

  do
  {
    printf("1. Insert element at end\n");
    printf("2. Delete element at top\n");
    printf("3. Display Stack\nEnter Choice : ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
      printf("\n Enter the number to be inserted :");
      scanf("%d", &num);
      insert(num);
      break;
    case 2:
      data = del();
      printf("Deleted : %d \n", data);
      break;
    case 3:
      display();
      printf("\n");
    default:
      break;
    }
  } while (c != -1);
  return 0;
}

void insert(int num)
{

  if (rear == (MAX - 1))
    printf("\n Queue overflow");

  else if (front == -1 && rear == -1)
  {
    front = rear = 0;
    queue[rear] = num;
  }

  else
  {
    rear++;
    queue[rear] = num;
  }
}

int delete ()
{

  int val;
  if (front == -1 || front > rear)
  {
    printf("\nQueue underflow");
    return -1;
  }

  else
  {

    val = queue[front];
    front++;

    if (front > rear)
      front = rear = -1;

    return val;
  }
}

int peek()
{

  if (front == -1 || front > rear)
  {
    printf("\nQueue is empty");
    return -1;
  }
  else

    return (queue[front]);
}

void display()
{
  int i;
  if (front == -1 || front > rear)
  {
    printf("\nQueue is empty");
  }

  else
  {
    for (i = rear; i >= front; i--)
      printf("\t%d", queue[i]);
  }
}

int del()
{
  if (front == -1 || front > rear)
    return -1;
  else
  {
    rear--;
    return queue[rear + 1];
  }
}