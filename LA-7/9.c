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
    while((scanf("%d",&t)) && t != -1){
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

void RotateKTime(int K, Node * & head, Node * & end){
    Node * st = head, *t1 , * en = end;
    for(int i = 0 ; i < K ; i++){
        if(st != NULL &&  en != NULL){
            en->next = st;
            en = st;
            head = st->next;
            end = en;
            t1 = st->next;
            st->next = NULL;
            st = t1;
        }
    }
}


int main(){
    Node * head =NULL , * end = NULL;
    printf("Enter all the nodes of Double linkedList \nPress -1 to terminate:\n");
    CreateDLL(head,end);
    Display(head);
    int K;
    printf("Enter the kth element: ");
    scanf("%d",&K);
    RotateKTime(K,head,end);
    printf("After rotating the Double LL counter-clockwise by k nodes: \n");
    Display(head);
    return 0;
}