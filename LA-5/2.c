#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node *kAltReverse(struct Node *head, int k){
	struct Node* current = head;
	struct Node* next;
	struct Node* prev = NULL;
	int count = 0;

	while (current != NULL && count < k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
	}

	if(head != NULL)
	head->next = current;

	count = 0;
	while(count < k-1 && current != NULL ){
        current = current->next;
        count++;
	}

	if(current != NULL)
	current->next = kAltReverse(current->next, k);

	return prev;
}

void atHEad(struct Node** head_ref, int new_data){
	struct Node* new_node =  (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);	
	(*head_ref) = new_node;
}


void printList(struct Node *node){
	int count = 0;
	while(node != NULL){
        printf("%d ",node->data);
		node = node->next;
		count++;
	}
}

int main(){
	struct Node* head = NULL;
	for(int i = 12; i > 0; i--){
	    atHEad(&head, i);
    }

    printf("Given linked list \n");
	printList(head);
    int k;
    printf("\nEnter the value of k: ");
    scanf("%d",&k);
	head = kAltReverse(head, k);

    printf("\n Modified Linked list \n");
	printList(head);
	return 0;
}

