#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
} Node;

void CreateCLL(Node * & head, Node * & end){
    Node * n, * prev = NULL;
    int t;
    while((scanf("%d",&t) && t != -1 )){
        n = (Node *) malloc(sizeof(Node));
        n->data = t;
        n->next = NULL;

        if(head == NULL){
            head = n;
        }

        if(prev != NULL){
            prev->next = n;
        }

        prev = n;
    }

    end = n;
    end->next = head;
   
}

void Display(Node * head){
    Node * curr = head;
   
    while(curr->next != head){        
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("%d ",curr->data);
   
    printf("\n");
}


int main(){
    Node * head = NULL, * end = NULL;

    CreateCLL(head,end);
    Display(head);
}