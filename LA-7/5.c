#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
} Node;

void CreateDLL(Node * & head, Node * & end){
    Node * n, * prev = NULL;
    int t;
    int N;
    printf("Enter no. of Node : ");
    scanf("%d",&N);
    while((N--) != 0 ){
        scanf("%d",&t);
        n = (Node *) malloc(sizeof(Node));
        n->data = t;
        n->next = NULL;
        n->prev = prev;

        if(head == NULL){
            head = n;
        }

        if(prev != NULL){
            prev->next = n;
        }
        prev = n;
    }
    end = n;
}


void Display(Node * head){
    Node * curr = head;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}


void RemDupl(Node * head){
    Node * curr=NULL,* prev = head;
    if(head->next != NULL)
    curr = head->next;

    while(curr != NULL){
        if(curr->data != prev->data){
            prev->next = curr;
            curr->prev = prev;
            prev = curr;            
        }
        curr = curr->next;
    }
    prev->next = curr;
}

int main(){
    Node * head =NULL , * end = NULL;
    CreateDLL(head,end);
    // Display(head);
    RemDupl(head);
    printf("After Removing Duplicates: \n");
    Display(head);
    return 0;
}