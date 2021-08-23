#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void atHEad(struct Node** head_ref, int data){
	struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
	ptr1->data = data;
	ptr1->next = *head_ref;
	if (*head_ref != NULL) {
		struct Node* temp = *head_ref;
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}else{
		ptr1->next = ptr1; 
    }
	*head_ref = ptr1;
}


void printList(struct Node* head){
	struct Node* temp = head;
	if (head != NULL) {
		do {
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != head);
	}

	printf("\n");
}

void deleteNode(struct Node* head, int key){
	if (head == NULL)
		return;
	struct Node *curr = head, *prev;
	while (curr->data != key)
	{
		if (curr->next == head)
		{
			printf("\nGiven node is not found in the list!!!");
			break;
		}

		prev = curr;
		curr = curr->next;
	}

	if (curr->next == head)
	{
		head = NULL;
		free(curr);
		return;
	}

	if (curr == head){
		prev = head;
		while (prev->next != head)
			prev = prev->next;
		head = curr->next;
		prev->next = head;
		free(curr);
	}

	else if (curr->next == head && curr == head){
		prev->next = head;
		free(curr);
	}else{
		prev->next = curr->next;
		free(curr);
	}
}

int main(){
	struct Node* head = NULL;
	atHEad(&head, 12);
	atHEad(&head, 25);
	atHEad(&head, 70);
	atHEad(&head, 81);
	atHEad(&head, 10);
    atHEad(&head, 28);
    atHEad(&head, 31);

	printf("Created Circular LinkedList: \n");
	printList(head);

    int k;
    printf("\nEnter the value of node to be deleted: ");
    scanf("%d",&k);
	deleteNode(head, k);

	printf("Circular LinkedList After Deletion: \n");
	printList(head);

	return 0;
}
