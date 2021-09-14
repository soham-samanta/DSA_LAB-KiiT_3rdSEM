#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
} Node;

void CreateDLL(Node * & head1, Node * & head2 , Node * & end1, Node * & end2){
    Node * n1, * n2, * prev1 = NULL, *prev2 = NULL;
    int t;
    while((scanf("%d",&t)) && t != -1){
        n1 = (Node *) malloc(sizeof(Node));
        n2 = (Node *) malloc(sizeof(Node));
        n1->data = n2->data = t;
        n1->next = NULL;
        n2->next = NULL;
        if(head1 == NULL) head1 = n1;
        if(head2 == NULL) head2 = n2;

        if(prev1 != NULL){
            prev1->next = n1;
        }
        n2->next = prev2;
        prev2 = n2;
        prev1 = n1;
    }
    end1 = n1;
    end2  = head2;
    head2 = n2;
}

void Display(Node * head){
    Node * curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    Node * head1 =NULL, * head2 =NULL , * end1 =NULL , * end2 =NULL;
    CreateDLL(head1,head2,end1,end2);
    printf("Implementing Double LL from Single LL: \n");
    Display(head1);
    Display(head2);

    return 0;
}