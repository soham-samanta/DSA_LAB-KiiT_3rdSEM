#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
} Node;

void CreateSLL(Node * & head, Node * & end){
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
   
}

void Display(Node * head){
    Node * curr = head;
   
    while(curr != NULL){        
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void DisplayCLL(Node * head){
    Node * curr = head;
   
    while(curr->next != head){        
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("%d ",curr->data);
   
    printf("\n");
}

int main(){
    Node * head=NULL, * end=NULL;    
    CreateSLL(head,end);
    Display(head);
    if(end != NULL){
        end->next = head;
    }
    printf("After Coverting: \n");
    DisplayCLL(head);
    return 0;
}