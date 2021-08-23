#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void rotate(struct Node** head_ref, int k){
	if (k == 0)
		return;
	struct Node* current = *head_ref;
	int count = 1;
	while (count < k && current != NULL) {
		current = current->next;
		count++;
	}
	if (current == NULL)
		return;
	struct Node* kthNode = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head_ref;
	*head_ref = kthNode->next;
	kthNode->next = NULL;
}
void atHEad(struct Node** head_ref, int new_data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node* node){
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main(){
	struct Node* head = NULL;
	for (int i = 60; i > 0; i -= 10)
		atHEad(&head, i);

	printf("Given linked list \n");
	printList(head);
    int k;
    printf("\nEnter the value of k: ");
    scanf("%d",&k);
	rotate(&head, k);

	printf("\nRotated Linked list \n");
	printList(head);

	return 0;
}
