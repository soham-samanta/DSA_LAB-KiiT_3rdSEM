#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a,b)  a>b?a:b

typedef struct Node{
    int row,col,value;    
    struct Node * next;
} Node;

void CreateSLL(Node * & head, Node * & end){
    Node * ele, * prev = NULL;    
    int t1 = 0, t2=0, t3 = -1, rows = INT_MIN , cols = INT_MIN, entries=0;
    while(1){
        scanf("%d%d%d",&t1,&t2,&t3);
        if(t3 == 0) break;
        ele = (Node *) malloc(sizeof(Node));
        ele->row = t1;
        ele->col = t2;
        ele->value = t3;
        ele->next = NULL;

        if(head == NULL){
            head = ele;
        }

        if(prev != NULL){
            prev->next = ele;
        }
        rows = max(rows,t1);
        cols = max(cols,t1);
        entries++;
        prev = ele; 
    }

    end = ele;
    
    ele = (Node *) malloc(sizeof(Node));
    ele->row = max(rows,cols);
    ele->col = max(rows,cols);
    ele->value = entries;
    ele->next = head;
    head = ele;
}

void Display(Node * head){
    Node * curr = head;
    while(curr != NULL){        
        printf("%d %d %d\n",curr->row, curr->col, curr->value); 
        curr = curr->next;
    }
    printf("\n") ;
}

Node * AddLL(Node * head1, Node * head2){
    
    Node * head = NULL, *curr, *curr1 = head1->next , *curr2 = head2->next, *prev = NULL; 
    int entries = 0;
    while(curr1 != NULL && curr2 != NULL){
        
        curr = (Node *) malloc(sizeof(Node));
        if(curr1->row < curr2->row){            
            curr->value = curr1->value;
            curr->row = curr1->row;
            curr->col = curr1->col;
            curr->next = NULL;      
            curr1 = curr1->next;            
        }
        else if(curr2->row < curr1->row){            
            curr->value = curr2->value;
            curr->row = curr2->row;
            curr->col = curr2->col;
            curr->next = NULL;      
            curr2 = curr2->next;
        }
        else if(curr1->row == curr2->row){

            if(curr1->col < curr2->col){
                curr->value = curr1->value;
            curr->row = curr1->row;
            curr->col = curr1->col;
            curr->next = NULL;      
            curr1 = curr1->next;
            }
            else if(curr2->col < curr1->col){
                curr->value = curr2->value;
            curr->row = curr2->row;
            curr->col = curr2->col;
            curr->next = NULL;      
            curr2 = curr2->next;
            }
            else if(curr2->col == curr1->col){
                curr->value = curr1->value + curr2->value;
            curr->row = curr2->row;
            curr->col = curr2->col;
            curr->next = NULL;  
            curr1 = curr1->next;
            curr2 = curr2->next;   
            }
        }   

        if(head == NULL){
            head = curr;
        }

        if(prev != NULL){
            prev->next = curr;
        }

        prev = curr;
        entries++;

    }

    while(curr1 != NULL){
        curr = (Node *) malloc(sizeof(Node));
        curr->value = curr1->value;
        curr->row = curr1->row;
        curr->col = curr1->col;
        curr->next = NULL;

        if(head == NULL){
            head = curr;
        }

        if(prev != NULL){
            prev->next = curr;
        }

        prev = curr;

        curr1 = curr1->next;
        entries++;
        
    }
    
    
    while(curr2 != NULL){
        curr = (Node *) malloc(sizeof(Node));
        curr->value = curr2->value;
        curr->row = curr2->row;
        curr->col = curr2->col;
        curr->next = NULL;

        if(head == NULL){
            head = curr;
        }

        if(prev != NULL){
            prev->next = curr;
        }

        prev = curr;
        
        curr2 = curr2->next; 
        entries++;       
    }

    curr = (Node *) malloc(sizeof(Node));
    curr->row = head1->row;
    curr->row = head2->row;
    curr->value = entries;
    curr->next = head;
    head = curr;

    return head;
}


int main(){
    Node * head1 =NULL, * head2 = NULL , * end1, * end2, *ans;    
    CreateSLL(head1,end1);
    printf("First Polynomial : ");
    Display(head1);
    CreateSLL(head2,end2);
    printf("Second Polynomial : ");
    Display(head2);    
    
    printf("Sum of both Polys : ");
    ans = AddLL(head1,head2);
    Display(ans);
}