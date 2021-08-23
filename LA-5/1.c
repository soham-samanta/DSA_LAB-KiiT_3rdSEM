#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void atHEad(struct Node** head_ref, int new_data){
	struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node* node){
	while (node != NULL) {
        printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
}

int countNodes(struct Node* s){
	int count = 0;
	while (s != NULL) {
		count++;
		s = s->next;
	}
	return count;
}

void swapKth(struct Node** head_ref, int k){
	int n = countNodes(*head_ref);
	if (n < k)
		return;
	if (2 * k - 1 == n)
		return;

	struct Node* x = *head_ref;
	struct Node* x_prev = NULL;
	for (int i = 1; i < k; i++) {
		x_prev = x;
		x = x->next;
	}

	struct Node* y = *head_ref;
	struct Node* y_prev = NULL;
	for (int i = 1; i < n - k + 1; i++) {
		y_prev = y;
		y = y->next;
	}

	if (x_prev)
		x_prev->next = y;
	if (y_prev)
		y_prev->next = x;
	struct Node* temp = x->next;
	x->next = y->next;
	y->next = temp;
	if (k == 1)
		*head_ref = y;
	if (k == n)
		*head_ref = x;
}

int main(){
	struct Node* head = NULL;
	for (int i = 8; i >= 1; i--)
		atHEad(&head, i);
    printf("Original LinkedList: ");
	printList(head);

    int k;
    printf("\nEnter the value of k: ");
    scanf("%d",&k);
		swapKth(&head, k);
        printf("\nModified List for k = %d\n",k);
		printList(head);

	return 0;
}
