#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct snode{
	struct node *t;
	struct snode *next;
};

void push(struct snode **s, struct node *k){
	struct snode *tmp = (struct snode *) malloc(sizeof(struct snode));

	tmp->t = k;
	tmp->next = *s;
	(*s) = tmp;
}

struct node *pop(struct snode **s){
	struct node *t;
	struct snode *st;
	st=*s;
	(*s) = (*s)->next;
	t = st->t;
	free(st);
	return t;
}

int isEmpty(struct snode *s){
	if (s == NULL )
		return 1;

	return 0;
}

struct node* newNode (int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct node *root){
	if (root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void merge(struct node *root1, struct node *root2){
	struct snode *s1 = NULL;
	struct node *current1 = root1;
	struct snode *s2 = NULL;
	struct node *current2 = root2;
	if (root1 == NULL)
	{
		inorder(root2);
		return;
	}

	if (root2 == NULL)
	{
		inorder(root1);
		return ;
	}
	while (current1 != NULL || !isEmpty(s1) ||current2 != NULL || !isEmpty(s2)){
		if (current1 != NULL || current2 != NULL ){
			if (current1 != NULL)
			{
				push(&s1, current1);
				current1 = current1->left;
			}
			if (current2 != NULL)
			{
				push(&s2, current2);
				current2 = current2->left;
			}

		}else{
			if (isEmpty(s1))
			{
				while (!isEmpty(s2))
				{
					current2 = pop (&s2);
					current2->left = NULL;
					inorder(current2);
				}
				return ;
			}
			if (isEmpty(s2))
			{
				while (!isEmpty(s1))
				{
					current1 = pop (&s1);
					current1->left = NULL;
					inorder(current1);
				}
				return ;
			}

			current1 = pop(&s1);
			current2 = pop(&s2);
			if (current1->data < current2->data)
			{
				printf("%d ", current1->data);
				current1 = current1->right;
				push(&s2, current2);
				current2 = NULL;
			}
			else
			{
				printf("%d ", current2->data);
				current2 = current2->right;
				push(&s1, current1);
				current1 = NULL;
			}
		}
	}
}

int main(){
	struct node *root1 = NULL, *root2 = NULL;

	/* 
		 3
		/ \
	   1   5
	*/
	root1 = newNode(3);
	root1->left = newNode(1);
	root1->right = newNode(5);

	/* 
		 4
		/ \
	   2   6
	*/
	root2 = newNode(4);
	root2->left = newNode(2);
	root2->right = newNode(6);

	merge(root1, root2);

	return 0;
}
