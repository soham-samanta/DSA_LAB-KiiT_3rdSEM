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


void MiddleEle(Node * head){
    int N = 0,pos;
    Node * curr = head,*prev;
    while(curr != NULL){
        N++;
        prev = curr;
        curr = curr->next;
    }
    pos = N;
    while(prev != NULL){
        if(pos == N/2){
            printf("Middle Ele : %d\n",prev->data);
            break;
        }
        pos--;
        prev=prev->prev;
    }
}


int main(){
    Node * head =NULL , * end = NULL;
    CreateDLL(head,end);
    printf("Displaying Double LL: \n");
    Display(head);
    printf("Middle of a Double LL: \n");
    MiddleEle(head);
    return 0;
}