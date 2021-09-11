#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    int expox, expoy;
    struct Node * next;
} Node;

void CreateSLL(Node *  head, Node *  end){
    Node * ele, * prev = NULL;    
    int t1, t2=0, t3 = 0;
    printf("Enter maximum exponent of x : ");
    scanf("%d",&t2);
    printf("Enter maximum exponent of y : ");
    scanf("%d",&t3);

    for(int i = 0 ; i <= t2 ; i++){
        for(int j = 0 ; j <= t3 ; j++){
            ele = (Node *) malloc(sizeof(Node));
            printf("Enter value of x^%dy^%d : ", i , j);
            scanf("%d",&t1);
            ele->value = t1;
            ele->expox = t1;
            ele->expoy = t2;
            if(head == NULL){
                head = ele;
            }

            if(prev != NULL){
                prev->next = ele;
            }
            prev = ele;
        }
    }

    end = ele;
}

void disp(Node * head){
    Node * curr = head;
    while(curr != NULL){
        printf("%d",curr->value);
        if(curr->expox != 0){
            printf("x^%d",curr->expox);
        }
        if(curr->expoy != 0){
            printf("y^%d",curr->expoy);
        }
        printf(" +");
        curr = curr->next;
    }
    printf("\n") ;
}

Node * AddLL(Node * head1, Node * head2){
    Node * head = NULL, *curr, *curr1 = head1 , *curr2 = head2, *prev = NULL; 
    while(curr1 != NULL && curr2 != NULL){
        curr = (Node*) malloc(sizeof(Node));
        curr->value = curr1->value + curr2->value;
        curr->expox = curr1->expox;
        curr->expoy = curr1->expoy;
        if(head == NULL){
            head = curr;
        }
        if(prev != NULL){
            prev->next = curr;
        }
        prev = curr;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    while(curr1 != NULL){
        curr = (Node*) malloc(sizeof(Node));
        curr->value = curr1->value;
        curr->expox = curr1->expox;
        curr->expoy = curr1->expoy;
        if(head == NULL){
            head = curr;
        }
        if(prev != NULL){
            prev->next = curr;
        }
        prev = curr;
        curr1 = curr1->next;
    }
    while(curr2 != NULL){
        curr = (Node*) malloc(sizeof(Node));
        curr->value = curr2->value;
        curr->expox = curr2->expox;
        curr->expoy = curr2->expoy;
        if(head == NULL){
            head = curr;
        }
        if(prev != NULL){
            prev->next = curr;
        }
        prev = curr;
        curr2 = curr2->next;
    }

    return head;
}


int main(){
    Node * head1 =NULL, * head2 = NULL , * end1, * end2, *ans;    
    CreateSLL(head1,end1);
    printf("First Polynomial : ");
    disp(head1);
    CreateSLL(head2,end2);
    printf("Second Polynomial : ");
    disp(head2);
    printf("Sum of both Polys : ");
    ans = AddLL(head1,head2);
    disp(ans);
}